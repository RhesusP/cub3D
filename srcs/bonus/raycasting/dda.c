/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:49:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:41:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

static t_dda_vars	get_ver_utils(t_dda_vars var, t_map_info *map, int right)
{
	double	slope;

	slope = var.angle_sin / var.angle_cos;
	if (right)
		var.delta_x = 1;
	else
		var.delta_x = -1;
	var.delta_y = var.delta_x * slope;
	if (right)
		var.x = ceil(map->player.map_pos.x);
	else
		var.x = floor(map->player.map_pos.x);
	var.y = map->player.map_pos.y + (var.x - map->player.map_pos.x) * slope;
	return (var);
}

static t_dda_vars	get_hor_utils(t_dda_vars var, t_map_info *map, int up)
{
	double	slope;

	slope = var.angle_cos / var.angle_sin;
	if (up)
		var.delta_y = -1;
	else
		var.delta_y = 1;
	var.delta_x = var.delta_y * slope;
	if (up)
		var.y = floor(map->player.map_pos.y);
	else
		var.y = ceil(map->player.map_pos.y);
	var.x = map->player.map_pos.x + (var.y - map->player.map_pos.y) * slope;
	return (var);
}

static void	ver_dda(t_dda_vars u, t_map_info *map, t_frame *f, double angle)
{
	int		right;
	double	wall_x;
	double	wall_y;

	right = (angle > PI_3_2 || angle < M_PI_2);
	u = get_ver_utils(u, map, right);
	while (coords_within_boundaries(map, u.x, u.y))
	{
		if (right)
			wall_x = floor(u.x);
		else
			wall_x = floor(u.x - 1); 
		wall_y = floor(u.y);
		if (is_wall(map, wall_x, wall_y))
		{
			fill_frm_ver(f, map, u, right);
			break ;
		}
		u.x += u.delta_x;
		u.y += u.delta_y;
	}
}

static void	hor_dda(t_dda_vars u, t_map_info *map, t_frame *f, double angle)
{
	int		up;
	double	wall_x;
	double	wall_y;
	double	dist;

	up = (angle < 0 || angle > M_PI);
	u = get_hor_utils(u, map, up);
	while (coords_within_boundaries(map, u.x, u.y))
	{
		wall_y = get_wall_y(u, up);
		wall_x = floor(u.x);
		if (is_wall(map, wall_x, wall_y))
		{
			dist = sqrt(pow(u.x - map->player.map_pos.x, 2) + \
				pow(u.y - map->player.map_pos.y, 2));
			if (!f->distance || dist < f->distance)
			{
				f->distance = dist;
				fill_frm_hor(f, u, up);
			}
			break ;
		}
		u.x += u.delta_x;
		u.y += u.delta_y;
	}
}

void	dda(t_map_info *map, double ray_angle, t_frame *frame)
{
	t_dda_vars	utils;
	double		fishbowl_corr;

	frame->distance = 0;
	frame->angle = ray_angle;
	fishbowl_corr = cos(normalize_angle(ray_angle - map->player.dir));
	utils.angle_cos = cos(ray_angle);
	utils.angle_sin = sin(ray_angle);
	ver_dda(utils, map, frame, ray_angle);
	hor_dda(utils, map, frame, ray_angle);
	frame->distance *= fishbowl_corr;
	frame->height = CUBE_SIZE / frame->distance * PROJECTION_DISTANCE;
}

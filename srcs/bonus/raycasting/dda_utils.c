/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:57:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:41:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

int	coords_within_boundaries(t_map_info *map, int x, int y)
{
	if (x >= 0 && x < map->map_width * CUBE_SIZE && \
		y >= 0 && y < map->map_height * CUBE_SIZE)
		return (1);
	return (0);
}

int	is_wall(t_map_info *map, int x, int y)
{
	x = (int)floor(x / CUBE_SIZE);
	y = (int)floor(y / CUBE_SIZE);
	if (map->map[y][x] == '1')
		return (1);
	return (0);
}

void	fill_frm_ver(t_frame *f, t_map_info *map, t_dda_vars u, int r)
{
	f->distance = sqrt(pow(u.x - map->player.map_pos.x, 2) + \
		pow(u.y - map->player.map_pos.y, 2));
	f->point.x = u.x;
	f->point.y = u.y;
	f->axis = 1;
	if (r)
		f->wall_face = WEST;
	else
		f->wall_face = EAST;
}

void	fill_frm_hor(t_frame *f, t_dda_vars u, int up)
{
	f->point.x = u.x;
	f->point.y = u.y;
	f->axis = 0;
	if (up)
		f->wall_face = SOUTH;
	else
		f->wall_face = NORTH;
}

double	get_wall_y(t_dda_vars utils, int up)
{
	double	wall_y;

	if (up)
		wall_y = floor(utils.y - 1);
	else
		wall_y = floor(utils.y);
	return (wall_y);
}

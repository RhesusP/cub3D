/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:12:48 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 18:53:46 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

static void	draw_image(t_map_info *map)
{
	int	i;

	i = 0;
	while (i < NB_RAYS)
	{
		if (map->frame[i].distance > 0)
		{
			draw_slice(map, map->frame[i], 2 * i);
			draw_slice(map, map->frame[i], 2 * i + 1);
		}
		i++;
	}
}

// Radian to degree = o * 180/pi
// Degree to radian = o * pi/180
static void	raycasting(t_map_info *map)
{
	int		i;
	double	ray_orientation;

	if (map->frame)
		free(map->frame);
	map->frame = malloc(sizeof(t_frame) * NB_RAYS);
	if (!map->frame)
	{
		print_error("malloc failed\n", 0);
		free_map(map);
	}
	ray_orientation = map->player.dir - (HALF_FOV * DEG_RAD);
	ray_orientation = normalize_angle(ray_orientation);
	i = -1;
	while (++i < NB_RAYS)
	{
		dda(map, ray_orientation, &map->frame[i]);
		ray_orientation += ANGLE_INCR;
		ray_orientation = normalize_angle(ray_orientation);
	}
}

void	draw_frame(t_map_info *map)
{
	map->mlx_img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->mlx_img.img)
		free_map(map);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img, \
		&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length, \
		&map->mlx_img.endian);
	if (!map->mlx_img.addr)
		free_map(map);
	raycasting(map);
	draw_image(map);
	draw_minimap(map, &map->mlx_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->mlx_img.img, 0, 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:12:48 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/09 12:23:39 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	draw_frame(t_map_info *map)
{
	printf("%f (%f)\n", map->player.dir, map->player.dir * 180.0 / M_PI);
	map->mlx_img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img, \
		&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length, \
		&map->mlx_img.endian);
	draw_minimap(map, &map->mlx_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->mlx_img.img, 0, 0);
}

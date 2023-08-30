/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:44:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 16:51:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

void	rotate_left(t_map_info *map)
{
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	map->player.dir -= ROT_SPEED;
	map->player.dir = normalize_angle(map->player.dir);
	draw_frame(map);
}

void	rotate_right(t_map_info *map)
{
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	map->player.dir += ROT_SPEED;
	map->player.dir = normalize_angle(map->player.dir);
	draw_frame(map);
}

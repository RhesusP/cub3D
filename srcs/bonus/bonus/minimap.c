/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:35:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/28 08:36:59 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Trace a square of size MINI_SIZE at the position (x, y) in the image.
 * 
 * @param data image to draw in
 * @param x x position of the square (top left corner)
 * @param y y position of the square (top left corner)
 * @param color 
 */
static void	trace_mini_wall(t_mlx_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINI_SIZE)
	{
		j = 0;
		while (j < MINI_SIZE)
		{
			ft_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

/**
 * @brief Trace a square of size 2 representing the player at the position
 * (x, y) in the image.
 * 
 * @param data image to draw in
 * @param x x position of the square (top left corner)
 * @param y y position of the square (top left corner)
 * @param color 
 */
static void	put_mini_player(t_mlx_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			ft_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

/**
 * @brief Trace rays representing the player's vision.
 * @param map 
 */
static void	trace_mini_rays(t_map_info *map)
{
	int		i;
	t_point	hit_point;

	i = 0;
	while (i < NB_RAYS)
	{
		hit_point.x = (map->frame[i].point.x / CUBE_SIZE) * MINI_SIZE;
		hit_point.y = (map->frame[i].point.y / CUBE_SIZE) * MINI_SIZE;
		ft_draw_line(&map->mlx_img, map->player.mini_pos, \
			hit_point, 0x0000FF00);
		i++;
	}
}

/**
 * @brief Draw the minimap (walls, player, rays)
 * 
 * @param map 
 * @param img 
 */
void	draw_minimap(t_map_info *map, t_mlx_data *img)
{
	int		i;
	int		j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				trace_mini_wall(img, j * MINI_SIZE, i * MINI_SIZE, \
				0x00FFFFFF);
			else
				trace_mini_wall(img, j * MINI_SIZE, i * MINI_SIZE, \
				0x00000000);
			j++;
		}
		i++;
	}
	put_mini_player(img, map->player.mini_pos.x, \
		map->player.mini_pos.y, 0x00FF0000);
	trace_mini_rays(map);
}

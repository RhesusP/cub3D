/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:35:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 19:56:54 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	trace_wall(t_mlx_data *data, int x, int y, int color)
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

void	put_player(t_mlx_data *data, int x, int y, int color)
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

void	draw_minimap(t_map_info *map, t_mlx_data *img)
{
	int		i;
	int		j;
	t_point	hit_point;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				trace_wall(img, j * MINI_SIZE, i * MINI_SIZE, \
				0x00FFFFFF);
			else
				trace_wall(img, j * MINI_SIZE, i * MINI_SIZE, \
				0x00000000);
			j++;
		}
		i++;
	}
	put_player(img, map->player.mini_pos.x, map->player.mini_pos.y, 0x00FF0000);
	i = 0;
	while (i < NB_RAYS)
	{
		// if (i % 2)
		// {
		hit_point.x = (map->frame[i].point.x / CUBE_SIZE) * MINI_SIZE;
		hit_point.y = (map->frame[i].point.y / CUBE_SIZE) * MINI_SIZE;
		ft_draw_line(&map->mlx_img, map->player.mini_pos, hit_point, 0x0000FF00);
		// }
		i++;
	}
}

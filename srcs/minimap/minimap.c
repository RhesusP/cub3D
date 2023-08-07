/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:35:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:30:16 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	trace_cube(t_mlx_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < MINI_CUBE_SIZE)
	{
		j = 0;
		while (j < MINI_CUBE_SIZE)
		{
			ft_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_map_info *map, t_mlx_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				trace_cube(img, j * MINI_CUBE_SIZE, i * MINI_CUBE_SIZE, \
				0x00FFFFFF);
			j++;
		}
		i++;
	}
	trace_cube(img, (map->player.x / CUBE_SIZE) * MINI_CUBE_SIZE, \
	(map->player.y / CUBE_SIZE) * MINI_CUBE_SIZE, 0x00FF0000);
}

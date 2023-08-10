/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:35:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/10 18:08:49 by cbernot          ###   ########.fr       */
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
	t_point	end_line;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == '1')
				trace_wall(img, j * MINI_SIZE, i * MINI_SIZE, \
				0x00FFFFFF);
			j++;
		}
		i++;
	}
	put_player(img, map->player.mini_pos.x, map->player.mini_pos.y, 0x00FF0000);
	end_line.x = map->player.mini_pos.x + cos(map->player.dir) * 16;
	end_line.y = map->player.mini_pos.y + sin(map->player.dir) * 16;
	ft_draw_line(img, map->player.mini_pos, end_line, 0x00FFFF00);
}

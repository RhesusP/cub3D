/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:34:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/08 20:21:51 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_slice(t_map_info *map, t_mlx_data *img, int index)
{
	int	i;
	int	y_offset;

	i = 0;
	y_offset = (HEIGHT / 2) - (map->frame[index].height / 2);
	while (i < map->frame[index].height)
	{
		ft_mlx_pixel_put(img, index, y_offset + i, 0x00FF0000);
		i++;
	}
}

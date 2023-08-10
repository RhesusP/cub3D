/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:34:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/10 18:51:29 by cbernot          ###   ########.fr       */
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
	printf("wall or: %c\n", map->frame->wall_orientation);
	i = 0;
	if (map->frame[index].height >= HEIGHT)
	{
		while (i < HEIGHT)
		{
			ft_mlx_pixel_put(img, index, i, 0x00FF0000);
			i++;
		}
		return ;
	}
	y_offset = (HEIGHT - map->frame[index].height) / 2;
	if (y_offset < 0)
		return ;
	while (i < y_offset)
	{
		ft_mlx_pixel_put(img, index, i, map->ceiling_color);
		i++;
	}
	while (i < map->frame[index].height + y_offset)
	{
		ft_mlx_pixel_put(img, index, i, 0x00FF0000);
		i++;
	}
	while (i < HEIGHT)
	{
		ft_mlx_pixel_put(img, index, i, map->floor_color);
		i++;
	}
}

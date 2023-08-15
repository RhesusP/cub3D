/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:34:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/15 18:34:04 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_wall_color(t_frame frame)
{
	if (frame.wall_orientation == NORTH)
		return (0x00FF0000);
	else if (frame.wall_orientation == SOUTH)
		return (0x0000FF00);
	else if (frame.wall_orientation == EAST)
		return (0x000000FF);
	else if (frame.wall_orientation == WEST)
		return (0x00FFFF00);
	return (0x00FFFFFF);
}

void	draw_slice(t_map_info *map, t_mlx_data *img, int index)
{
	int	i;
	int	y_offset;
	printf("wall or: %d\n", map->frame->wall_orientation);
	i = 0;
	if (map->frame[index].height >= HEIGHT)
	{
		while (i < HEIGHT)
		{
			ft_mlx_pixel_put(img, index, i, get_wall_color(map->frame[index]));
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
		ft_mlx_pixel_put(img, index, i, get_wall_color(map->frame[index]));
		i++;
	}
	while (i < HEIGHT)
	{
		ft_mlx_pixel_put(img, index, i, map->floor_color);
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:34:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 20:05:00 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

void	ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;
	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	get_wall_color(t_frame frame)
{
	if (frame.wall_face == NORTH)			// red
		return (create_mlx_color(0, 255, 0, 0));
	else if (frame.wall_face == SOUTH)		// green
		return (create_mlx_color(0, 0, 255, 0));
	else if (frame.wall_face == EAST)		// blue
		return (create_mlx_color(0, 0, 0, 255));
	else if (frame.wall_face == WEST)
		return (create_mlx_color(0, 255, 0, 255));	// purple
	return (create_mlx_color(0, 0, 0, 0));			// black
}

t_text	*get_texture(t_map_info *map, enum e_side side)
{
	if (side == NORTH)
		return (map->no_texture);
	else if (side == SOUTH)
		return (map->so_texture);
	else if (side == EAST)
		return (map->ea_texture);
	else
		return (map->we_texture);
}

void	draw_texture_col(t_map_info *map, t_frame frame, int x, int offset)
{
	float	scale;
	int		texture_x_offset;
	t_text	*texture;
	float	text_y;
	int		texture_y;
	int 	y;
	int		color;

	texture = get_texture(map, frame.wall_face);
	scale = texture->height / frame.height;
	
	if (frame.axis == 1)
		texture_x_offset = frame.point.y % CUBE_SIZE;
	else
		texture_x_offset = frame.point.x % CUBE_SIZE;
	text_y = 0;
	if (frame.height > HEIGHT)
        text_y = ((frame.height - HEIGHT) / 2) * scale;
	y = 0;
	while (y < frame.height)
	{
		texture_y = (int)text_y % texture->height;
		color = get_texture_pixel(texture, texture_x_offset, texture_y);
		ft_mlx_pixel_put(&map->mlx_img, x, y + offset, color);
		text_y += scale;
		y++;
	}
}

void	draw_slice(t_map_info *map, t_mlx_data *img, t_frame frame, int index)
{
	int	i;
	int	y_offset;
	i = 0;
	y_offset = (HEIGHT - frame.height) / 2;
	if (y_offset < 0)
		y_offset = 0;
	// draw ceil
	while (i < y_offset)
	{
		ft_mlx_pixel_put(img, index, i, map->ceiling_color);
		i++;
	}
	// draw wall
	draw_texture_col(map, frame, index, i);
	i = frame.height + y_offset;
	while (i < HEIGHT)
	{
		ft_mlx_pixel_put(img, index, i, map->floor_color);
		i++;
	}
}

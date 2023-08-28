/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 16:34:14 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 13:07:34 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Get the texture according to the wall face.
 * 
 * @param map 
 * @param side 
 * @return t_text* 
 */
static t_text	*get_texture(t_map_info *map, enum e_side side)
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

/**
 * @brief Draw a column of the texture on the screen.
 * @details Draws a column of the texture on the screen according to the frame
 * informations. The texture is scaled according to the texture height and the
 * wall height.
 * @param map 
 * @param frame 
 * @param x index of the column (x coordinate)
 * @param offset offset of the column (y coordinate)
 */
static void	draw_texture_col(t_map_info *map, t_frame frame, int x, int offset)
{
	float	scale;
	int		texture_x_offset;
	t_text	*texture;
	float	text_y;
	int		y;

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
		ft_mlx_pixel_put(&map->mlx_img, x, y + offset, \
			get_texture_color(texture, texture_x_offset, \
			(int)text_y % texture->height));
		text_y += scale;
		y++;
	}
}

/**
 * @brief Draws a slice of the screen
 * @details Draws a slice of the screen composed of a ceiling, a wall and a 
 * floor.
 * @param map 
 * @param frame 
 * @param index index of the slice. It is the x coordinate of the slice.
 */
void	draw_slice(t_map_info *map, t_frame frame, int index)
{
	int	i;
	int	y_offset;

	i = 0;
	y_offset = (HEIGHT - frame.height) / 2;
	if (y_offset < 0)
		y_offset = 0;
	while (i < y_offset)
	{
		ft_mlx_pixel_put(&map->mlx_img, index, i, map->ceiling_color);
		i++;
	}
	draw_texture_col(map, frame, index, i);
	i = frame.height + y_offset;
	while (i < HEIGHT)
	{
		ft_mlx_pixel_put(&map->mlx_img, index, i, map->floor_color);
		i++;
	}
}

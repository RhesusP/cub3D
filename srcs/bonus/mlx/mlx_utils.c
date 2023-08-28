/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 13:12:16 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Loads a texture from a path.
 * 
 * @param map 
 * @param texture 
 * @param path 
 * @return int 1 if the texture is correctly loaded, 0 otherwise
 */
int	load_texture(t_map_info *map, t_text *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(map->mlx, path, \
		&texture->width, &texture->height);
	if (!texture->img)
		return (print_error("texture not found\n", 0));
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, \
		&texture->line_length, &texture->endian);
	if (!texture->addr)
		return (print_error("texture addr not found\n", 0));
	return (1);
}

/**
 * @brief Get the color of a pixel in a texture.
 * 
 * @param text texture to get the color from
 * @param x 
 * @param y 
 * @return int the color of the pixel
 */
int	get_texture_color(t_text *text, int x, int y)
{
	int	pixel_offset;

	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)
		return (0);
	pixel_offset = y * text->line_length + x * (text->bits_per_pixel / 8);
	return (*(int *)(text->addr + pixel_offset));
}

/**
 * @brief Create a color in the mlx format.
 *  
 * @param t transparency
 * @param r red
 * @param g green
 * @param b blue
 * @return int 
 */
int	create_mlx_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

/**
 * @brief Key handling function.
 * @details Handles the following keys:
 * - ESC: exits the program
 * - LEFT_ARROW: rotates the player to the left
 * - RIGHT_ARROW: rotates the player to the right
 * - W: moves the player forward
 * - S: moves the player backward
 * - A: moves the player to the left
 * - D: moves the player to the right
 * The mlx image is destroyed and a new one is created to draw the new frame.
 * @param keycode 
 * @param map 
 * @return int 
 */
static int	key_hook(int keycode, t_map_info *map)
{
	if (keycode == LEFT_ARROW)
	{
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir -= ROT_SPEED;
		map->player.dir = normalize_angle(map->player.dir);
		draw_frame(map);
	}
	else if (keycode == RIGHT_ARROW)
	{
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir += ROT_SPEED;
		map->player.dir = normalize_angle(map->player.dir);
		draw_frame(map);
	}
	else if (keycode == FORWARD)
		move_forward(map);
	else if (keycode == BACKWARD)
		move_backward(map);
	else if (keycode == LEFT)
		move_left(map);
	else if (keycode == RIGHT)
		move_right(map);
	if (keycode == ESC)
		free_map(map);
	return (0);
}

/**
 * @brief Main game loop.
 * @details The function initializes the mlx window and calls the key_hook 
 * function and performs the raycasting and rendering parts.
 * @param map 
 */
void	game_loop(t_map_info *map)
{
	mlx_do_key_autorepeaton(map->mlx);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, (1L << 2), free_map, map);
	draw_frame(map);
	mlx_loop(map->mlx);
}

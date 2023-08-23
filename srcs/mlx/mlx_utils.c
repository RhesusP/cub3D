/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 13:26:26 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	load_texture(t_map_info *map, t_text *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(map->mlx, path, &texture->width, &texture->height);
	if (!texture->img)
	{
		printf("%s", path);
		return (print_error("texture not found\n", 0, 0));
	}
	texture->addr = mlx_get_data_addr(texture->img, &texture->bits_per_pixel, &texture->line_length, &texture->endian);
	if (!texture->addr)
		return (print_error("texture addr not found\n", 0, 0));
	return (1);
}

int	get_texture_pixel(t_text *text, int x, int y)
{
	if (x < 0 || x >= text->width)
		return (0);
	if (y < 0 || y >= text->height)
		return (0);
	int pixel_offset = y * text->line_length + x * (text->bits_per_pixel / 8);
	return *(int *)(text->addr + pixel_offset);
}

int	create_mlx_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	key_hook(int keycode, t_map_info *map)
{
	if (keycode == LEFT_ARROW)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir -= ROT_SPEED;
		map->player.dir = normalize_angle(map->player.dir);
		draw_frame(map);
	}
	else if (keycode == RIGHT_ARROW)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
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
		exit(EXIT_SUCCESS);
	return (0);
}

int	free_map(t_map_info *map)
{
	printf("need to free map\n");
	(void)map;
	exit(EXIT_SUCCESS);
	return (0);
}

void	start_mlx(t_map_info *map)
{
	mlx_do_key_autorepeaton(map->mlx);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, (1L << 2), free_map, map);
	draw_frame(map);
	mlx_loop(map->mlx);
}

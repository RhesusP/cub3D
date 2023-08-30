/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 23:10:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

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

int	create_mlx_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static int	key_hook(int keycode, t_map_info *map)
{
	if (keycode == LEFT_ARROW)
		rotate_left(map);
	else if (keycode == RIGHT_ARROW)
		rotate_right(map);
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

int funct(int x, int y, void *param)
{
	t_map_info	*map;

	map = (t_map_info *)param;

	if ((x > 0 && x < WIDTH) && (y > 0 && y < HEIGHT))
	{
		if (map->mouse_x < x)
			rotate_right(map);
		else if (map->mouse_x > x)
			rotate_left(map);
		map->mouse_x = x;
	}
	// static		t_point	ref = {-1, -1};
	// int			delta_x;

	// printf("ref: (%d, %d)\n", ref.x, ref.y);
	// printf("x: %d, y: %d\n", x, y);
	// if (x <= 20 || x > WIDTH - 20 || y <= 20 || y > HEIGHT - 20)
	// {
	// 	printf("mouse out\n");
	// 	ref.x = -1;
	// 	ref.y = -1;
	// }
	// if (ref.x == -1 && ref.y == -1)
	// {
	// 	ref.x = x;
	// 	ref.y = y;
	// }
	// map = (t_map_info *)param;

	// delta_x = x - ref.x;
	// printf("delta_x: %d\n", delta_x);
	// delta_x /= 4;
	// printf("delta_x: %d\n", delta_x);
	// if (delta_x > 0)
	// {
	// 	mlx_destroy_image(map->mlx, map->mlx_img.img);
	// 	map->player.dir += ROT_SPEED;
	// 	map->player.dir = normalize_angle(map->player.dir);
	// 	draw_frame(map);
	// }
	// else if (delta_x < 0)
	// {
	// 	mlx_destroy_image(map->mlx, map->mlx_img.img);
	// 	map->player.dir -= ROT_SPEED;
	// 	map->player.dir = normalize_angle(map->player.dir);
	// 	draw_frame(map);
	// }




	// delta_x = x - NB_RAYS;
	// printf("delta_x: %d\n", delta_x);

	// mlx_destroy_image(map->mlx, map->mlx_img.img);
	// map->player.dir += ROT_SPEED;
	// map->player.dir = normalize_angle(map->player.dir);
	// draw_frame(map);
	return (0);
}

void	game_loop(t_map_info *map)
{
	mlx_do_key_autorepeaton(map->mlx);
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	mlx_hook(map->mlx_win, 17, (1L << 2), free_map, map);
	mlx_hook(map->mlx_win, 6, (1L << 6), funct, map);
	draw_frame(map);
	mlx_loop(map->mlx);
}

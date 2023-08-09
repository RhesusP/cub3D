/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:24:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/09 12:25:27 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	key_hook(int keycode, t_map_info *map)
{
	if (keycode == LEFT_ARROW)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir -= ROT_SPEED;
		draw_frame(map);
	}
	else if (keycode == RIGHT_ARROW)
	{
		mlx_clear_window(map->mlx, map->mlx_win);
		mlx_destroy_image(map->mlx, map->mlx_img.img);
		map->player.dir += ROT_SPEED;
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
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

void	start_mlx(t_map_info *map)
{
	map->mlx = mlx_init();
	mlx_do_key_autorepeaton(map->mlx);
	if (!map->mlx)
		print_error("mlx_init() failed\n", 0, EXIT_FAILURE);
	map->mlx_win = mlx_new_window(map->mlx, WIDTH, HEIGHT, "cub3D");
	mlx_hook(map->mlx_win, 2, 1L << 0, key_hook, map);
	draw_frame(map);
	mlx_loop(map->mlx);
}

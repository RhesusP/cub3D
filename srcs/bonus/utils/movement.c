/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 12:09:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/18 12:08:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Checks if the player can move to the new position.
 * @details The new position is valid if it is in boundaries and is not a wall.
 * @param map 
 * @param new_x x coordinate of position to check
 * @param new_y y coordinate of position to check
 * @return int 1 if the new position is invalid, 0 otherwise
 */
static int	is_blocking(t_map_info *map, int new_x, int new_y)
{
	new_x /= CUBE_SIZE;
	new_y /= CUBE_SIZE;
	if (new_x < 0 || new_x >= map->map_width || new_y < 0 || \
		new_y >= map->map_height)
	{
		return (1);
	}
	if (map->map[new_y][new_x] == '1' || map->map[new_y][new_x] == ' ')
	{
		return (1);
	}
	return (0);
}

/**
 * @brief Moves the player forward
 * @details If the new position is in boundaries and is not a wall, the player
 * moves to the new position.
 * @param map 
 */
void	move_forward(t_map_info *map)
{
	double	new_x;
	double	new_y;

	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player.map_pos.x + cos(map->player.dir) * map->player.speed;
	new_y = map->player.map_pos.y + sin(map->player.dir) * map->player.speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player.map_pos.x = new_x;
		map->player.map_pos.y = new_y;
		map->player.mini_pos.x = new_x / CUBE_SIZE * MINI_SIZE;
		map->player.mini_pos.y = new_y / CUBE_SIZE * MINI_SIZE;
	}
	draw_frame(map);
}

/**
 * @brief Moves the player backward
 * @details If the new position is in boundaries and is not a wall, the player
 * moves to the new position.
 * @param map 
 */
void	move_backward(t_map_info *map)
{
	double	new_x;
	double	new_y;

	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player.map_pos.x - cos(map->player.dir) * map->player.speed;
	new_y = map->player.map_pos.y - sin(map->player.dir) * map->player.speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player.map_pos.x = new_x;
		map->player.map_pos.y = new_y;
		map->player.mini_pos.x = new_x / CUBE_SIZE * MINI_SIZE;
		map->player.mini_pos.y = new_y / CUBE_SIZE * MINI_SIZE;
	}
	draw_frame(map);
}

/**
 * @brief Moves the player to its left
 * @details If the new position is in boundaries and is not a wall, the player
 * moves to the new position.
 * @param map 
 */
void	move_left(t_map_info *map)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = map->player.speed;
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player.map_pos.x - cos(map->player.dir + M_PI_2) * speed;
	new_y = map->player.map_pos.y - sin(map->player.dir + M_PI_2) * speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player.map_pos.x = new_x;
		map->player.map_pos.y = new_y;
		map->player.mini_pos.x = new_x / CUBE_SIZE * MINI_SIZE;
		map->player.mini_pos.y = new_y / CUBE_SIZE * MINI_SIZE;
	}
	draw_frame(map);
}

/**
 * @brief Moves the player to its right
 * @details If the new position is in boundaries and is not a wall, the player
 * moves to the new position.
 * @param map 
 */
void	move_right(t_map_info *map)
{
	double	new_x;
	double	new_y;
	double	speed;

	speed = map->player.speed;
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	new_x = map->player.map_pos.x + cos(map->player.dir + M_PI_2) * speed;
	new_y = map->player.map_pos.y + sin(map->player.dir + M_PI_2) * speed;
	if (!is_blocking(map, new_x, new_y))
	{
		map->player.map_pos.x = new_x;
		map->player.map_pos.y = new_y;
		map->player.mini_pos.x = new_x / CUBE_SIZE * MINI_SIZE;
		map->player.mini_pos.y = new_y / CUBE_SIZE * MINI_SIZE;
	}
	draw_frame(map);
}

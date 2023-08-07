/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:57:45 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:42:36 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

/**
 * @brief WIP (not working correctly yet)
 * 
 * @param map 
 */
t_point	find_horizontal_wall(t_map_info *map, double orientation)
{
	printf("orientation: %f\n", orientation);
	t_point	a;
	t_point	b;
	t_point err;
	double	delta_x;
	double	delta_y;
	double	tan_orientation;

	err.x = -1;
	err.y = -1;
	tan_orientation = tan(orientation);
	if (orientation >= 0 && orientation < M_PI)
		a.y = floor(map->player.y / CUBE_SIZE) * CUBE_SIZE - 1;
	else
		a.y = floor(map->player.y / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	a.x = floor(map->player.x + (map->player.y - a.y) / tan_orientation);
	if (a.x < 0 || a.y < 0 || floor(a.x / 64) >= map->width || floor(a.y / 64) >= map->height)
		return (err);
	if (map->map[(int)floor(a.x / 64)][(int)floor(a.y / 64)] == '1')
		return (a);
	if (orientation >= 0 && orientation < M_PI)
		delta_y = -CUBE_SIZE;
	else
		delta_y = CUBE_SIZE;
	delta_x = floor(CUBE_SIZE / tan_orientation);
	b.x = a.x + delta_x;
	b.y = a.y + delta_y;
	if (b.x < 0 || b.y < 0 || floor(b.x / 64) >= map->width || floor(b.y / 64) >= map->height)
		return (err);
	while (map->map[(int)floor(b.x / 64)][(int)floor(b.y / 64)] != '1')
	{
		b.x += delta_x;
		b.y += delta_y;
		if (b.x < 0 || b.y < 0 || floor(b.x / 64) >= map->width || floor(b.y / 64) >= map->height)
			return (err);
	}
	return (b);
}

/**
 * @brief WIP (not working correctly yet)
 * 
 * @param map 
 */
t_point	find_vertical_wall(t_map_info *map, double orientation)
{
	printf("orientation: %f\n", orientation);
	t_point	a;
	t_point	b;
	t_point err;
	double	delta_x;
	double	delta_y;
	double	tan_orientation;

	err.x = -1;
	err.y = -1;
	tan_orientation = tan(orientation);
	if (orientation >= M_PI_2 && orientation < 3 * M_PI_2)
		a.x = floor(map->player.x / CUBE_SIZE) * CUBE_SIZE + CUBE_SIZE;
	else
		a.x = floor(map->player.x / CUBE_SIZE) * CUBE_SIZE - 1;
	a.y = floor(map->player.y + (map->player.x - a.x) * tan_orientation);
	if (a.x < 0 || a.y < 0 || floor(a.x / 64) >= map->width || floor(a.y / 64) >= map->height)
		return (err);
	if (map->map[(int)floor(a.x / 64)][(int)floor(a.y / 64)] == '1')
		return (a);
	if (orientation >= M_PI_2 && orientation < 3 * M_PI_2)
		delta_x = CUBE_SIZE;
	else
		delta_x	= -CUBE_SIZE;
	delta_y = floor(CUBE_SIZE * tan_orientation);
	b.x = a.x + delta_x;
	b.y = a.y + delta_y;
	if (b.x < 0 || b.y < 0 || floor(b.x / 64) >= map->width || floor(b.y / 64) >= map->height)
		return (err);
	while (map->map[(int)floor(b.x / 64)][(int)floor(b.y / 64)] != '1')
	{
		b.x += delta_x;
		b.y += delta_y;
		if (b.x < 0 || b.y < 0 || floor(b.x / 64) >= map->width || floor(b.y / 64) >= map->height)
			return (err);
	}
	return (b);
}


double	get_distance(t_point a, t_point b)
{
	return (sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2)));
}

/**
 * @brief WIP (not working correctly yet)
 * 
 * @param map 
 */
double	find_wall(t_map_info *map, double orientation)
{
	t_point	horizontal_wall;
	t_point	vertical_wall;
	
	horizontal_wall = find_horizontal_wall(map, orientation);
	return (get_distance(map->player, horizontal_wall));
	vertical_wall = find_vertical_wall(map, orientation);
	if (horizontal_wall.x == -1 && horizontal_wall.y == -1)
		return (get_distance(map->player, vertical_wall));
	if (vertical_wall.x == -1 && vertical_wall.y == -1)
		return (get_distance(map->player, horizontal_wall));
	if (get_distance(map->player, horizontal_wall) < get_distance(map->player, vertical_wall))
		return (get_distance(map->player, horizontal_wall));
	else
		return (get_distance(map->player, vertical_wall));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 23:57:20 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 12:16:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Checks if the coordinates are within the map boundaries.
 * 
 * @param map 
 * @param x 
 * @param y 
 * @return int 1 if the coordinates are within the map boundaries, 0 otherwise 
 */
int	coords_within_boundaries(t_map_info *map, int x, int y)
{
	if (x >= 0 && x < map->map_width * CUBE_SIZE && \
		y >= 0 && y < map->map_height * CUBE_SIZE)
		return (1);
	return (0);
}

/**
 * @brief Checks if the coordinates are on a wall.
 * 
 * @param map
 * @param x 
 * @param y 
 * @return int 1 if the coordinates are on a wall, 0 otherwise 
 */
int	is_wall(t_map_info *map, int x, int y)
{
	x = (int)floor(x / CUBE_SIZE);
	y = (int)floor(y / CUBE_SIZE);
	if (map->map[y][x] == '1')
		return (1);
	return (0);
}

/**
 * @brief Fill the frame informations for a vertical wall.
 * @details The distance is calculated using the Pythagorean theorem. The point
 * coordinates are the coordinates of the wall. The axis is set to 1 (vertical).
 * The wall face is set to WEST if the ray is facing right, EAST otherwise.
 * @param f 
 * @param map 
 * @param u 
 * @param r 1 if the ray is facing right, 0 otherwise
 */
void	fill_frm_ver(t_frame *f, t_map_info *map, t_dda_vars u, int r)
{
	f->distance = sqrt(pow(u.x - map->player.map_pos.x, 2) + \
		pow(u.y - map->player.map_pos.y, 2));
	f->point.x = u.x;
	f->point.y = u.y;
	f->axis = 1;
	if (r)
		f->wall_face = WEST;
	else
		f->wall_face = EAST;
}

/**
 * @brief Fill the frame informations for an horizontal wall.
 * @details The point coordinates are the coordinates of the wall. The axis is
 * set to 0 (horizontal). The wall face is set to SOUTH if the ray is facing up,
 * NORTH otherwise.
 * @param f 
 * @param u 
 * @param up 1 if the ray is facing up, 0 otherwise
 */
void	fill_frm_hor(t_frame *f, t_dda_vars u, int up)
{
	f->point.x = u.x;
	f->point.y = u.y;
	f->axis = 0;
	if (up)
		f->wall_face = SOUTH;
	else
		f->wall_face = NORTH;
}

/**
 * @brief Approximates the y coordinate of a potential wall hit by the ray.
 * 
 * @param utils 
 * @param up 1 if the ray is facing up, 0 otherwise
 * @return double
 */
double	get_wall_y(t_dda_vars utils, int up)
{
	double	wall_y;

	if (up)
		wall_y = floor(utils.y - 1);
	else
		wall_y = floor(utils.y);
	return (wall_y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:34:59 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 12:29:50 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Associates a description character to an orientation in radians.
 * @details Here are possible orientations:
 * - North 270.0° or 3 * M_PI_2 rad
 * - South 90.0° or M_PI_2 rad
 * - East 0.0° or 0.0 rad
 * - West 180.0° or M_PI
 * By default, the orientation is North (270.0° or 3 * M_PI_2 rad).
 * @param orientation 
 * @return double 
 */
static double	get_player_orientation(char c)
{
	if (c == 'N')
		return (3 * M_PI_2);
	else if (c == 'S')
		return (M_PI_2);
	else if (c == 'E')
		return (0.0);
	else if (c == 'W')
		return (M_PI);
	return (3 * M_PI_2);
}

/**
 * @brief Initializes the player starting position and orientation.
 * @details The player starting position is the center of the cell where the
 * player orientation is given in map description. The player orientation is
 * given in radians.
 * 
 * @param map
 */
void	get_start_pos(t_map_info *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (map->map[i][j] == 'N' || map->map[i][j] == 'S' || \
			map->map[i][j] == 'E' || map->map[i][j] == 'W')
			{
				map->player.map_pos.x = j * CUBE_SIZE + CUBE_SIZE / 2;
				map->player.map_pos.y = i * CUBE_SIZE + CUBE_SIZE / 2;
				map->player.dir = get_player_orientation(map->map[i][j]);
				map->player.speed = SPEED;
				return ;
			}
			j++;
		}
		i++;
	}
}

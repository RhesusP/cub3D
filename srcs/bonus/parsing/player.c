/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:34:59 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:41:00 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Get the player orientation given in map description
 * @details Here are possible directions :
 * - North 270.0° or 3 * M_PI_2 rad
 * - South 90.0° or M_PI_2 rad
 * - East 0.0° or 0.0 rad
 * - West 180.0° or M_PI
 * @param orientation char found in map description
 * @return double 
 */
static double	get_player_orientation(char orientation)
{
	if (orientation == 'N')
		return (3 * M_PI_2);
	else if (orientation == 'S')
		return (M_PI_2);
	else if (orientation == 'E')
		return (0.0);
	else if (orientation == 'W')
		return (M_PI);
	return (3 * M_PI_2);
}

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
				map->player.mini_pos.x = j * MINI_SIZE + MINI_SIZE / 2;
				map->player.mini_pos.y = i * MINI_SIZE + MINI_SIZE / 2;
				map->player.dir = get_player_orientation(map->map[i][j]);
				map->player.speed = SPEED;
				return ;
			}
			j++;
		}
		i++;
	}
}

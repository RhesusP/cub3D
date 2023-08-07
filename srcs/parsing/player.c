/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:34:59 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:39:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

double	get_player_orientation(char orientation)
{
	if (orientation == 'N')
		return (M_PI_2);
	else if (orientation == 'S')
		return (3 * M_PI_2);
	else if (orientation == 'E')
		return (0.0);
	else if (orientation == 'W')
		return (M_PI);
	return (0.0);
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
				map->player.x = j * CUBE_SIZE + CUBE_SIZE / 2;
				map->player.y = i * CUBE_SIZE + CUBE_SIZE / 2;
				map->player_or = get_player_orientation(map->map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
}

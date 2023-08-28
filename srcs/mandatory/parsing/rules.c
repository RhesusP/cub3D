/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:09:02 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 12:25:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Checks if all map elements are initialized  (execpt map description).
 * @details Checked elements are floor color, ceiling color, north texture, 
 * south texture, east texture and west texture.
 * @param map 
 * @return int 1 if all elements are initialized, 0 otherwise
 */
int	text_col_complete(t_map_info *map)
{
	if (map->floor_color < 0 || map->ceiling_color < 0)
		return (0);
	if (!map->no_texture->img || !map->so_texture->img || \
		!map->ea_texture->img || !map->we_texture->img)
		return (0);
	return (1);
}

/**
 * @brief Check if the map description contains only one player.
 * @param map map description
 * @return int 1 if the map description contains only one player, 0 otherwise
 */
int	map_have_one_player(char **map)
{
	int	i;
	int	j;
	int	player_detected;

	player_detected = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!player_detected && char_is_player(map[i][j]))
				player_detected = 1;
			else if (player_detected && char_is_player(map[i][j]))
				return (print_error("multiple players in map description\n", 0));
			j++;
		}
		i++;
	}
	if (!player_detected)
		return (print_error("no player specified in map description\n", 0));
	return (1);
}

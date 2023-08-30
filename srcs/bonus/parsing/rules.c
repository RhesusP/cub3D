/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 22:09:02 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 15:07:41 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

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

int	valid_surroundings(char **map, int i, int j)
{
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' \
		|| map[i][j - 1] == ' ' || map[i][j + 1] == ' ' \
		|| !map[i - 1][j] || !map[i + 1][j] \
		|| !map[i][j - 1] || !map[i][j + 1])
		return (0);
	return (1);
}

/**
 * @brief Checks if the map description is surrounded by walls.
 * 
 * @param map 2d array containing the map description
 * @return int 1 if the map is surrounded by walls, 0 otherwise
 */
int	is_map_closed(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr("NSWE", map[i][j]) && !valid_surroundings(map, i, j))
				return (print_error("map is not closed\n", 0));
			if (map[i][j] == '0' && !valid_surroundings(map, i, j))
				return (print_error("map is not closed\n", 0));
			j++;
		}
		i++;
	}
	return (1);
}

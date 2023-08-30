/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:12:56 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 13:49:58 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Checks if the character is a player orientation.
 * 
 * @param c 
 * @return int 1 if the character is a player orientation, 0 otherwise
 */
int	char_is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

/**
 * @brief Checks if the character is a valid map description character.
 * 
 * @param c
 * @return int 1 if the character is a valid map description character, 0 
 * otherwise
 */
int	is_desc_char_valid(char c)
{
	if (c == ' ' || c == '0' || c == '1' || char_is_player(c))
		return (1);
	return (0);
}

/**
 * @brief Checks if the line belong to a map description.
 * @details A line belong to the map description if it is not empty and does not
 * start with a valid map element description (NO, SO, WE, EA, F, C)
 * @param line 
 * @return int 1 if the line belong to a map description, 0 otherwise
 */
int	is_map_desc(char *line)
{
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (0);
	else
		return (1);
}

/**
 * @brief Initializes the map info structure.
 * @details The map info structure contains all the information about the map.
 * Textures are allocated.
 * @param map map info structure to initialize
 * @return int 1 if the initialization is successful, 0 otherwise
 */
int	init_void_map(t_map_info *map)
{
	if (!init_no_text(map))
		return (0);
	if (!init_so_text(map))
		return (0);
	if (!init_ea_text(map))
		return (0);
	if (!init_we_text(map))
		return (0);
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_width = 0;
	map->map_height = 0;
	map->map = NULL;
	map->player.map_pos.x = 0;
	map->player.map_pos.y = 0;
	map->player.mini_pos.x = 0;
	map->player.mini_pos.y = 0;
	map->player.dir = 0;
	map->frame = 0;
	map->mouse_x = NB_RAYS;
	return (1);
}

/**
 * @brief Initializes the map 2D char array.
 * @details The map 2D char array contains the map description.
 * @param map 
 * @param height map description height
 * @param width map description width
 * @return int 1 if the initialization is successful, 0 otherwise
 */
int	init_map_array(t_map_info *map, int height, int width)
{
	int	i;

	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
	{
		free_allocated_text(map);
		return (print_error("malloc failed\n", 0));
	}
	map->map[height] = NULL;
	i = 0;
	while (i < height)
	{
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
		{
			free_partial_array(&map->map, i);
			return (print_error("malloc failed\n", 0));
		}
		map->map[i][width] = '\0';
		i++;
	}
	return (1);
}

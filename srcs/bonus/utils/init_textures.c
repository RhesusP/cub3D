/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 12:07:13 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 13:03:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Initializes the north texture.
 * 
 * @param map
 * @return int 1 if the initialization is successful, 0 otherwise 
 */
int	init_no_text(t_map_info *map)
{
	map->no_texture = malloc(sizeof(t_text));
	if (!map->no_texture)
		return (print_error("malloc failed\n", 0));
	map->no_texture->is_init = 0;
	return (1);
}

/**
 * @brief Initializes the south texture.
 * 
 * @param map 
 * @return int 1 if the initialization is successful, 0 otherwise
 */
int	init_so_text(t_map_info *map)
{
	map->so_texture = malloc(sizeof(t_text));
	if (!map->so_texture)
	{
		free(map->no_texture);
		return (print_error("malloc failed\n", 0));
	}
	map->so_texture->is_init = 0;
	return (1);
}

/**
 * @brief Initializes the east texture.
 * 
 * @param map 
 * @return int 1 if the initialization is successful, 0 otherwise
 */
int	init_ea_text(t_map_info *map)
{
	map->ea_texture = malloc(sizeof(t_text));
	if (!map->ea_texture)
	{
		free(map->no_texture);
		free(map->so_texture);
		return (print_error("malloc failed\n", 0));
	}
	map->ea_texture->is_init = 0;
	return (1);
}

/**
 * @brief Initializes the west texture.
 * 
 * @param map 
 * @return int 1 if the initialization is successful, 0 otherwise
 */
int	init_we_text(t_map_info *map)
{
	map->we_texture = malloc(sizeof(t_text));
	if (!map->we_texture)
	{
		free(map->no_texture);
		free(map->so_texture);
		free(map->ea_texture);
		return (print_error("malloc failed\n", 0));
	}
	map->we_texture->is_init = 0;
	return (1);
}

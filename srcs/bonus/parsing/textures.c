/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/18 11:26:25 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Loads the north texture and stores it in the map structure.
 * @details Spaces and ending newlines are removed from the path. If the 
 * texture is already initialized, the function returns 1. Else, the texture 
 * is loaded with mlx_xpm_file_to_image and stored in the map structure.
 * @param line 
 * @param map
 * @return int 1 if the texture is correctly loaded or already initialized, 0 
 * otherwise 
 */
static int	add_no_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->no_texture->is_init)
		return (print_error("double definition of a texture (NO)\n", 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0));
	if (!load_texture(map, map->no_texture, path))
	{
		free(path);
		return (0);
	}
	map->no_texture->is_init = 1;
	free(path);
	return (1);
}

/**
 * @brief Loads the south texture and stores it in the map structure.
 * @details Spaces and ending newlines are removed from the path. If the 
 * texture is already initialized, the function returns 1. Else, the texture 
 * is loaded with mlx_xpm_file_to_image and stored in the map structure.
 * @param line 
 * @param map 
 * @return int 1 if the texture is correctly loaded or already initialized, 0 
 * otherwise 
 */
static int	add_so_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->so_texture->is_init)
		return (print_error("double definition of a texture (SO)\n", 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0));
	if (!load_texture(map, map->so_texture, path))
	{
		free(path);
		return (0);
	}
	map->so_texture->is_init = 1;
	free(path);
	return (1);
}

/**
 * @brief Loads the east texture and stores it in the map structure.
 * @details Spaces and ending newlines are removed from the path. If the 
 * texture is already initialized, the function returns 1. Else, the texture 
 * is loaded with mlx_xpm_file_to_image and stored in the map structure.
 * @param line 
 * @param map 
 * @return int 1 if the texture is correctly loaded or already initialized, 0 
 * otherwise
 */
static int	add_ea_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->ea_texture->is_init)
		return (print_error("double definition of a texture (EA)\n", 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0));
	if (!load_texture(map, map->ea_texture, path))
	{
		free(path);
		return (0);
	}
	map->ea_texture->is_init = 1;
	free(path);
	return (1);
}

/**
 * @brief Loads the west texture and stores it in the map structure.
 * @details Spaces and ending newlines are removed from the path. If the 
 * texture is already initialized, the function returns 1. Else, the texture 
 * is loaded with mlx_xpm_file_to_image and stored in the map structure.
 * @param line 
 * @param map 
 * @return int 1 if the texture is correctly loaded or already initialized, 0 
 * otherwise
 */
static int	add_we_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->we_texture->is_init)
		return (print_error("double definition of a texture (WE)\n", 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0));
	if (!load_texture(map, map->we_texture, path))
	{
		free(path);
		return (0);
	}
	map->we_texture->is_init = 1;
	free(path);
	return (1);
}

/**
 * @brief Adds the texture described in the line to the map structure.
 * @details The function checks the first characters of the line to determine
 * which texture to load. If the line does not match any texture, the function
 * returns -1. Else, the function calls the corresponding function to load the
 * texture.
 * @param map 
 * @param line
 * @return int 1 if the texture is correctly loaded, 0 if an error occurs, 
 * -1 if the line does not match any texture
 */
int	add_texture(t_map_info *map, char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
	{
		if (!add_no_texture(line, map))
			return (0);
		return (1);
	}
	else if (ft_strncmp(line, "SO ", 3) == 0)
	{
		if (!add_so_texture(line, map))
			return (0);
		return (1);
	}
	else if (ft_strncmp(line, "WE ", 3) == 0)
	{
		if (!add_we_texture(line, map))
			return (0);
		return (1);
	}
	else if (ft_strncmp(line, "EA ", 3) == 0)
	{
		if (!add_ea_texture(line, map))
			return (0);
		return (1);
	}
	return (-1);
}

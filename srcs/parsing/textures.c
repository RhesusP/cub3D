/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/24 20:18:48 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	add_no_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->no_texture->is_init)
		return (print_error("double definition of a texture (NO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0, 0));
	if (!load_texture(map, map->no_texture, path))
	{
		free(path);
		return (0);
	}
	map->no_texture->is_init = 1;
	free(path);
	return (1);
}

int	add_so_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->so_texture->is_init)
		return (print_error("double definition of a texture (SO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0, 0));
	if (!load_texture(map, map->so_texture, path))
	{
		free(path);
		return (0);
	}
	map->so_texture->is_init = 1;
	free(path);
	return (1);
}

int	add_ea_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->ea_texture->is_init)
		return (print_error("double definition of a texture (EA)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0, 0));
	if (!load_texture(map, map->ea_texture, path))
	{
		free(path);
		return (0);
	}
	map->ea_texture->is_init = 1;
	free(path);
	return (1);
}

int	add_we_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->we_texture->is_init)
		return (print_error("double definition of a texture (WE)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnls(&line[i]);
	if (!path)
		return (print_error("malloc failed\n", 0, 0));
	if (!load_texture(map, map->we_texture, path))
	{
		free(path);
		return (0);
	}
	map->we_texture->is_init = 1;
	free(path);
	return (1);
}

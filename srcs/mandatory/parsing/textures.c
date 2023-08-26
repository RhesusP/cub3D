/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:41:59 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/16 22:28:31 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	add_no_texture(char *line, t_map_info *map)
{
	int		i;
	char	*path;

	if (map->no_texture->img)
		return (print_error("double definition of a texture (NO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnl(&line[i]);
	load_texture(map, map->no_texture, path);
	free(path);
	return (1);
}

int	add_so_texture(char *line, t_map_info *map)
{
	int	i;
	char	*path;

	if (map->so_texture->img)
		return (print_error("double definition of a texture (SO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnl(&line[i]);
	load_texture(map, map->so_texture, path);
	free(path);
	return (1);
}

int	add_ea_texture(char *line, t_map_info *map)
{
	int	i;
	char	*path;

	if (map->ea_texture->img)
		return (print_error("double definition of a texture (EA)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnl(&line[i]);
	load_texture(map, map->ea_texture, path);
	free(path);
	return (1);
}

int	add_we_texture(char *line, t_map_info *map)
{
	int	i;
	char	*path;

	if (map->we_texture->img)
		return (print_error("double definition of a texture (WE)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	path = ft_strdup_wnl(&line[i]);
	load_texture(map, map->we_texture, path);
	free(path);
	return (1);
}

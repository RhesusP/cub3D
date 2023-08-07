/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:29 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:37:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	add_no_texture(char *line, t_map_info *map)
{
	int	i;

	if (map->no_texture)
		return (print_error("double definition of a texture (NO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	map->no_texture = ft_strdup(&line[i]);
	return (1);
}

int	add_so_texture(char *line, t_map_info *map)
{
	int	i;

	if (map->so_texture)
		return (print_error("double definition of a texture (SO)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	map->so_texture = ft_strdup(&line[i]);
	return (1);
}

int	add_ea_texture(char *line, t_map_info *map)
{
	int	i;

	if (map->ea_texture)
		return (print_error("double definition of a texture (EA)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	map->ea_texture = ft_strdup(&line[i]);
	return (1);
}

int	add_we_texture(char *line, t_map_info *map)
{
	int	i;

	if (map->we_texture)
		return (print_error("double definition of a texture (WE)\n", 0, 0));
	i = 2;
	while (line[i] == ' ')
		i++;
	map->we_texture = ft_strdup(&line[i]);
	return (1);
}

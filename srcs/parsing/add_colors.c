/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/10 19:44:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	add_floor_color(char *line, t_map_info *map)
{
	int	i;

	if (map->floor_color != -1)
		return (print_error("double definition of a color (F)\n", 0, 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	map->floor_color = create_mlx_color(0, 100, 100, 100);
	return (1);
}

int	add_ceiling_color(char *line, t_map_info *map)
{
	int	i;

	if (map->ceiling_color != -1)
		return (print_error("double definition of a color (F)\n", 0, 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	map->ceiling_color = create_mlx_color(0, 82, 157, 229);
	return (1);
}

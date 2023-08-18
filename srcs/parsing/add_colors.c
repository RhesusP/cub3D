/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/18 12:50:07 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"


int	check_color(char *str)
{
	char	*temp;
	int		i;
	int		col;

	temp = ft_strdup_wnls(str);
	i = 0;
	while (temp[i] != '\0')
	{
		if (!(ft_isdigit(temp[i]) || temp[i] == '+' || temp[i] == '-' || temp[i] == ' '))
		{
			free(temp);
			return (print_error("invalid character in color\n", 0, -1));
		}
		i++;
	}
	col = ft_atoi(temp);
	free(temp);
	return (col);
}

int	ft_get_color(char *str)
{
	int r;
	int g;
	int b;
	int		i;
	char	**split;

	split = ft_split(str, ',');
	i = 0;
	while (split[i])
	{
		if (i == 0)
			r = check_color(split[i]);
		else if (i == 1)
			g = check_color(split[i]);
		else if (i == 2)
			b = check_color(split[i]);
		else
			return (print_error("invalid caracter detected\n", 0, 0));		// TODO free memory
		free(split[i]);
		i++;
	}
	free(split);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_error("color is out of range [0, 255]\n", 0, -1));
	return (create_mlx_color(0, r, g, b));
}

int	add_floor_color(char *line, t_map_info *map)
{
	int	i;
	int	col;

	if (map->floor_color != -1)
		return (print_error("double definition of a color (F)\n", 0, 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	col = ft_get_color(&line[i]);
	if (col < 0)
		return (0);
	map->floor_color = col;
	return (1);
}

int	add_ceiling_color(char *line, t_map_info *map)
{
	int	i;
	int	col;

	if (map->ceiling_color != -1)
		return (print_error("double definition of a color (C)\n", 0, 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	col = ft_get_color(&line[i]);
	if (col < 0)
		return (0);
	map->ceiling_color = col;
	return (1);
}

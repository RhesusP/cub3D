/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:40:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

static int	check_color_syntax(char *str)
{
	char	*temp;
	int		i;
	int		col;

	temp = ft_strdup_wnls(str);
	i = 0;
	while (temp[i] != '\0')
	{
		if (!(ft_isdigit(temp[i]) || temp[i] == '+' || temp[i] == '-' || \
			temp[i] == ' '))
		{
			free(temp);
			return (print_error("invalid character in color\n", -1));
		}
		i++;
	}
	col = ft_atoi(temp);
	free(temp);
	return (col);
}

static int	ft_get_color(char *str)
{
	int		r;
	int		g;
	int		b;
	int		i;
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		return (print_error("malloc failed\n", -1));
	i = -1;
	while (split[++i])
	{
		if (i == 0)
			r = check_color_syntax(split[i]);
		else if (i == 1)
			g = check_color_syntax(split[i]);
		else if (i == 2)
			b = check_color_syntax(split[i]);
		else
			return (free_allocated_array(&split, 1));
	}
	free_allocated_array(&split, 0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_error("color is out of range [0, 255]\n", -1));
	return (create_mlx_color(0, r, g, b));
}

static int	add_floor_color(char *line, t_map_info *map)
{
	int	i;
	int	col;

	if (map->floor_color != -1)
		return (print_error("double definition of a color (F)\n", 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	col = ft_get_color(&line[i]);
	if (col < 0)
		return (0);
	map->floor_color = col;
	return (1);
}

static int	add_ceiling_color(char *line, t_map_info *map)
{
	int	i;
	int	col;

	if (map->ceiling_color != -1)
		return (print_error("double definition of a color (C)\n", 0));
	i = 1;
	while (line[i] == ' ')
		i++;
	col = ft_get_color(&line[i]);
	if (col < 0)
		return (0);
	map->ceiling_color = col;
	return (1);
}

int	add_color(t_map_info *map, char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
	{
		if (!add_floor_color(line, map))
			return (0);
		return (1);
	}
	else if (ft_strncmp(line, "C ", 2) == 0)
	{
		if (!add_ceiling_color(line, map))
			return (0);
		return (1);
	}
	return (-1);
}

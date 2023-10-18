/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:32:12 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/18 15:54:12 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Checks if the color syntax is valid.
 * @details The color syntax is valid if it contains only digits, spaces and 
 * signs.
 * @param str 
 * @return int atoi of the color if the syntax is valid, -1 otherwise
 */
static int	check_color_syntax(char *str)
{
	char	*temp;
	int		i;
	int		col;

	i = 0;
	while (str[i] == ' ')
		i++;
	if (ft_strlen_wnl(&str[i]) == 0)
		return (-1);
	temp = ft_strdup_wnls(&str[i]);
	i = 0;
	while (temp[i] != '\0' && ft_isdigit(temp[i]))
		i++;
	while (temp[i] != '\0')
	{
		if (temp[i] != ' ')
		{
			free(temp);
			return (-1);
		}
		i++;
	}
	col = ft_atoi(temp);
	free(temp);
	return (col);
}

/**
 * @brief Transforms a string with the "R,G,B" format into a mlx color.
 * @details The string is split with the ',' character. The first part is the
 * red value, the second part is the green value and the third part is the blue
 * value. If the string doesn't contain exactly three parts, if the syntax is 
 * invalid or if the color is out of range, the function returns -1.
 * @param str 
 * @return int mlx color if the string is correctly parsed, -1 otherwise
 */
static int	ft_get_color(char *str)
{
	int		r;
	int		g;
	int		b;
	char	**split;

	split = ft_split(str, ',');
	if (!split)
		return (print_error("malloc failed\n", -1));
	if (ft_char_array_len(split) != 3)
	{
		free_allocated_array(&split, 0);
		return (print_error("invalid color format\n", -1));
	}
	r = check_color_syntax(split[0]);
	g = check_color_syntax(split[1]);
	b = check_color_syntax(split[2]);
	free_allocated_array(&split, 0);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		return (print_error("invalid color\n", -1));
	return (create_mlx_color(0, r, g, b));
}

/**
 * @brief Adds the floor color described in the line to the map structure.
 * 
 * @param line 
 * @param map 
 * @return int 1 if the color is correctly added, 0 if an error occurs
 */
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

/**
 * @brief Adds the ceiling color described in the line to the map structure.
 * 
 * @param line 
 * @param map 
 * @return int 1 if the color is correctly added, 0 if an error occurs
 */
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

/**
 * @brief Adds the color described in the line to the map structure.
 * 
 * @param map 
 * @param line 
 * @return int 1 if the color is correctly added, 0 if an error occurs.
 */
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:15:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/10/18 15:23:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Search textures and colors in the given line.
 * @details If the line is a texture description, the texture is loaded and 
 * stored in the map structure. If the line is a color description, the color 
 * is stored in the map structure. If an unexpected character is found, the 
 * function returns 0.
 * @param line 
 * @param map 
 * @return int 1 if the line is correctly parsed, 0 if an error occured.
 */
static int	get_line(char *line, t_map_info *map)
{
	static int	max_width = 0;
	static int	height = 0;
	int			add_t;
	int			add_c;

	if (!line || line[0] == '\0' || line[0] == '\n')
		return (1);
	add_t = add_texture(map, line);
	if (add_t == 1 || add_t == 0)
		return (add_t);
	add_c = add_color(map, line);
	if (add_c == 1 || add_c == 0)
		return (add_c);
	else if (text_col_complete(map) && is_desc_char_valid(line[0]))
	{
		height++;
		if ((int)ft_strlen_wnl(line) > max_width)
			max_width = ft_strlen_wnl(line);
	}
	else
		return (print_error("invalid character found in file\n", 0));
	map->map_height = height + 1;
	map->map_width = max_width;
	return (1);
}

/**
 * @brief Fills a row of the map array with the map description.
 * @details Every character of the line is checked and stored in the map array.
 * If the line is shorter than the map width, the remaining characters are filled
 * with spaces.
 * @param line
 * @param map 
 * @param row 
 * @return int 1 if the row is correctly filled, 0 if an error occured 
 */
static int	fill_map_row(char *line, t_map_info *map, int row)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'\
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			map->map[row][i] = line[i];
		else
			return (print_error("invalid character in map description\n", 0));
		i++;
	}
	while (i < map->map_width)
	{
		map->map[row][i] = ' ';
		i++;
	}
	map->map[row][i] = '\0';
	return (1);
}

/**
 * @brief Fills the map array with the map description.
 * 
 * @param map_path 
 * @param map 
 * @return int 1 if the map array is correctly filled, 0 if an error occured
 */
static int	fill_map_array(char *map_path, t_map_info *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (print_error("unable to open map\n", 0));
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (is_map_desc(line))
		{
			if (!fill_map_row(line, map, i))
			{
				free(line);
				return (close(fd));
			}
			i++;
		}
		free(line);
	}
	close(fd);
	return (1);
}

/**
 * @brief Browses the map file searching for map description lines 
 * (C, F, NO, SO, WE, EA).
 * @param map_path 
 * @param map 
 * @return int 1 if the map is correctly scanned, 0 if an error occured
 */
static int	scan_map(char *map_path, t_map_info *map)
{
	int		fd;
	char	*line;
	int		err;

	err = 0;
	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (print_error("unable to open map\n", 0));
	if (!init_void_map(map))
		return (0);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!err && !get_line(line, map))
			err = 1;
		free(line);
	}
	close(fd);
	if (err)
		return (free_allocated_text(map));
	return (1);
}

/**
 * @brief Parses the map description and stores it in the map structure.
 * @details The function scans the map description and stores it in a 2D 
 * char array. The map description is checked for errors and the player 
 * position and orientation are stored in the map structure. Textures 
 * and colors are also checked and stored in the map structure.
 * @param map_path
 * @param map
 * @return int 1 if the map is correctly parsed, 0 if an error occured
 */
int	parse_map(char *map_path, t_map_info *map)
{
	if (!scan_map(map_path, map))
		return (0);
	if (!init_map_array(map, map->map_height, map->map_width))
		return (free_allocated_text(map));
	if (fill_map_array(map_path, map) <= 0)
	{
		free_allocated_array(&map->map, 0);
		return (free_allocated_text(map));
	}
	if (!map_have_one_player(map->map))
	{
		free_allocated_array(&map->map, 0);
		return (free_allocated_text(map));
	}
	if (!is_map_closed(map->map))
	{
		free_allocated_array(&map->map, 0);
		return (free_allocated_text(map));
	}
	get_start_pos(map);
	return (1);
}

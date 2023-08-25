/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:15:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 00:53:40 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

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
		return (print_error("invalid character found in map\n", 0));
	map->map_height = height;
	map->map_width = max_width;
	return (1);
}

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
	get_start_pos(map);
	return (1);
}

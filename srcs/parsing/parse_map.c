/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:15:19 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 22:09:33 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	get_line(char *line, t_map_info *map)
{
	static int	max_width = 0;
	static int	height = 0;

	if (!line || line[0] == '\0' || line[0] == '\n')
		return (1);
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
		return(1);
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
	else if (ft_strncmp(line, "F ", 2) == 0)
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
	else if (text_col_complete(map) && is_desc_char_valid(line[0]))
	{
		// TODO precise error "map is not last"
		height++;
		if ((int)ft_strlen_wnl(line) > max_width)
			max_width = ft_strlen_wnl(line);
	}
	else
		return (print_error("invalid character found in map\n", 0, 0));
	map->map_height = height;
	map->map_width = max_width;
	return (1);
}

int	fill_map_row(char *line, t_map_info *map, int row)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '1' || line[i] == '0' || line[i] == 'N'\
		|| line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			map->map[row][i] = line[i];
		else
			return (print_error("invalid character in map description\n", 0, 0));
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

int	fill_map_array(char *map_path, t_map_info *map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		print_error("", 1, 0);
	line = "";
	i = 0;
	while (line)
	{
		line = get_next_line(fd);
		if (is_map_desc(line))
		{
			if (!fill_map_row(line, map, i))
			{
				printf("fill return 0\n");
				return (0);
			}
			i++;
		}
		free(line);
	}
	close(fd);
	return (1);
}

int	parse_map(char *map_path, t_map_info *map)
{
	int		fd;
	char	*line;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (print_error("unable to open map\n", 0, 0));
	if (!init_void_map(map))
		return (0);
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!get_line(line, map))
			return (0);
		free(line);
	}
	close(fd);
	init_map_array(map, map->map_height, map->map_width);
	fill_map_array(map_path, map);
	if (!map_have_one_player(map->map))
		return (0);
	get_start_pos(map);
	return (1);
}

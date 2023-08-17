/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:12:56 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/16 12:28:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	init_void_map(t_map_info *map)
{
	map->no_texture = malloc(sizeof(t_text));
	map->so_texture = malloc(sizeof(t_text));
	map->ea_texture = malloc(sizeof(t_text));
	map->we_texture = malloc(sizeof(t_text));
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_width = 0;
	map->map_height = 0;
	map->sprite_texture = NULL;
	map->map = NULL;
	map->player.map_pos.x = 0;
	map->player.map_pos.y = 0;
	map->player.mini_pos.x = 0;
	map->player.mini_pos.y = 0;
	map->player.dir = 0;
}

int	init_map_array(t_map_info *map, int height, int width)
{
	int	i;

	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		return (print_error("malloc error\n", 0, 0));
	map->map[height] = NULL;
	i = 0;
	while (i < height)
	{
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
			return (print_error("malloc error\n", 0, 0));
		map->map[i][width] = '\0';
		i++;
	}
	return (1);
}

int	is_map_desc(char *line)
{
	if (!line || line[0] == '\0' || line[0] == '\n')
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (0);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (0);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (0);
	else
		return (1);
}

/**
 * @brief [DEBUG FUNCTION] Print the map info structure
 * 
 * @param map 
 */
void	debug_print_map(t_map_info *map)
{
	int i;
	
	if (map->floor_color == -1)
		printf("Floor color: UNDEFINED\n");
	else
		printf("Floor color: %d\n", map->floor_color);
	if (map->ceiling_color == -1)
		printf("Ceiling color: UNDEFINED\n");
	else
		printf("Ceiling color: %d\n", map->ceiling_color);
	printf("Width: %d\n", map->map_width);
	printf("Height: %d\n", map->map_height);
	printf("map: \n");
	i = 0;
	while (map->map[i])
	{
		printf("%s\n", map->map[i]);
		i++;
	}
	printf("Player in map: (%d, %d)\n", map->player.map_pos.x, map->player.map_pos.x);
	printf("Player in minimap: (%d, %d)\n", map->player.mini_pos.x, map->player.mini_pos.x);
	printf("Player direction: %f rad --> %f deg\n", map->player.dir, map->player.dir * 180 / M_PI);
}
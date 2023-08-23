/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:12:56 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 13:00:34 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	is_desc_char_valid(char c)
{
	if (c == ' ' || c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

int	init_void_map(t_map_info *map)
{
	map->no_texture = malloc(sizeof(t_text));
	if (!map->no_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->so_texture = malloc(sizeof(t_text));
	if (!map->so_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->ea_texture = malloc(sizeof(t_text));
	if (!map->ea_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->we_texture = malloc(sizeof(t_text));
	if (!map->we_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->floor_color = -1;
	map->ceiling_color = -1;
	map->map_width = 0;
	map->map_height = 0;
	map->map = NULL;
	map->player.map_pos.x = 0;
	map->player.map_pos.y = 0;
	map->player.mini_pos.x = 0;
	map->player.mini_pos.y = 0;
	map->player.dir = 0;
	return (1);
}

int	init_map_array(t_map_info *map, int height, int width)
{
	int	i;

	map->map = malloc(sizeof(char *) * (height + 1));
	if (!map->map)
		return (print_error("malloc failed\n", 0, 0));
	map->map[height] = NULL;
	i = 0;
	while (i < height)
	{
		map->map[i] = malloc(sizeof(char) * (width + 1));
		if (!map->map[i])
			return (print_error("malloc failed\n", 0, 0));
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

void	debug_print_texture_fields(t_text *t)
{
	// img
	printf("img: ");
	if (!t->img)
		printf("null\n");
	else
		printf("%p\n", t->img);
	
	// addr
	printf("addr: ");
	if (!t->addr)
		printf("null\n");
	else
		printf("%p\n", t->addr);
	
	// bits_per_pixel
	printf("bits_per_pixel: ");
	if ((!t->bits_per_pixel))
		printf("null\n");
	else
		printf("%d\n", t->bits_per_pixel);
	
	// line_lenght
	printf("line_lenght: ");
	if ((!t->line_length))
		printf("null\n");
	else
		printf("%d\n", t->line_length);

	// endian
	printf("endian: ");
	if ((!t->endian))
		printf("null\n");
	else
		printf("%d\n", t->endian);

	// width
	printf("width: ");
	if ((!t->width))
		printf("null\n");
	else
		printf("%d\n", t->width);

	// height
	printf("height: ");
	if ((!t->height))
		printf("null\n");
	else
		printf("%d\n", t->height);
}

//TODO delete before push
void	debug_print_map_fields(t_map_info *map)
{
	printf("---- no_texture ----\n");
	debug_print_texture_fields(map->no_texture);
	printf("---- so_texture ----\n");
	debug_print_texture_fields(map->so_texture);
	printf("---- ea_texture ----\n");
	debug_print_texture_fields(map->ea_texture);
	printf("---- we_texture ----\n");
	debug_print_texture_fields(map->we_texture);
	printf("---- colors ----\n");
	printf("floor: %d\n", map->floor_color);
	printf("ceil: %d\n", map->ceiling_color);
}

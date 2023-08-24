/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:12:56 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 21:47:25 by cbernot          ###   ########.fr       */
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
	map->no_texture->is_init = 0;
	map->so_texture = malloc(sizeof(t_text));
	if (!map->so_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->so_texture->is_init = 0;
	map->ea_texture = malloc(sizeof(t_text));
	if (!map->ea_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->ea_texture->is_init = 0;
	map->we_texture = malloc(sizeof(t_text));
	if (!map->we_texture)
		return (print_error("malloc failed\n", 0, 0));
	map->we_texture->is_init = 0;
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
	map->frame = 0;
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

int	free_map(t_map_info *map)
{
	int	i;
	free(map->frame);
	i = 0;
	while (i < map->map_height)
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	mlx_destroy_image(map->mlx, map->no_texture->img);
	mlx_destroy_image(map->mlx, map->so_texture->img);
	mlx_destroy_image(map->mlx, map->ea_texture->img);
	mlx_destroy_image(map->mlx, map->we_texture->img);
	free(map->no_texture);
	free(map->so_texture);
	free(map->ea_texture);
	free(map->we_texture);
	mlx_destroy_image(map->mlx, map->mlx_img.img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

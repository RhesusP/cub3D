/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 11:35:43 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 04:41:32 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Frees map structure, mlx pointers and exits the program.
 * @param map 
 * @return int
 */
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
	if (map->mlx_img.img)
		mlx_destroy_image(map->mlx, map->mlx_img.img);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

/**
 * @brief Frees an allocated array.
 * @details If is_err is set to 1, the function prints the "invalid 
 * caracter detected" error message
 * @param array address of the array to free
 * @param is_err 1 if the function is called after an error, 0 otherwise
 * @return int -1 if is_err is set to 1, 0 otherwise
 */
int	free_allocated_array(char ***array, int is_err)
{
	int	i;

	if (*array == NULL)
		return (0);
	i = 0;
	while ((*array)[i])
	{
		free((*array)[i]);
		i++;
	}
	free(*array);
	if (is_err)
		return (print_error("invalid caracter detected\n", -1));
	return (0);
}

/**
 * @brief Frees allocated textures.
 * 
 * @param map 
 * @return int 
 */
int	free_allocated_text(t_map_info *map)
{
	if (map->no_texture->is_init)
	{
		mlx_destroy_image(map->mlx, map->no_texture->img);
		free(map->no_texture);
	}
	if (map->so_texture->is_init)
	{
		mlx_destroy_image(map->mlx, map->so_texture->img);
		free(map->so_texture);
	}
	if (map->ea_texture->is_init)
	{
		mlx_destroy_image(map->mlx, map->ea_texture->img);
		free(map->ea_texture);
	}
	if (map->we_texture->is_init)
	{
		mlx_destroy_image(map->mlx, map->we_texture->img);
		free(map->we_texture);
	}
	return (0);
}

/**
 * @brief Frees a partial array.
 * @details The function frees the array until the last_alloc index.
 * It is useful for a failed allocated 2d array.
 * @param array 
 * @param last_alloc index of the last allocated element
 */
void	free_partial_array(char ***array, int last_alloc)
{
	int	i;

	i = 0;
	while (i < last_alloc)
	{
		free(*(array[i]));
		i++;
	}
	free(*array);
}

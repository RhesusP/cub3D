/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:25:31 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:42:06 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_map_info	map;

	if (argc != 2)
		return (print_error("Usage: ./cub3D path_to_map\n", EXIT_FAILURE));
	if (!is_file_extension_correct(argv[1]))
		return (print_error("Wrong file extension\n", EXIT_FAILURE));
	map.mlx = mlx_init();
	if (!map.mlx)
		return (print_error("mlx_init() failed\n", EXIT_FAILURE));
	map.mlx_win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "cub3D");
	if (!map.mlx_win)
	{
		mlx_destroy_display(map.mlx);
		free(map.mlx);
		return (print_error("mlx_new_window() failed\n", EXIT_FAILURE));
	}
	if (!parse_map(argv[1], &map))
	{
		mlx_destroy_window(map.mlx, map.mlx_win);
		mlx_destroy_display(map.mlx);
		free(map.mlx);
		return (EXIT_FAILURE);
	}
	game_loop(&map);
	return (0);
}

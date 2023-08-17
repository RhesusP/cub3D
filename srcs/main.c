/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:25:31 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/16 12:32:03 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	print_error(char *str, int use_perror, int exit_status)
{
	if (use_perror)
		perror("\033[31mError\033[39m\n");
	else
	{
		ft_putstr_fd("\033[31mError\033[39m\n", 2);
		ft_putstr_fd(str, 2);
	}
	return (exit_status);
}

int	is_file_extension_correct(char *filename)
{
	int	i;

	i = 0;
	while (filename[i])
		i++;
	if (i < 5)
		return (0);
	if (filename[i - 1] != 'b' || filename[i - 2] != 'u'
		|| filename[i - 3] != 'c' || filename[i - 4] != '.')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_map_info	map;

	if (argc != 2)
		return (print_error("Wrong number of arguments\n", 0, EXIT_FAILURE));
	if (!is_file_extension_correct(argv[1]))
		return (print_error("Wrong file extension\n", 0, EXIT_FAILURE));
	map.mlx = mlx_init();
	if (!map.mlx)
		print_error("mlx_init() failed\n", 0, EXIT_FAILURE);
	map.mlx_win = mlx_new_window(map.mlx, WIDTH, HEIGHT, "cub3D");
	if (!parse_map(argv[1], &map))
		return (EXIT_FAILURE);
	start_mlx(&map);
	return (0);
}

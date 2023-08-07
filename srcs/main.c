/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:25:31 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:50:51 by cbernot          ###   ########.fr       */
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

/**
 * @brief WIP (not working correctly yet)
 * 
 * @param map 
 */
void	start_mlx(t_map_info *map)
{
	t_mlx_data	img;
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	if (!mlx)
		print_error("mlx_init() failed\n", 0, EXIT_FAILURE);
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "cub3D");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw_minimap(map, &img);

	// map->player_or = M_PI_4;

	int	i;
	double	ray_angle = map->player_or + HALF_FOV;
	printf("ray_angle: %f\n", ray_angle);
	map->frame = malloc(sizeof(t_frame) * WIDTH);
	if (!map->frame)
		print_error("malloc() failed\n", 0, EXIT_FAILURE);
	i = 0;
	while (i < WIDTH)
	{
		map->frame[i].angle = ray_angle;
		map->frame[i].distance = find_wall(map, ray_angle);
		printf("map->frame[%d].distance: %f\n", i, map->frame[i].distance);
		map->frame[i].height = ceil(CUBE_SIZE / map->frame[i].distance * PROJECTION_DISTANCE);
		ray_angle -= (60.0 / WIDTH) * (M_PI / 180.0);
		i++;
	}

	i = 0;
	while (i < WIDTH)
	{
		draw_slice(map, &img, i);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

int	main(int argc, char **argv)
{
	t_map_info	map;
	
	if (argc != 2)
		return (print_error("Wrong number of arguments\n", 0, EXIT_FAILURE));
	if (!is_file_extension_correct(argv[1]))
		return (print_error("Wrong file extension\n", 0, EXIT_FAILURE));
	if (!parse_map(argv[1], &map))
		return (EXIT_FAILURE);
	start_mlx(&map);
	
	return (0);
}

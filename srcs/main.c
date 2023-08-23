/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:25:31 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 13:58:39 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_free_settings(t_settings *settings)
{
	free(settings->north_texture);
	free(settings->south_texture);
	free(settings->east_texture);
	free(settings->west_texture);
	free(settings->sprite_texture);
	free(settings);
}

int	print_error(char *str)
{
	ft_putstr_fd("\033[31mError\033[39m\n", 2);
	ft_putstr_fd(str, 2);
	return (EXIT_FAILURE);
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

int	check_input(int argc, char **argv)
{
	if (argc != 2)
		return (print_error("Wrong number of arguments\n"));
	if (!is_file_extension_correct(argv[1]))
		return (print_error("Wrong file extension\n"));
	return (0);
}

int	main(int argc, char **argv)
{
	t_rsc	*rsc;
	int		fd;

	if (check_input(argc, argv))
		return (EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	rsc = parse_file(fd);
	if (!rsc)
		return (print_error("Parsing error\n"));
	/*if (fd == -1)
		return (perror("open :"));*/
	ft_free_settings(rsc->settings);
	free(rsc);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:40:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 13:02:15 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Prints an error message and returns the exit status.
 * 
 * @param str error message
 * @param exit_status 
 * @return int exit_status given in parameter
 */
int	print_error(char *str, int exit_status)
{
	ft_putstr_fd("\033[31mError\033[39m\n", 2);
	ft_putstr_fd(str, 2);
	return (exit_status);
}

/**
 * @brief Checks if the file extension is .cub
 * 
 * @param filename 
 * @return int 1 if the file extension is .cub, 0 otherwise
 */
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

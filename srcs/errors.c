/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 21:40:57 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/23 21:41:31 by cbernot          ###   ########.fr       */
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

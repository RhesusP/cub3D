/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:58:10 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:53:38 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief Print a char and return -1 if an error occurs.
 */
int	ft_print_char(unsigned char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

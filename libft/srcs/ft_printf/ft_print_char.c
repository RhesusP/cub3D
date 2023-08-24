/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 19:58:10 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/24 18:43:39 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/**
 * @brief Print a char and return -1 if an error occurs.
 */
int	ft_print_char(unsigned char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

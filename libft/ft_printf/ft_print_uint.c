/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_uint.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:56:35 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:53:55 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/**
 * @brief The same as `ft_print_int`... but for unsigned int.
 */
int	ft_print_uint(unsigned int nb)
{
	int	len;
	int	temp;

	len = 0;
	if (nb >= 10)
	{
		temp = ft_print_int(nb / 10);
		if (temp == -1)
			return (-1);
		len += temp;
		if (ft_print_char((nb % 10) + '0') == -1)
			return (-1);
		len += 1;
	}
	else
	{
		if (ft_print_char(nb + '0') == -1)
			return (-1);
		len += 1;
	}
	return (len);
}

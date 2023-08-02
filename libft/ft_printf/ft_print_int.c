/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 22:40:12 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:53:46 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_handle_intmin(void)
{
	if (ft_print_str("-2147483648") == -1)
		return (-1);
	return (11);
}

static int	ft_handle_neg(int nb, int *len)
{
	int	temp;

	if (ft_print_char('-') == -1)
		return (-1);
	*len += 1;
	nb *= -1;
	temp = ft_print_int(nb);
	if (temp == -1)
		return (-1);
	*len += temp;
	return (*len);
}

/**
 * @brief Print an integer in base 10.
 */
int	ft_print_int(int nb)
{
	int	len;
	int	temp;

	len = 0;
	if (nb == -2147483648)
		return (ft_handle_intmin());
	if (nb < 0)
		return (ft_handle_neg(nb, &len));
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

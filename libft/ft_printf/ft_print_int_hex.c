/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_hex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 23:28:22 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:53:43 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_display_nb(long nb, char *base, int base_size)
{
	long	reste;
	int		printed_len;
	int		temp;

	printed_len = 0;
	if (nb < 0)
		nb = 4294967295 - (nb * -1) + 1;
	reste = nb % base_size;
	nb = nb / base_size;
	if (nb > 0)
	{
		temp = ft_display_nb(nb, base, base_size);
		if (temp == -1)
			return (-1);
		printed_len += temp;
	}
	temp = ft_print_char(base[reste]);
	if (temp == -1)
		return (-1);
	printed_len += temp;
	return (printed_len);
}

/**
 * @brief Print an integer in a given base. Here, -1 is returned 
 * if an error occurs.
 */
int	ft_print_int_base(long nbr, char *base)
{
	int	base_size;
	int	len;

	base_size = 0;
	while (base[base_size])
		base_size++;
	len = ft_display_nb(nbr, base, base_size);
	if (len == -1)
		return (-1);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:07:09 by cbernot           #+#    #+#             */
/*   Updated: 2022/12/17 14:53:49 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_display_nb(unsigned long long nb, char *base, int base_size)
{
	long long	reste;
	int			printed_len;
	int			temp;

	printed_len = 0;
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

int	ft_print_ptr(unsigned long long nbr)
{
	char	*base;
	int		base_size;
	int		printed_len;
	int		temp;

	base = "0123456789abcdef";
	if (nbr == 0)
	{
		if (write(1, "0x0", 3) == -1)
			return (-1);
		return (3);
	}
	base_size = 0;
	while (base[base_size])
		base_size++;
	printed_len = 0;
	if (ft_print_str("0x") == -1)
		return (-1);
	printed_len += 2;
	temp = ft_display_nb(nbr, base, base_size);
	if (temp == -1)
		return (-1);
	return (printed_len + temp);
}

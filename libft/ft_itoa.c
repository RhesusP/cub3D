/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:11:25 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 18:45:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n *= -1;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_minint_case(void)
{
	char	*res;

	res = malloc(sizeof(char) * (12));
	if (!res)
		return (0);
	ft_strlcpy(res, "-2147483648", 12);
	return (res);
}

static char	*ft_itoa2(int n, int len, char *res)
{
	int	i;
	int	offset;

	offset = 0;
	i = 0;
	if (n == 0)
	{
		ft_strlcpy(res, "0", 2);
		return (res);
	}
	if (n < 0)
	{
		res[0] = '-';
		offset = 1;
		n *= -1;
	}
	while (n > 0)
	{
		res[len - 1 - i] = (n % 10) + '0';
		n = n / 10;
		i++;
	}
	res[i + offset] = '\0';
	return (res);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*res;

	len = ft_nbrlen(n);
	if (n == -2147483648)
		return (ft_minint_case());
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res = ft_itoa2(n, len, res);
	return (res);
}

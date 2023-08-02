/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:08:36 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/11 23:13:32 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)(s);
	i = 0;
	while (i < n)
	{
		if (ptr[i] == (unsigned char)(c))
			return (&ptr[i]);
		i++;
	}
	return ((void *)(0));
}

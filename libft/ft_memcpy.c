/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 16:45:26 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 16:39:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dst_clone;
	char	*src_clone;

	if (!dst && !src)
		return (0);
	dst_clone = (char *)(dst);
	src_clone = (char *)(src);
	i = 0;
	while (i < n)
	{
		dst_clone[i] = src_clone[i];
		i++;
	}
	return (dst);
}

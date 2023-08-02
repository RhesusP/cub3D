/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:25:15 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 18:12:53 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	k;
	size_t	len_src;

	if (dstsize == 0)
		return (ft_strlen(src));
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (dstsize < len_dest)
		return (dstsize + len_src);
	else
		len_src += len_dest;
	k = 0;
	while (src[k] != '\0' && (len_dest + k) < dstsize - 1)
	{
		dst[len_dest + k] = src[k];
		k++;
	}
	dst[len_dest + k] = '\0';
	return (len_src);
}

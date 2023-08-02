/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:10:00 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 18:41:37 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (count != 0 && SIZE_MAX / count < size)
		return (0);
	res = malloc(size * count);
	if (!res)
		return (0);
	ft_memset(res, 0, size * count);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:10:00 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/24 18:41:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

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

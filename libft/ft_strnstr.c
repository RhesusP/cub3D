/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 11:28:44 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 17:40:50 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size;
	char	*str;

	size = ft_strlen(needle);
	i = 0;
	str = (char *)haystack;
	if (needle[i] == '\0' || (needle[i] == '\0' && len == 0))
		return (str);
	if (len == 0)
		return (0);
	while (str[i] != '\0' && i < len)
	{
		if (ft_strncmp(&str[i], needle, size) == 0 && i + size <= len)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 12:55:45 by cbernot           #+#    #+#             */
/*   Updated: 2022/11/13 16:50:19 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charinset(char const c, char const *set)
{
	int	i;

	i = 0;
	while ((unsigned char)set[i] != '\0')
	{
		if ((unsigned char)set[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	int		start;
	size_t	len;
	size_t	end;

	if (!s1 || !set)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	while (s1[i] != '\0' && ft_charinset(s1[i], set))
		i++;
	start = i;
	i = ft_strlen(s1) - 1;
	end = 0;
	while (i > 0 && ft_charinset(s1[i], set))
	{
		i--;
		end++;
	}
	return (ft_substr(s1, start, len - start - end));
}

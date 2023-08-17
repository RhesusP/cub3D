/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:33:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/16 12:41:57 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

unsigned int	ft_strlen_wnl(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_strdup_wnl(const char *s1)
{
	char			*res;
	unsigned int	i;

	res = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!res)
		return (res);
	i = 0;
	while (s1[i] != '\0' && s1[i] != '\n')
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

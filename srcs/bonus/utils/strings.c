/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:33:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/26 12:41:14 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

unsigned int	ft_strlen_wnl(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

// without consedering ending \n \0 and ' '
char	*ft_strdup_wnls(const char *s1)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen(s1);
	while (s1[j] == '\0' || s1[j] == '\n' || s1[j] == ' ')
		j--;
	res = malloc(sizeof(char) * (j + 2));
	if (!res)
		return (res);
	i = 0;
	while (i < j + 1)
	{
		res[i] = s1[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

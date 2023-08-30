/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 09:33:38 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 19:37:45 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Returns the length of the string without the ending `\n`
 * 
 * @param str 
 * @return unsigned int 
 */
unsigned int	ft_strlen_wnl(const char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

/**
 * @brief Returns the string without the ending `\n` and spaces.
 * 
 * @param s1 
 * @return char* Allocated string without the ending `\n` and spaces
 */
char	*ft_strdup_wnls(const char *s1)
{
	char			*res;
	unsigned int	i;
	unsigned int	j;

	j = ft_strlen_wnl(s1);
	if (j == 1 && s1[0] == '\n')
		return (ft_strdup(""));
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

int	ft_char_array_len(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
		i++;
	return (i);
}

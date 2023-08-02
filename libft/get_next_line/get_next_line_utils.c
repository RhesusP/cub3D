/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:36:53 by cbernot           #+#    #+#             */
/*   Updated: 2023/07/22 18:55:23 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_free_stash(char **stash, int create_line)
{
	char	*line;

	if (!*stash)
		return (0);
	if (create_line == 0)
	{
		if (*stash)
		{
			free(*stash);
			*stash = 0;
		}
		return (0);
	}
	else if (create_line == 1)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = 0;
		return (line);
	}
	return (0);
}

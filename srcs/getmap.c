/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:49 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/15 20:15:01 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	**init_strs(void)
{
	char	**strs;

	strs = malloc(sizeof(char *) * 1);
	strs[0] = NULL;
	return (strs);
}

char	**strscat(char **strs, char *str)
{
	int		i;
	char	**new;

	i = 0;
	new = malloc(sizeof(char *) * (ft_strslen(strs) + 2));
	while (strs[i])
	{
		new[i] = ft_strdup(strs[i]);
		i++;
	}
	new[i] = ft_strdup(str);
	new[i + 1] = NULL;
	return (new);
}

void	print_raw_map(char **raw)
{
	int	i;

	i = 0;
	while (raw[i])
	{
		ft_printf("%s\n", raw[i]);
		i++;
	}
}

t_map	*get_raw_map(int fd)
{
	t_map	*map;
	char	**raw;
	char	*line;

	raw = init_strs();
	(void)map;
	line = get_next_data(fd);
	while (line)
	{
		raw = strscat(raw, line);
		free(line);
		line = get_next_data(fd);
	}
	print_raw_map(raw);
	return (NULL);
}

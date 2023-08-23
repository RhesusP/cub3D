/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 15:38:49 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/23 15:34:09 by svanmeen         ###   ########.fr       */
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

void	fill(t_map *map, char **raw, int width)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (raw[i])
	{
		j = 0;
		while (raw[i][j])
		{
			if (raw[i][j] == '\n')
			{
				while (j != width)
				{
					map[k].x = i;
					map[k].y = j;
					map[k].val = ' ';
					k++;
					j++;
				}
			}
			else
			{
			map[k].x = i;
			map[k].y = j;
			map[k].val = raw[i][j];
			k++;
			j++;
			}
		}
		i++;
	}
	map[k].x = -1;
	map[k].y = -1;
	map[k].val = -1;
}

int	get_width(char **raw)
{
	int	i;
	int	j;
	int	width;

	i = 0;
	width = 0;
	while (raw[i])
	{
		j = 0;
		while (raw[i][j])
			j++;
		if (j > width)
			width = j;
		i++;
	}
	return (width);
}

int	get_heigh(char **raw)
{
	int	i;

	i = 0;
	while (raw[i])
		i++;
	return (i);
}

t_map	*get_raw_map(int fd, t_rsc *rsc)
{
	t_map	*map;
	char	**raw;
	char	*line;
//	int		nb_pts;

	raw = init_strs();
	(void)map;
	line = get_next_data(fd);
	while (line)
	{
		raw = strscat(raw, line);
		free(line);
		line = get_next_data(fd);
	}
	rsc->settings->map_width = get_width(raw);
	rsc->settings->map_heigh = get_heigh(raw);
	map = malloc(sizeof(t_map) * (get_heigh(raw) * get_width(raw) + 1));
	if (!map)
		return (NULL);
	fill(map, raw, rsc->settings->map_width);
	free(raw);
	return (map);
}

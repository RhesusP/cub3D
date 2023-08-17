/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:24:17 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/17 10:35:38 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

int	ft_get_color(char *str)
{
	int		i;
	int		color;
	char	**split;

	i = 0;
	color = 0;
	split = ft_split(str, ',');
	while (split[i])
	{
		if (ft_atoi(split[i]) > 255 || ft_atoi(split[i]) < 0)
			ft_printf("Error\nInvalid color\n");
		else
			color = color * 256 + ft_atoi(split[i]);
		i++;
	}
	ft_free_split(split);
	return (color);
}

int	ft_strslen(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	ft_strschr(char *str, char *charset)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] && charset[j] == str[i + j])
		{
			j++;
			if (!charset[j])
				return (1);
		}
		i++;
	}
	return (0);
}

char	*get_next_data(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line && line[0] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	if (!line)
		return (NULL);
	return (line);
}

int	get_settings(int fd, t_settings *set)
{
	char		*raw_line;
	char		*line;
	char		**split;
	int			i;

	i = 0;
	while (i < 6)
	{
		raw_line = get_next_data(fd);
		line = ft_strtrim(raw_line, "\n");
		split = ft_split(line, ' ');
		//ft_printf("split: %s\n", split[0]);
		//ft_printf("split: %s\n", split[1]);
		if (ft_strschr(split[0], "NO") && ft_strslen(split) == 2)
			set->north_texture = ft_strdup(split[1]);
		else if (ft_strschr(split[0], "SO") && ft_strslen(split) == 2)
			set->south_texture = ft_strdup(split[1]);
		else if (ft_strschr(split[0], "WE") && ft_strslen(split) == 2)
			set->west_texture = ft_strdup(split[1]);
		else if (ft_strschr(split[0], "EA") && ft_strslen(split) == 2)
			set->east_texture = ft_strdup(split[1]);
		else if (ft_strschr(split[0], "F") && ft_strslen(split) == 2)
			set->floor_color = ft_get_color(split[1]);
		else if (ft_strschr(split[0], "C") && ft_strslen(split) == 2)
			set->ceiling_color = ft_get_color(split[1]);
		else
			return (1);
		i++;
		free(raw_line);
		free(line);
		ft_free_split(split);
	}
	return (0);
}

t_settings	*init_settings(void)
{
	t_settings	*settings;

	settings = malloc(sizeof(t_settings));
	if (!settings)
		return (NULL);
	settings->floor_color = 0;
	settings->ceiling_color = 0;
	settings->north_texture = NULL;
	settings->south_texture = NULL;
	settings->east_texture = NULL;
	settings->west_texture = NULL;
	settings->sprite_texture = NULL;
	settings->map_heigh = 0;
	settings->map_width = 0;
	return (settings);
}

t_rsc	*init_rsc(void)
{
	t_rsc	*rsc;

	rsc = malloc(sizeof(t_rsc));
	if (!rsc)
		return (NULL);
	rsc->settings = init_settings();
	if (!rsc->settings)
		return (NULL);
	return (rsc);
}

void	print_raw(t_map *raw)
{
	int	i;

	i = 0;
	while (raw[i].val != -1)
	{
		ft_printf("%c", raw[i].val);
		if (raw[i + 1].x != raw[i].x)
			ft_printf("\n");
		//ft_printf("x: %d, y: %d, val: %d\n", raw[i].x, raw[i].y, raw[i].val);
		i++;
	}
}

t_rsc	*parse_file(int fd)
{
	t_rsc	*rsc;
	t_map	*raw;

	rsc = init_rsc();
	if (!rsc)
		return (NULL);
	if (get_settings(fd, rsc->settings) == 1)
		return (NULL);
	raw = get_raw_map(fd, rsc);
	if (!raw)
		return (NULL);
	print_raw(raw);
	return (rsc);
}

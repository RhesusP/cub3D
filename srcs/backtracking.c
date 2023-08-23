/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:18:27 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/23 15:31:45 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	border(t_map *map, int i, t_settings *set, int old)
{
	if (i < 0 || i > set->map_heigh * set->map_width)
		return (0);
	if (map[i].val != 49)
		return (0);
	if (ft_abs(old - i) != set->map_width)
	{
		if (map[i].x != map[old].x)
			return (0);
	}
	return (1);
}

int	get_nb_wall(t_map *map, int i, t_settings *set)
{
	int	nb_ways;

	nb_ways = 0;
	if (border(map, i - 1, set, i) && map[i - 1].val == 49)
		nb_ways++;
	if (border(map, i + 1, set, i) && map[i + 1].val == 49)
		nb_ways++;
	if (border(map, i - set->map_width, set, i) \
		&& map[i - set->map_width].val == 49)
		nb_ways++;
	if (border(map, i + set->map_width, set, i) \
		&& map[i + set->map_width].val == 49)
		nb_ways++;
	return (nb_ways);
}

int	get_next(t_map *map, int i, t_settings *set, int from)
{
	if (border(map, i + 1, set, from) && map[i + 1].val == 49 && i + 1 != from)
		return (i + 1);
	if (border(map, i - 1, set, from) && map[i - 1].val == 49 && i - 1 != from)
		return (i - 1);
	if (border(map, i + set->map_width, set, from) \
		&& map[i + set->map_width].val == 49 && i + set->map_width != from)
		return (i + set->map_width);
	if (border(map, i - set->map_width, set, from) \
		&& map[i - set->map_width].val == 49 && i - set->map_width != from)
		return (i - set->map_width);
	return (0);
}

int	backtrack(t_settings *set, t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 1;
	if (map[i].val != 49)
	{
		while (charset(map[i]))
			i += 1;
	}
	set->origin = i;
	if (track(map, i + 1, set, i, &k))
		return (EXIT_FAILURE);
	return (0);
}

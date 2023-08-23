/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   track.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:24:25 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/23 15:27:52 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	go_first(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	else if (old - i == 1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == -set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	else if (old - i == set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	return (1);
}

int	go_second(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	else if (old - i == 1 && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == -set->map_width \
		&& border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == set->map_width \
		&& border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	return (1);
}

int	go_third(t_map *map, int i, t_settings *set, int old, int *k)
{
	if (old - i == -1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i, k));
	else if (old - i == 1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i, k));
	else if (old - i == -set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i, k));
	else if (old - i == set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i, k));
	return (1);
}

int	track(t_map *map, int i, t_settings *set, int old, int *k)
{
	int	ways;

	map[i].val = 1;
	ways = get_nb_wall(map, i, set);
	if (ways == 0 && i == set->origin)
	{
		*k = 0;
		return (0);
	}
	else if (ways > 0 && *k == 1)
	{
		if (go_first(map, i, set, old, k) && *k == 1)
		{
			if (go_second(map, i, set, old, k) && *k == 1)
			{
				if (go_third(map, i, set, old, k) && *k == 1)
					return (*k);
			}
		}
		else
			return (*k);
	}
	return (*k);
}

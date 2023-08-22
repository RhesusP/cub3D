/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:18:27 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/22 18:59:43 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	track(t_map *map, int i, t_settings *set, int old);

int	ft_abs(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

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
	{
		ft_printf("i-1 exist\n");
		nb_ways++;
	}
	if (border(map, i + 1, set, i) && map[i + 1].val == 49)
	{
		ft_printf("i+1 exist\n");
		nb_ways++;
	}
	if (border(map, i - set->map_width, set, i) && map[i - set->map_width].val == 49)
	{
		ft_printf("i-width exist\n");
		nb_ways++;
	}
	if (border(map, i + set->map_width, set, i) && map[i + set->map_width].val == 49)
	{
		ft_printf("i+width exist\n");
		nb_ways++;
	}

	ft_printf("nb_ways: %d\n", nb_ways);
	return (nb_ways);
}

int	get_next(t_map *map, int i, t_settings *set, int from)
{
	if (border(map, i + 1, set, from) && map[i + 1].val == 49 && i + 1 != from)
		return (i + 1);
	if (border(map, i - 1, set, from) && map[i - 1].val == 49 && i - 1 != from)
		return (i - 1);
	if (border(map, i + set->map_width, set, from) && map[i + set->map_width].val == 49 && i + set->map_width != from)
		return (i + set->map_width);
	if (border(map, i - set->map_width, set, from) && map[i - set->map_width].val == 49 && i - set->map_width != from)
		return (i - set->map_width);
	return (0);
}

int	check_if_corner(t_map *map, int i, t_settings *set)
{
	int	ways;

	ways = get_nb_wall(map, i, set);
	if (ways == 1)
		return (-1);
	else if (ways >= 2)
		return (-2);
	return (-1);
}

int	charset(t_map map)
{
	if (map.val == ' ')
		return (1);
	return (0);
}

int	go_first(t_map *map, int i, t_settings *set, int old)
{
	ft_printf("from_d : %d\n", old - i);
	if (old - i == -1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i));
	else if (old - i == 1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i));
	else if (old - i == -set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i));
	else if (old - i == set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i));
	return (1);
}

int	go_second(t_map *map, int i, t_settings *set, int old)
{
	ft_printf("from_d : %d\n", old - i);
	if (old - i == -1 && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i));
	else if (old - i == 1 && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i));
	else if (old - i == -set->map_width && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i));
	else if (old - i == set->map_width && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i));
	return (1);
}

int	go_third(t_map *map, int i, t_settings *set, int old)
{
	ft_printf("from_d : %d\n", old - i);
	if (old - i == -1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i));
	else if (old - i == 1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i));
	else if (old - i == -set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i));
	else if (old - i == set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i));
	return (1);
}

/*int	go_fourth(t_map *map, int i, t_settings *set, int old)
{
	if (old - i == -1 && border(map, i - set->map_width, set, i))
		return (track(map, i - set->map_width, set, i));
	else if (old - i == 1 && border(map, i + set->map_width, set, i))
		return (track(map, i + set->map_width, set, i));
	else if (old - i == -set->map_width && border(map, i - 1, set, i))
		return (track(map, i - 1, set, i));
	else if (old - i == set->map_width && border(map, i + 1, set, i))
		return (track(map, i + 1, set, i));
	return (1);
}*/

int	track(t_map *map, int i, t_settings *set, int old)
{
	int	temp;

	ft_printf("map[%d] : x: %d, y: %d, val: %d\n", i, map[i].x, map[i].y, map[i].val);
	temp = check_if_corner(map, i, set);
	ft_printf("temp: %d\n", temp);
	if (temp == -1 || i == set->origin)
		return (0);
	else if (temp == -2)
	{
		ft_printf("go first\n");
		if (go_first(map, i, set, old))
		{
			ft_printf("go_second\n");
		}
		if (go_second(map, i, set, old))
		{
			ft_printf("go_third\n");
		}
		if (go_third(map, i, set, old))
		{
			ft_printf("FAILURE\n");
		}
		else
			return (1);
	}
	return (1);
}

int	backtrack(t_settings *set, t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (map[i].val != 49)
	{
		while (charset(map[i]))
			i += 1;
	}
	set->origin = i;
	track(map, i + 1, set, i);
	if (k == 0)
		return (1);
	return (0);
}

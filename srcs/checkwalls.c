/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkwalls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 20:38:55 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/15 21:48:21 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

int	get_first_wall(t_map *map)
{
	int	i;

	i = 0;
	while (map[i].val == -16)
		i++;
	return (i);
}

int	get_adjacent_i(t_map *map, int i, int cor)
{
	int	j;

	if (cor == 1)
	{
		j = i + 1;
		//ft_printf("x: %d, y: %d, val: %d, cor : %d\n", map[i].x, map[i].y, map[i].val, cor);
		//ft_printf("+1 x: %d, y: %d, val: %d, cor : %d\n", map[i + 1].x, map[i + 1].y, map[i + 1].val, cor);
		if ((map[i + 1].y == map[i].y + 1) && (map[i + 1].val != -16 && map[i + 1].val != -127))
			return (i + 1);
		else
		{
			//ft_printf("Changing to <\n");
			while ((map[i].y != map[j].y) && map[j].val != -1)
			{
				ft_printf("x: %d, y: %d, val: %d, cor : %d\n", map[j].x, map[j].y, map[j].val, cor);
				j++;
			}
			if (map[j].val == -127)
			{
				cor = -1;
				return (get_adjacent_i(map, i, cor));
			}
			//ft_printf(">%d\n", j);
			return (j);
		}
	}
	else
	{
		j = i - 1;
		if ((map[i - 1].x == map[i].x - 1) && (map[i - 1].val != 32 && map[i - 1].val != -127))
			return (i - 1);
		else
		{
			while (map[i].y != map[j].y && map[j].val != -1)
				j--;
			if (map[j].val == -127)
			{
				cor = 1;
				return (get_adjacent_i(map, i, cor));
			}
			return (j);
		}
	}
}

int	backtrack_wall(t_map *map, int start, int i, int cor)
{
	if (map[i].val == 1 && i != start)
	{
		ft_printf("x: %d, y: %d, val: %d, cor : %d\n", map[i].x, map[i].y, map[i].val, cor);
		i = backtrack_wall(map, start, get_adjacent_i(map, i, cor), cor);
	}
	else if (i == start)
		return (1);
	return (-1);
}

int	check_walls(t_map *map)
{
	int	start;
	int	cor;
	int	god;

	cor = 1;
	start = get_first_wall(map);
	god = backtrack_wall(map, start, start + 1, cor);
	ft_printf("start: %d, god: %d\n", start, god);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:18:27 by svanmeen          #+#    #+#             */
/*   Updated: 2023/08/28 20:19:28 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/cub3d.h"

/// @brief Check if the index is on the border of the map
int	border(int i, t_settings *set, int old)
{
	if (i < 0 || i > set->map_heigh * set->map_width)
		return (0);
	if (ft_abs(old - i) != set->map_width)
		return (0);
	return (1);
}

/// @brief Check if the character is in the charset
/// @param map 
/// @return 
int	charsets(t_map map)
{
	if (map.val == 49 || map.val == 48 || map.val == 78 || map.val == 83 \
		|| map.val == 69 || map.val == 87)
		return (1);
	return (0);
}

/// @brief Check if we are in a checkable area
/// @param map 
/// @return 
int	ischeckable(t_map map)
{
	if (map.val == 48 || map.val == 78 || map.val == 83 \
		|| map.val == 69 || map.val == 87)
		return (1);
	return (0);
}

/// @brief Check if a area of the map is surronded by walls
/// @param map 
/// @param i 
/// @param set 
/// @return 
int	surrondings(t_map *map, int i, t_settings *set)
{
	if (!border(i + 1, set, i) && !charsets(map[i + 1]))
		return (1);
	if (!border(i - 1, set, i) && !charsets(map[i - 1]))
		return (1);
	if (!border(i + set->map_width, set, i) \
		&& !charsets(map[i + set->map_width]))
		return (1);
	if (!border(i - set->map_width, set, i) \
		&& !charsets(map[i - set->map_width]))
		return (1);
	return (0);
}

/// @brief Main function of the wall check
/// @param set parameters of the game
/// @param map map of the game
/// @return 
int	ismapclosed(t_settings *set, t_map *map)
{
	int		i;

	i = 0;
	while (map[i].val != -1)
	{
		if (ischeckable(map[i]))
		{
			if (surrondings(map, i, set))
				return (1);
			i++;
		}
		else
			i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:02:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 14:06:47 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d.h"

/**
 * @brief Normalizes an angle between 0 and 2PI
 * 
 * @param rad_angle
 * @return double 
 */
double	normalize_angle(double rad_angle)
{
	if (rad_angle >= TWO_PI)
		rad_angle -= TWO_PI;
	if (rad_angle < 0.0)
		rad_angle += TWO_PI;
	return (rad_angle);
}

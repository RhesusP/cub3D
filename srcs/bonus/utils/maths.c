/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 14:02:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 13:49:12 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Normalizes an angle between 0 and 2PI
 * 
 * @param rad_angle
 * @return double 
 */
double	normalize_angle(double rad_angle)
{
	double	two_pi;

	two_pi = 2.0 * M_PI;
	if (rad_angle >= two_pi)
		rad_angle -= two_pi;
	if (rad_angle < 0.0)
		rad_angle += two_pi;
	return (rad_angle);
}

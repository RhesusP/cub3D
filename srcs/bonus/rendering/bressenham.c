/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bressenham.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:08:05 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 13:01:32 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

static void	absolute(int *d, int *i)
{
	if (*d < 0)
	{
		*i = -1;
		*d = -(*d);
	}
}

static void	draw_seg_low(t_mlx_data *img, t_point p1, t_point p2, int col)
{
	int	dy;
	int	yi;
	int	derive;
	int	y;
	int	x;

	dy = p2.y - p1.y;
	yi = 1;
	absolute(&dy, &yi);
	derive = (2 * dy) - (p2.x - p1.x);
	y = p1.y;
	x = p1.x;
	while (x < p2.x)
	{
		ft_mlx_pixel_put(img, x, y, col);
		if (derive > 0)
		{
			y += yi;
			derive += 2 * (dy - (p2.x - p1.x));
		}
		else
			derive += 2 * dy;
		x++;
	}
}

static void	draw_seg_high(t_mlx_data *img, t_point p1, t_point p2, int col)
{
	int	dx;
	int	xi;
	int	derive;
	int	y;
	int	x;

	dx = p2.x - p1.x;
	xi = 1;
	absolute(&dx, &xi);
	derive = (2 * dx) - (p2.y - p1.y);
	y = p1.y;
	x = p1.x;
	while (y < p2.y)
	{
		ft_mlx_pixel_put(img, x, y, col);
		if (derive > 0)
		{
			x += xi;
			derive += 2 * (dx - (p2.y - p1.y));
		}
		else
			derive += 2 * dx;
		y++;
	}
}

/**
 * @brief Draws a line between two points.
 * @details The function uses the Bressenham algorithm. 
 * @see https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm
 * @param img
 * @param p1 
 * @param p2 
 * @param col Color of the line
 */
void	ft_draw_line(t_mlx_data *img, t_point p1, t_point p2, int col)
{
	if (abs(p2.y - p1.y) < abs(p2.x - p1.x))
	{
		if (p1.x > p2.x)
			draw_seg_low(img, p2, p1, col);
		else
			draw_seg_low(img, p1, p2, col);
	}
	else
	{
		if (p1.y > p2.y)
			draw_seg_high(img, p2, p1, col);
		else
			draw_seg_high(img, p1, p2, col);
	}
}

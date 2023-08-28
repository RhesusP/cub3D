/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:47:52 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/27 12:52:27 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Puts a pixel in the image.
 * @details The pixel is put at the coordinates (x, y) in the image. If the
 * coordinates are out of the image, the function does nothing.
 * @param data
 * @param x 
 * @param y 
 * @param color
 */
void	ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

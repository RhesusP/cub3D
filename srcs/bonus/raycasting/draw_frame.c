/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:12:48 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/30 13:50:03 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../../includes/cub3d_bonus.h"

/**
 * @brief Draws a slice of the image.
 * @details As we throw half as many rays as horizontal pixels, we need to draw
 * two slices of the image for each ray.
 * @param map 
 */
static void	draw_image(t_map_info *map)
{
	int	i;

	i = 0;
	while (i < NB_RAYS)
	{
		if (map->frame[i].distance > 0)
		{
			draw_slice(map, map->frame[i], 2 * i);
			draw_slice(map, map->frame[i], 2 * i + 1);
		}
		i++;
	}
}

/**
 * @brief Calls the DDA algorithm for each ray.
 * @details The function casts NB_RAYS rays from the player position and
 * calls the DDA algorithm for each ray to detect the first wall hit.
 * Hit informations are stored in the frame array stored in the map structure.
 * @see dda
 * @see t_frame
 * @param map 
 */
static void	raycasting(t_map_info *map)
{
	int		i;
	double	ray_orientation;

	if (map->frame)
		free(map->frame);
	map->frame = malloc(sizeof(t_frame) * NB_RAYS);
	if (!map->frame)
	{
		print_error("malloc failed\n", 0);
		free_map(map);
	}
	ray_orientation = map->player.dir - (HALF_FOV * DEG_RAD);
	ray_orientation = normalize_angle(ray_orientation);
	i = -1;
	while (++i < NB_RAYS)
	{
		dda(map, ray_orientation, &map->frame[i]);
		ray_orientation += ANGLE_INCR;
		ray_orientation = normalize_angle(ray_orientation);
	}
}

/**
 * @brief Draw a frame (image) of the game.
 * @details The function calls the raycasting function and then draws the image
 * on the screen.
 * @see raycasting
 * @param map 
 */
void	draw_frame(t_map_info *map)
{
	map->mlx_img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	if (!map->mlx_img.img)
		free_map(map);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img, \
		&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length, \
		&map->mlx_img.endian);
	if (!map->mlx_img.addr)
		free_map(map);
	raycasting(map);
	draw_image(map);
	draw_minimap(map, &map->mlx_img);
	mlx_put_image_to_window(map->mlx, map->mlx_win, map->mlx_img.img, 0, 0);
}

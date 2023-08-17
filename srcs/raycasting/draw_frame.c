/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:12:48 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/16 20:20:03 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../../includes/cub3d.h"

double	normalize_angle(double rad_angle)
{
	double two_pi;

	two_pi = M_PI * 2.0;
	if (rad_angle >= two_pi)
		rad_angle -= two_pi;
	if (rad_angle < 0.0)
		rad_angle += two_pi;
	return (rad_angle);
}

double	normalize_angle2(double angle)
{
	double two_pi = 2 * M_PI;
	angle = fmod(angle, two_pi);
	if (angle < 0)
		angle += two_pi;
	return (angle);

}

t_point	cast_single_ray(t_map_info *map, double ray_angle, t_frame *frame)
{
	t_point	hit_point;
	double two_pi = 2 * M_PI;
	
	ray_angle = fmod(ray_angle, two_pi);
    if (ray_angle < 0)
        ray_angle += two_pi;
    int right = (ray_angle > two_pi * 0.75 || ray_angle < two_pi * 0.25);
    int up = (ray_angle < 0 || ray_angle > M_PI);
    double angle_sin = sin(ray_angle);
    double angle_cos = cos(ray_angle);
    double dist = 0;
    double x_hit = 0;
    double y_hit = 0;
	t_point	check;

    double wall_x;
    double wall_y;

    double slope, delta_x, delta_y;
    double x, y, dist_x, dist_y, block_dist;

	// Check against vertical map/wall lines
    slope = angle_sin / angle_cos;
    delta_x = right ? 1 : -1;
    delta_y = delta_x * slope;
    x = right ? ceil(map->player.map_pos.x) : floor(map->player.map_pos.x);
    y = map->player.map_pos.y + (x - map->player.map_pos.x) * slope;
    while (x >= 0 && x < map->map_width * CUBE_SIZE && y >= 0 && y < map->map_height * CUBE_SIZE) {
        wall_x = floor(x + (right ? 0 : -1));
        wall_y = floor(y);
        if (map->map[(int)floor(wall_y / CUBE_SIZE)][(int)floor(wall_x / CUBE_SIZE)] == '1') {
            dist_x = x - map->player.map_pos.x;
            dist_y = y - map->player.map_pos.y;
            dist = dist_x * dist_x + dist_y * dist_y;
            x_hit = x;
            y_hit = y;
			frame->axis = 1;
            break;
        }
        x += delta_x;
        y += delta_y;
    }
	// Check against horizontal lines
    slope = angle_cos / angle_sin;
    delta_y = up ? -1 : 1;
    delta_x = delta_y * slope;
    y = up ? floor(map->player.map_pos.y) : ceil(map->player.map_pos.y);
    x = map->player.map_pos.x + (y - map->player.map_pos.y) * slope;
    while (x >= 0 && x < map->map_width * CUBE_SIZE && y >= 0 && y < map->map_height * CUBE_SIZE) {
        wall_y = floor(y + (up ? -1 : 0));
        wall_x = floor(x);
        if (map->map[(int)floor(wall_y / CUBE_SIZE)][(int)floor(wall_x / CUBE_SIZE)] == '1') {
            dist_x = x - map->player.map_pos.x;
            dist_y = y - map->player.map_pos.y;
            block_dist = dist_x * dist_x + dist_y * dist_y;
            if (!dist || block_dist < dist) {
                dist = block_dist;
                x_hit = x;
                y_hit = y;
				check.x = 0;
				check.y = delta_y;
				frame->axis = 0;
            }
			else
			{
				check.x = right ? 1 : -1;
				check.y = 0;
			}
            break;
        }
        x += delta_x;
        y += delta_y;
    }
	// Draw minimap rays
	if (dist)
	{
		hit_point.x = (x_hit / CUBE_SIZE) * MINI_SIZE;
		hit_point.y = (y_hit / CUBE_SIZE) * MINI_SIZE;
		ft_draw_line(&map->mlx_img, map->player.mini_pos, hit_point, 0x0000FF00);
	}
	t_point	res;
	res.x = x_hit;
	res.y = y_hit;

	// get the wall face orientation hit by the ray
	if (check.x == 1)
		frame->wall_face = WEST;
	else if (check.x == -1)
		frame->wall_face = EAST;
	else if (check.y == 1)
		frame->wall_face = NORTH;
	else
		frame->wall_face = SOUTH;
	return (res);
}

// Radian to degree = o * 180/pi
// Degree to radian = o * pi/180
void	cast_rays(t_map_info *map)
{
	int		i;
	double	ray_orientation;
	double	angle_increment;
	double	fishbowl_corr;

	i = 0;
	map->frame = malloc(sizeof(t_frame) * WIDTH);
	if (!map->frame)
	{
		print_error("malloc failed", 1, 0);
		return;
	}
	angle_increment = (60.0 / WIDTH) * M_PI / 180.0;
	ray_orientation = map->player.dir - (HALF_FOV * M_PI / 180.0);
	ray_orientation = normalize_angle(ray_orientation);
	while (i < WIDTH)
	{
		map->frame[i].point = cast_single_ray(map, ray_orientation, &map->frame[i]);
		fishbowl_corr = cos(normalize_angle(ray_orientation - map->player.dir));
		map->frame[i].distance = fishbowl_corr * sqrt(pow(map->frame[i].point.x - map->player.map_pos.x, 2) + pow(map->frame[i].point.y - map->player.map_pos.y, 2));
		map->frame[i].angle = ray_orientation;
		map->frame[i].height = CUBE_SIZE / map->frame[i].distance * PROJECTION_DISTANCE;
		ray_orientation += angle_increment;
		ray_orientation = normalize_angle(ray_orientation);
		i++;
	}
	i = 0;
	while (i < WIDTH)
	{
		if (map->frame[i].distance > 0)
			draw_slice(map, &map->mlx_img, i);
		i++;
	}
}

void	draw_frame(t_map_info *map)
{
	map->mlx_img.img = mlx_new_image(map->mlx, WIDTH, HEIGHT);
	map->mlx_img.addr = mlx_get_data_addr(map->mlx_img.img, \
		&map->mlx_img.bits_per_pixel, &map->mlx_img.line_length, \
		&map->mlx_img.endian);
	cast_rays(map);
	draw_minimap(map, &map->mlx_img);

	mlx_put_image_to_window(map->mlx, map->mlx_win, map->mlx_img.img, 0, 0);
}

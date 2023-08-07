/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/07 09:52:40 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./../libft/libft.h"
# include "./../minilibx_opengl/mlx.h"
# include <stdio.h>
# include <math.h>

# define CUBE_SIZE 64
# define MINI_CUBE_SIZE 8
# define FOV 60 * M_PI / 180
# define HALF_FOV FOV / 2
# define PLAYER_HEIGHT 32
# define PROJECTION_DISTANCE 1108	// 1280 / 2 / tan(FOV / 2)
# define HEIGHT 720
# define WIDTH 1280

typedef struct	s_point
{
	double	x;
	double	y;
}	t_point;

typedef struct	s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct	s_frame
{
	double	distance;
	double	angle;
	double	height;
}	t_frame;


typedef struct	s_map_info
{
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	int			width;
	int			height;
	char		*sprite_texture;
	char		**map;
	t_frame		*frame;
	t_point		player;
	double		player_or;
}	t_map_info;

/* ------- PARSING -------*/
int				parse_map(char *map_path, t_map_info *map);
int				add_no_texture(char *line, t_map_info *map);
int				add_so_texture(char *line, t_map_info *map);
int				add_ea_texture(char *line, t_map_info *map);
int				add_we_texture(char *line, t_map_info *map);
int				add_floor_color(char *line, t_map_info *map);
int				add_ceiling_color(char *line, t_map_info *map);
void			get_start_pos(t_map_info *map);

/* --------- MLX  --------*/
void			draw_slice(t_map_info *map, t_mlx_data *img, int index);
void			ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);

/* ----- RAYCASTING ------*/
double	find_wall(t_map_info *map, double orientation);

/* -------- UTILS --------*/
int				print_error(char *str, int use_perror, int exit_status);
int				is_file_extension_correct(char *filename);
void			init_void_map(t_map_info *map);
int				init_map_array(t_map_info *map, int height, int width);
int				is_map_desc(char *line);
unsigned int	ft_strlen_wnl(char *str);
void			debug_print_map(t_map_info *map);

/* -------- BONUS --------*/
void			draw_minimap(t_map_info *map, t_mlx_data *img);

#endif
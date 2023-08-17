/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/17 15:28:28 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./../libft/libft.h"
# include "./../minilibx_opengl/mlx.h"
# include <stdio.h>
# include <math.h>

# define CUBE_SIZE 64
# define MINI_SIZE 8
# define FOV 60
# define HALF_FOV 30
# define PLAYER_HEIGHT 32
# define PROJECTION_DISTANCE 1108
# define HEIGHT 720
# define WIDTH 1280
# define SPEED 10.0
# define ROT_SPEED 0.06

# define LEFT_ARROW 123
# define RIGHT_ARROW 124
# define FORWARD 13
# define BACKWARD 1
# define LEFT 0
# define RIGHT 2
# define ESC 53

enum e_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};	

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct	s_wall
{
	t_point	p;
	double	dist;
}	t_wall;

typedef struct	s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct	s_text
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_text;

typedef struct	s_frame
{
	t_point		point;
	float		distance;
	double		angle;
	float		height;
	int			axis;		// 0 is x, 1 is y
	enum e_side	wall_face;
}	t_frame;

typedef struct	s_player
{
	t_point	map_pos;
	t_point	mini_pos;
	double	dir;
	double	speed;
}	t_player;

typedef struct	s_map_info
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_data	mlx_img;
	t_text		*no_texture;
	t_text		*so_texture;
	t_text		*we_texture;
	t_text		*ea_texture;
	int			floor_color;
	int			ceiling_color;
	int			map_width;
	int			map_height;
	char		*sprite_texture;
	char		**map;
	t_frame		*frame;
	t_player	player;
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
void			start_mlx(t_map_info *map);
void			draw_slice(t_map_info *map, t_mlx_data *img, int index);
void			ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
void			ft_draw_line(t_mlx_data *img, t_point p1, t_point p2, int col);
int				create_mlx_color(int t, int r, int g, int b);
int				load_texture(t_map_info *map, t_text *texture, char *path);
int				get_texture_pixel(t_text *text, int x, int y);

/* ------ MOVEMENT ------*/
void			move_forward(t_map_info *map);
void			move_backward(t_map_info *map);
void			move_left(t_map_info *map);
void			move_right(t_map_info *map);

/* ----- RAYCASTING ------*/
double	find_wall(t_map_info *map, double orientation);
void	draw_frame(t_map_info *map);

/* -------- UTILS --------*/
int				print_error(char *str, int use_perror, int exit_status);
int				is_file_extension_correct(char *filename);
void			init_void_map(t_map_info *map);
int				init_map_array(t_map_info *map, int height, int width);
int				is_map_desc(char *line);
unsigned int	ft_strlen_wnl(char *str);
char			*ft_strdup_wnl(const char *s1);
void			debug_print_map(t_map_info *map);
double			normalize_angle(double rad_angle);

/* -------- BONUS --------*/
void			draw_minimap(t_map_info *map, t_mlx_data *img);

#endif
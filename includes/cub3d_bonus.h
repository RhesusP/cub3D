/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/28 09:01:56 by cbernot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H
# include "./../libft/includes/libft.h"
# include "./../minilibx-linux/mlx.h"
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
# define NB_RAYS 640
# define SPEED 10.0
# define ROT_SPEED 0.06

# define DEG_RAD 0.017453
# define RAD_DEG 57.295780
# define ANGLE_INCR 0.001636
# define TWO_PI 6.283185
# define PI_3_2 4.712389

# define LEFT_ARROW 65361
# define RIGHT_ARROW 65363
# define FORWARD 122
# define BACKWARD 115
# define LEFT 113
# define RIGHT 100
# define ESC 65307

enum e_side
{
	NORTH,
	SOUTH,
	EAST,
	WEST
};	

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_mlx_data;

typedef struct s_text
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
	int			is_init;
}	t_text;

typedef struct s_frame
{
	t_point		point;
	float		distance;
	double		angle;
	float		height;
	int			axis;
	enum e_side	wall_face;
}	t_frame;

typedef struct s_dda_vars
{
	double	angle_sin;
	double	angle_cos;
	double	delta_x;
	double	delta_y;
	double	x;
	double	y;
}	t_dda_vars;

typedef struct s_player
{
	t_point	map_pos;
	t_point	mini_pos;
	double	dir;
	double	speed;
}	t_player;

typedef struct s_map_info
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
	char		**map;
	t_frame		*frame;
	t_player	player;
}	t_map_info;

/* --------- MLX  --------*/
void			game_loop(t_map_info *map);
void			ft_mlx_pixel_put(t_mlx_data *data, int x, int y, int color);
int				create_mlx_color(int t, int r, int g, int b);
int				get_texture_color(t_text *text, int x, int y);
int				load_texture(t_map_info *map, t_text *texture, char *path);

/* ------- PARSING -------*/
int				add_texture(t_map_info *map, char *line);
int				map_have_one_player(char **map);
int				text_col_complete(t_map_info *map);
void			get_start_pos(t_map_info *map);
int				parse_map(char *map_path, t_map_info *map);
int				add_color(t_map_info *map, char *line);

/* ----- RAYCASTING ------*/
void			draw_frame(t_map_info *map);
void			dda(t_map_info *map, double ray_angle, t_frame *frame);
double			get_wall_y(t_dda_vars utils, int up);
void			fill_frm_hor(t_frame *f, t_dda_vars u, int up);
void			fill_frm_ver(t_frame *f, t_map_info *map, t_dda_vars u, int r);
int				is_wall(t_map_info *map, int x, int y);
int				coords_within_boundaries(t_map_info *map, int x, int y);

/* ------ RENDERING ------*/
void			draw_slice(t_map_info *map, t_frame frame, int index);
void			ft_draw_line(t_mlx_data *img, t_point p1, t_point p2, int col);

/* -------- UTILS --------*/
unsigned int	ft_strlen_wnl(char *str);
char			*ft_strdup_wnls(const char *s1);
void			move_forward(t_map_info *map);
void			move_backward(t_map_info *map);
void			move_left(t_map_info *map);
void			move_right(t_map_info *map);
double			normalize_angle(double rad_angle);
int				char_is_player(char c);
int				is_desc_char_valid(char c);
int				is_map_desc(char *line);
int				init_void_map(t_map_info *map);
int				init_map_array(t_map_info *map, int height, int width);
int				init_no_text(t_map_info *map);
int				init_so_text(t_map_info *map);
int				init_ea_text(t_map_info *map);
int				init_we_text(t_map_info *map);
void			free_partial_array(char ***array, int last_alloc);
int				free_allocated_text(t_map_info *map);
int				free_allocated_array(char ***array, int is_err);
int				free_map(t_map_info *map);
int				print_error(char *str, int exit_status);
int				is_file_extension_correct(char *filename);

/* -------- BONUS --------*/
void			draw_minimap(t_map_info *map, t_mlx_data *img);

#endif
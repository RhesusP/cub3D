/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svanmeen <svanmeen@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 19:34:21 by cbernot           #+#    #+#             */
/*   Updated: 2023/08/28 20:17:02 by svanmeen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "./../libft/libft.h"
# include <fcntl.h>

typedef struct s_map
{
	int	x;
	int	y;
	int	val;
}				t_map;

typedef struct s_settings
{
	int		floor_color;
	int		ceiling_color;
	char	*north_texture;
	char	*south_texture;
	char	*east_texture;
	char	*west_texture;
	char	*sprite_texture;
	int		map_heigh;
	int		map_width;
	int		origin;
}				t_settings;

typedef struct s_rsc
{
	t_settings	*settings;
}				t_rsc;


t_rsc	*parse_file(int fd);
t_map	*get_raw_map(int fd, t_rsc *rsc);
char	*get_next_data(int fd);
int		ft_strslen(char **strs);
int		border(int i, t_settings *set, int old);
int		charset(t_map map);
int		ft_abs(int nb);
int		check_correct_map(char **raw, t_rsc *rsc);
int		ismapclosed(t_settings *set, t_map *map);

#endif

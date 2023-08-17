# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:23:19 by cbernot           #+#    #+#              #
#    Updated: 2023/08/16 12:18:29 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	cub3D
SRCS	=	./srcs/main.c \
			./srcs/minimap/minimap.c \
			./srcs/mlx/trace.c \
			./srcs/mlx/bressenham.c \
			./srcs/mlx/mlx_utils.c \
			./srcs/parsing/add_colors.c \
			./srcs/parsing/add_textures.c \
			./srcs/parsing/parse_map.c \
			./srcs/parsing/player.c \
			./srcs/raycasting/draw_frame.c \
			./srcs/map_utils.c \
			./srcs/utils.c \
			./srcs/movement.c

MINILIBX_DIR	=	minilibx_opengl/
MINILIBX_NAME	=	libmlx.a
MINILIBX		=	$(addprefix $(MINILIBX_DIR), $(MINILIBX_NAME))			

LIBFT_DIR	=	libft/
LIBFT_NAME	=	libft.a
LIBFT		=	$(addprefix $(LIBFT_DIR), $(LIBFT_NAME))

OBJS 		=	${SRCS:.c=.o}
INCLUDES	=	./includes
FLAGS		=	-Wall -Wextra -Werror
DIR_FLAG	=	--no-print-directory

%.o: %.c | minilibx libft ./includes/cub3d.h
	cc ${FLAGS} -I ${INCLUDES} -c $< -o $@

${NAME}: ${OBJS} ${LIBFT} ${MINILIBX} ./includes/cub3d.h
	cc ${OBJS} -L ./minilibx_opengl -l mlx -framework OpenGL -framework AppKit -L ./libft -lft -o ${NAME}

all: ${NAME}

libft:
	@make -C ${LIBFT_DIR}

minilibx:
	@make -C ./minilibx_opengl

clean:
	make ${DIR_FLAG} clean -C ./minilibx_opengl
	make ${DIR_FLAG} clean -C ./libft
	rm -f ${OBJS}

fclean: clean
	rm -rf ${MINILIBX}
	make ${DIR_FLAG} fclean -C ./libft
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re libft

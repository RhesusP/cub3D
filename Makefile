# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:23:19 by cbernot           #+#    #+#              #
#    Updated: 2023/08/26 00:48:28 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re makemlx makelibft

NAME			:=	cub3D
LIBFT 			:=	libft/libft.a
MLX				:=	minilibx-linux/libmlx.a

# ------------------------------------------------------------------------------
# ALL FILES
# ------------------------------------------------------------------------------

# Files
LST_INC			:=	cub3d.h
LST_SRC			:=	main.c
LST_RENDERING	:=	trace.c \
					bressenham.c
LST_PARSING		:=	colors.c \
					textures.c \
					rules.c \
					parse_map.c \
					player.c
LST_MINIMAP		:=	minimap.c
LST_RAYCASTING	:=	draw_frame.c \
					dda.c \
					dda_utils.c
LST_MLX			:=	mlx_utils.c \
					pixel_put.c
LST_UTILS		:=	free.c \
					errors.c \
					map.c \
					strings.c \
					init_textures.c \
					maths.c	\
					movement.c

# Directories
DIR_MLX			:=	minilibx-linux/
DIR_FT			:=	libft/

DIR_INC			:=	includes/
DIR_SRC			:=	srcs/
DIR_RENDERING	:=	rendering/
DIR_PARSING		:=	parsing/
DIR_MINIMAP		:=	minimap/
DIR_RAYCASTING	:=	raycasting/
DIR_UTILS		:=	utils/
DIR_MLX_S		:=	mlx/
DIR_OBJS		:=	objs/

# Shortcuts
INCS			:=	$(addprefix $(DIR_INC), $(LST_INC))
SRCS			:=	$(addprefix $(DIR_SRC), $(LST_SRC)) \
					$(addprefix $(DIR_SRC)$(DIR_RENDERING), $(LST_RENDERING)) \
					$(addprefix $(DIR_SRC)$(DIR_PARSING), $(LST_PARSING)) \
					$(addprefix $(DIR_SRC)$(DIR_MINIMAP), $(LST_MINIMAP)) \
					$(addprefix $(DIR_SRC)$(DIR_RAYCASTING), $(LST_RAYCASTING)) \
					$(addprefix $(DIR_SRC)$(DIR_MLX_S), $(LST_MLX)) \
					$(addprefix $(DIR_SRC)$(DIR_UTILS), $(LST_UTILS))
OBJS			:=	$(subst $(DIR_SRC), $(DIR_OBJS), $(SRCS:.c=.o))


# ------------------------------------------------------------------------------
# COMMAND VARIABLES
# ------------------------------------------------------------------------------

# Commands
CC				:=	cc
# CFLAGS			:=	-Wall -Wextra -Werror
CI				:=	-I $(DIR_FT) -I $(DIR_INC) -I $(DIR_MLX)
CF				:=	-L minilibx-linux -lmlx -lXext -lX11 -lm -L libft -lft
RM				:=	rm -rf

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

# ------------------------------------------------------------------------------
# RULES
# ------------------------------------------------------------------------------

all: makemlx makelibft $(NAME)

# Binary
$(NAME): $(OBJS) $(INCS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(CI) $(LIBFT) $(MLX) $(OBJS) -o $@ $(CF)
	@echo "$(ERASE)\n$(PURPLE)$(BOLD)🎉🎉 executable $(NAME) created 🎉🎉$(RESET)"
	@echo "$(ERASE)run $(BOLD)./$(NAME) path_to_map.cub$(RESET) to play.$(RESET)"

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(INCS) $(LIBFT) $(MLX) | $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(CI) -c $< -o $@
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) compiling... $(RESET)$<"

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS) \
	$(DIR_OBJS)$(DIR_RENDERING) \
	$(DIR_OBJS)$(DIR_PARSING) \
	$(DIR_OBJS)$(DIR_MINIMAP) \
	$(DIR_OBJS)$(DIR_RAYCASTING) \
	$(DIR_OBJS)$(DIR_MLX_S) \
	$(DIR_OBJS)$(DIR_UTILS)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) objects directory created.$(RESET)"

# Libraries
$(MLX): makemlx

$(LIBFT): makelibft

makemlx:
	@$(MAKE) -C $(DIR_MLX) --quiet --no-print-directory 
	
makelibft:
	@$(MAKE) -C $(DIR_FT) --no-print-directory

# Cleaning
clean:
	@$(RM) $(OBJS)
	@$(RM) $(DIR_OBJS)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(RED) objects deleted.$(RESET)"
	@$(MAKE) clean -C $(DIR_FT) --no-print-directory
	@$(MAKE) clean -C $(DIR_MLX) --no-print-directory

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) fclean -C $(DIR_FT) --no-print-directory
	@$(MAKE) clean -C $(DIR_MLX) --no-print-directory
	@echo "$(ERASE)$(BOLD)libmlx.a$(RESET)$(RED) deleted.$(RESET)"
	@echo "$(ERASE)$(RED)$(BOLD)🗑️  $(NAME) deleted.$(RESET)"

re: fclean all

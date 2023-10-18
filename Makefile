# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/01 00:23:19 by cbernot           #+#    #+#              #
#    Updated: 2023/10/18 14:42:53 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re makemlx makelibft bonus

NAME			:=	cub3D
BONUS_NAME		:=	cub3D_bonus
LIBFT 			:=	libft/libft.a
MLX				:=	minilibx-linux/libmlx.a

# ------------------------------------------------------------------------------
# ALL FILES
# ------------------------------------------------------------------------------

# Files
LST_INC			:=	cub3d.h
LST_BONUS_INC	:=	cub3d_bonus.h
LST_SRC			:=	main.c
LST_RENDERING	:=	trace.c			bressenham.c
LST_PARSING		:=	colors.c		textures.c			rules.c			\
					parse_map.c		player.c
LST_RAYCASTING	:=	draw_frame.c	dda.c				dda_utils.c
LST_MLX			:=	mlx_utils.c		pixel_put.c
LST_UTILS		:=	free.c			errors.c			map.c			\
					strings.c		init_textures.c		maths.c			\
					movement.c		is_blocking.c
LST_EXTRA		:=	minimap.c		rotation.c

# Directories
DIR_MLX			:=	minilibx-linux/
DIR_FT			:=	libft/

DIR_INC			:=	includes/
DIR_SRC			:=	srcs/
DIR_MANDATORY	:=	mandatory/
DIR_BONUS		:=	bonus/
DIR_RENDERING	:=	rendering/
DIR_PARSING		:=	parsing/
DIR_EXTRA		:=	bonus/
DIR_RAYCASTING	:=	raycasting/
DIR_UTILS		:=	utils/
DIR_MLX_S		:=	mlx/
DIR_OBJS		:=	objs/
DIR_BONUS_OBJS	:=	objs_bonus/

# Mandatory shortcuts
INCS			:=	$(addprefix $(DIR_INC), $(LST_INC))
SRCS			:=	$(addprefix $(DIR_SRC)$(DIR_MANDATORY), $(LST_SRC))							\
					$(addprefix $(DIR_SRC)$(DIR_MANDATORY)$(DIR_RENDERING), $(LST_RENDERING))	\
					$(addprefix $(DIR_SRC)$(DIR_MANDATORY)$(DIR_PARSING), $(LST_PARSING))		\
					$(addprefix $(DIR_SRC)$(DIR_MANDATORY)$(DIR_RAYCASTING), $(LST_RAYCASTING))	\
					$(addprefix $(DIR_SRC)$(DIR_MANDATORY)$(DIR_MLX_S), $(LST_MLX))				\
					$(addprefix $(DIR_SRC)$(DIR_MANDATORY)$(DIR_UTILS), $(LST_UTILS))
OBJS			:=	$(subst $(DIR_SRC), $(DIR_OBJS), $(SRCS:.c=.o))

# Bonus shortcuts
BONUS_INCS		:=	$(addprefix $(DIR_INC), $(LST_BONUS_INC))
BONUS_SRCS		:=	$(addprefix $(DIR_SRC)$(DIR_BONUS), $(LST_SRC))								\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_RENDERING), $(LST_RENDERING))		\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_PARSING), $(LST_PARSING))			\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_RAYCASTING), $(LST_RAYCASTING))		\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_MLX_S), $(LST_MLX))					\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_UTILS), $(LST_UTILS))				\
					$(addprefix $(DIR_SRC)$(DIR_BONUS)$(DIR_EXTRA), $(LST_EXTRA))
BONUS_OBJS		:=	$(subst $(DIR_SRC), $(DIR_BONUS_OBJS), $(BONUS_SRCS:.c=.o))

# ------------------------------------------------------------------------------
# COMMAND VARIABLES
# ------------------------------------------------------------------------------

# Commands
CC				:=	cc
CFLAGS			:=	-Wall -Wextra -Werror
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

# Mandatory rules
$(NAME): $(OBJS) $(INCS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(CI) $(LIBFT) $(MLX) $(OBJS) -o $@ $(CF)
	@echo "$(ERASE)\n$(PURPLE)$(BOLD)🎉🎉 executable $(NAME) created 🎉🎉$(RESET)"
	@echo "$(ERASE)run $(BOLD)./$(NAME) path_to_map.cub$(RESET) to play.$(RESET)"

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(INCS) $(LIBFT) $(MLX) | $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(CI) -c $< -o $@
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) compiling... $(RESET)$<"

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS) \
	$(DIR_OBJS)$(DIR_MANDATORY) \
	$(DIR_OBJS)$(DIR_MANDATORY)$(DIR_RENDERING) \
	$(DIR_OBJS)$(DIR_MANDATORY)$(DIR_PARSING) \
	$(DIR_OBJS)$(DIR_MANDATORY)$(DIR_RAYCASTING) \
	$(DIR_OBJS)$(DIR_MANDATORY)$(DIR_MLX_S) \
	$(DIR_OBJS)$(DIR_MANDATORY)$(DIR_UTILS)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) objects directory created.$(RESET)"

# Bonus rules
bonus: makemlx makelibft $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(BONUS_INCS) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(CI) $(LIBFT) $(MLX) $(BONUS_OBJS) -o $@ $(CF)
	@echo "$(ERASE)\n$(PURPLE)$(BOLD)🔥🔥 executable $(BONUS_NAME) created 🔥🔥$(RESET)"
	@echo "$(ERASE)run $(BOLD)./$(BONUS_NAME) path_to_map.cub$(RESET) to play.$(RESET)"

$(DIR_BONUS_OBJS)%.o: $(DIR_SRC)%.c $(BONUS_INCS) $(LIBFT) $(MLX) | $(DIR_BONUS_OBJS)
	@$(CC) $(CFLAGS) $(CI) -c $< -o $@
	@echo "$(ERASE)$(BOLD)$(BONUS_NAME)$(RESET)$(GREEN) compiling... $(RESET)$<"

$(DIR_BONUS_OBJS):
	@mkdir -p $(DIR_BONUS_OBJS) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_RENDERING) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_PARSING) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_RAYCASTING) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_MLX_S) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_UTILS) \
	$(DIR_BONUS_OBJS)$(DIR_BONUS)$(DIR_EXTRA)
	@echo "$(ERASE)$(BOLD)$(BONUS_NAME)$(RESET)$(GREEN) objects directory created.$(RESET)"

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
	@$(RM) $(BONUS_OBJS)
	@if [ -d "$(DIR_OBJS)" ]; then \
		$(RM) $(DIR_OBJS); echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(RED) objects deleted.$(RESET)"; \
	fi
	@if [ -d "$(DIR_BONUS_OBJS)" ]; then \
		$(RM) $(DIR_BONUS_OBJS); echo "$(ERASE)$(BOLD)$(BONUS_NAME)$(RESET)$(RED) objects deleted.$(RESET)"; \
	fi
	@$(MAKE) clean -C $(DIR_FT) --no-print-directory
	@$(MAKE) clean -C $(DIR_MLX) --no-print-directory

fclean: clean
	@if [ -f "$(NAME)" ]; then \
		$(RM) $(NAME); echo "$(ERASE)$(RED)$(BOLD)🗑️  $(NAME) deleted.$(RESET)"; \
	fi
	@if [ -f "$(BONUS_NAME)" ]; then \
		$(RM) $(BONUS_NAME); echo "$(ERASE)$(RED)$(BOLD)🗑️  $(BONUS_NAME) deleted.$(RESET)"; \
	fi
	@$(MAKE) fclean -C $(DIR_FT) --no-print-directory
	@echo "$(ERASE)$(BOLD)libmlx.a$(RESET)$(RED) deleted.$(RESET)"

re: fclean all

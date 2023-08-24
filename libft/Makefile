# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:02:40 by cbernot           #+#    #+#              #
#    Updated: 2023/08/24 19:21:05 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME		:=	libft.a

# ------------------------------------------------------------------------------
# ALL FILES
# ------------------------------------------------------------------------------

# Files
LST_INC		:=	libft.h
LST_SRC		:=	ft_isalpha.c		ft_isdigit.c		ft_isalnum.c		\
				ft_isascii.c		ft_isprint.c		ft_strlen.c			\
				ft_memset.c			ft_bzero.c			ft_memcpy.c			\
				ft_memmove.c		ft_strlcpy.c		ft_strlcat.c		\
				ft_toupper.c		ft_tolower.c		ft_strchr.c			\
				ft_strrchr.c		ft_strncmp.c		ft_memchr.c			\
				ft_memcmp.c			ft_strnstr.c		ft_atoi.c			\
				ft_calloc.c			ft_strdup.c			ft_substr.c			\
				ft_strjoin.c		ft_strtrim.c		ft_split.c			\
				ft_itoa.c			ft_strmapi.c		ft_striteri.c		\
				ft_putchar_fd.c		ft_putstr_fd.c		ft_putendl_fd.c		\
				ft_putnbr_fd.c		ft_lstnew.c			ft_lstadd_front.c	\
				ft_lstsize.c		ft_lstlast.c		ft_lstadd_back.c	\
				ft_lstdelone.c		ft_lstclear.c		ft_lstiter.c		\
				ft_lstmap.c
LST_PRT		:=	ft_printf.c			ft_print_char.c		ft_print_int_hex.c	\
				ft_print_int.c		ft_print_ptr.c		ft_print_str.c		\
				ft_print_uint.c		
LST_GNL		:=	get_next_line.c		get_next_line_utils.c

# Directories
DIR_INC		:=	includes/
DIR_SRC		:=	srcs/
DIR_PRT		:=	ft_printf/
DIR_GNL		:=	get_next_line/
DIR_OBJS	:=	objs/

# Shortcuts
INCS		:=	$(addprefix $(DIR_INC), $(LST_INC))
SRCS		:=	$(addprefix $(DIR_SRC), $(LST_SRC)) \
				$(addprefix $(DIR_SRC)$(DIR_PRT), $(LST_PRT)) \
				$(addprefix $(DIR_SRC)$(DIR_GNL), $(LST_GNL))
OBJS		:=	$(SRCS:$(DIR_SRC)%.c=$(DIR_OBJS)%.o)

# ------------------------------------------------------------------------------
# COMMAND VARIABLES
# ------------------------------------------------------------------------------

# Commands
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror
CI			:=	-I $(DIR_INC)
RM			:=	rm -rf

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

all: $(NAME)

# Binary
$(NAME): $(OBJS)
	@ar rcs ${NAME} ${OBJS}
	@echo "$(ERASE)$(GREEN)$(BOLD)✅ $(NAME)$(GREEN) created.$(RESET)"

$(DIR_OBJS)%.o: $(DIR_SRC)%.c $(INCS) | $(DIR_OBJS)
	@$(CC) $(CFLAGS) $(CI) -c $< -o $@
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) compiling... $(RESET)$<"

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS) \
	$(DIR_OBJS)$(DIR_PRT) \
	$(DIR_OBJS)$(DIR_GNL)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(GREEN) objects directory created.$(RESET)"

# Cleaning
clean:
	@$(RM) $(OBJS)
	@$(RM) $(DIR_OBJS)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(RED) objects deleted.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(ERASE)$(BOLD)$(NAME)$(RESET)$(RED) deleted.$(RESET)"

re: fclean all

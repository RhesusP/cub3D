# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbernot <cbernot@student.42lyon.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 14:02:40 by cbernot           #+#    #+#              #
#    Updated: 2023/07/22 18:58:58 by cbernot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRCS = ./ft_isalpha.c ./ft_isdigit.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c ./ft_strlen.c \
		./ft_memset.c ./ft_bzero.c ./ft_memcpy.c ./ft_memmove.c ./ft_strlcpy.c ./ft_strlcat.c \
		./ft_toupper.c ./ft_tolower.c ./ft_strchr.c ./ft_strrchr.c ./ft_strncmp.c ./ft_memchr.c \
		./ft_memcmp.c ./ft_strnstr.c ./ft_atoi.c ./ft_calloc.c ./ft_strdup.c ./ft_substr.c \
		./ft_strjoin.c ./ft_strtrim.c ./ft_split.c ./ft_itoa.c ./ft_strmapi.c ./ft_striteri.c \
		./ft_putchar_fd.c ./ft_putstr_fd.c ./ft_putendl_fd.c ./ft_putnbr_fd.c ./get_next_line/get_next_line.c \
		./get_next_line/get_next_line_utils.c ./ft_printf/ft_printf.c ./ft_printf/ft_print_char.c \
		./ft_printf/ft_print_int_hex.c ./ft_printf/ft_print_int.c ./ft_printf/ft_print_ptr.c \
		./ft_printf/ft_print_str.c ./ft_printf/ft_print_uint.c ./ft_lstnew.c ./ft_lstadd_front.c \
		./ft_lstsize.c ./ft_lstlast.c ./ft_lstadd_back.c ./ft_lstdelone.c ./ft_lstclear.c \
		./ft_lstiter.c ./ft_lstmap.c
OBJS = ${SRCS:.c=.o}
FLAGS = -Wall -Wextra -Werror

%.o : %.c libft.h
	cc ${FLAGS} -I . -c $< -o $@
	
$(NAME): ${OBJS}
	ar rcs ${NAME} ${OBJS}

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-had <moel-had@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/16 23:00:40 by moel-had          #+#    #+#              #
#    Updated: 2021/12/17 19:54:50 by moel-had         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = ft_printstr.c ft_printnbr.c ft_print_u.c ft_x.c ft_printf.c\

NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

CC = gcc

OBJ = $(SRCS:%.c=%.o)


all: $(NAME)

$(NAME): $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o:%.c ft_printf.h
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

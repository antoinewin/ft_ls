# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: achauvea <achauvea@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/11/10 08:23:40 by achauvea          #+#    #+#              #
#    Updated: 2015/01/08 14:55:27 by achauvea         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		=	main.c 			\
			tools.c			\
			ls_options.c	\
			ls_elem.c		\
			ls_struct.c		\
			ls_print.c		\
			ls_file.c		\
			ls_recursive.c	\
			ls_size.c		\

OBJ		= $(SRC:.c=.o)

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	make -C libft/
	gcc $(OBJ) -o $(NAME) -L libft/ -lft

all: $(NAME)

clean:
	make -C libft/ clean
	rm -rf $(OBJ)

fclean:
	make -C libft/ fclean
	rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)

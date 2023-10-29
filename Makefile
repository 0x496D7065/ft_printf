# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lpetit <lpetit@student.s19.be>             +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/20 12:47:37 by lpetit            #+#    #+#              #
#    Updated: 2023/10/29 17:07:46 by lpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

INC = -I.

CFLAGS = -Wall -Wextra -Werror $(INC)

SRC =	ft_printf.c ft_printf_aux.c ft_print_ptr.c \
	ft_print_hexa.c \

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean $(NAME)

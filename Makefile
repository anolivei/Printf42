# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 21:40:14 by anolivei          #+#    #+#              #
#    Updated: 2020/04/12 17:35:52 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_print_pct.c ft_print_char.c ft_print_string.c \
	  ft_print_int.c ft_print_int_aux.c ft_print_pointer.c \
	  ft_itoa.c ft_dtox.c ft_utoa.c \
	  ft_putchar.c ft_putstr.c \
	  ft_strlen.c ft_strchr.c ft_strjoin.c

MAIN = main.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

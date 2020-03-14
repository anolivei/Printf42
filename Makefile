# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anolivei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/19 21:40:14 by anolivei          #+#    #+#              #
#    Updated: 2020/03/14 05:12:52 by anolivei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_printf.c ft_strchr.c ft_print_char.c ft_strlen.c ft_putchar.c \
	ft_print_string.c ft_putstr.c
		#ft_print_int.c ft_print_string.c ft_print_hexa.c ft_print_pointer.c ft_print_u.c ft_print_percent.c ft_strlen.c ft_itoa.c

MAIN = main.c

OBJ = $(subst .c,.o,$(SRC))

all: $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
main:
	@gcc -Wall -Wextra -Werror $(SRC) $(MAIN)
clean:
	@/bin/rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:47:32 by fsinged           #+#    #+#              #
#    Updated: 2019/05/28 12:45:19 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
PATH = ./write/
SRCS = ft_printf.c \
ft_putchar.c \
ft_putstr.c \
ft_putdouble.c \
ft_putnbr.c \
ft_puthex.c \
ft_get_nbr.c \
ft_get_double.c \
ft_error.c \
ft_flags.c \
ft_length_flag.c \
ft_strdel.c \
ft_isdigit.c \
ft_isalpha.c \
ft_atoi.c
OBJ = $(SRCS:.c=.o)
HEADER = ft_printf.h

all:$(NAME)

$(NAME):
	@gcc -c $(SRCS) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean:clean
	@/bin/rm -f $(NAME)

re:fclean all
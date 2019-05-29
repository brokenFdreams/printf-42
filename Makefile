#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:47:32 by fsinged           #+#    #+#              #
#    Updated: 2019/05/29 12:58:38 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
SRCS = ft_printf.c \
ft_putdouble.c \
ft_puthex.c \
ft_get_nbr.c \
ft_get_double.c \
ft_error.c \
ft_flags.c \
ft_length_flag.c
LIBFT = ./libft/
LIB = ./libft/libft.a
OBJ = $(SRCS:.c=.o)
HEADER = ft_printf.h

all:$(NAME)

$(NAME):
	@make -C $(LIBFT)
	@gcc -c $(SRCS) $(LIB) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@make clean -C $(LIBFT)
	@/bin/rm -f $(OBJ)

fclean:clean
	@make fclean -C $(LIBFT)
	@/bin/rm -f $(NAME)

re:fclean all
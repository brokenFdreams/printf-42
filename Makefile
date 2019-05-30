#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:47:32 by fsinged           #+#    #+#              #
#    Updated: 2019/05/30 16:33:42 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
PATH = ./src/types/
SPATH = ./src/
FLAGS = -Wall -Wextra -Werror
SRCS = $(SPATH)ft_printf.c \
$(PATH)ft_get_double.c \
$(PATH)ft_get_hex.c \
$(PATH)ft_get_nbr.c \
$(PATH)ft_get_double.c \
$(PATH)ft_get_str.c \
$(PATH)ft_get_char.c \
$(PATH)ft_get_percent.c \
$(SPATH)ft_error.c \
$(SPATH)ft_check_flags.c \
$(SPATH)ft_flags.c \
$(SPATH)ft_length_flag.c
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
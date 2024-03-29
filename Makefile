#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:47:32 by fsinged           #+#    #+#              #
#    Updated: 2019/09/25 15:08:42 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./src/
SRCS_FILES = ft_printf.c ft_error.c ft_flags.c ft_length_flag.c ft_octal.c \
	ft_double.c ft_hex.c ft_int.c ft_uint.c ft_str.c ft_char.c ft_percent.c \
	ft_binary.c ft_pointer.c ft_strnjoin.c ft_double_itoa.c \
	ft_double_convert.c ft_double_exp.c ft_double_binary.c ft_strrdel.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS_PATH = ./OBJS/
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))

LIB_PATH = ./libft/
LIB = ./libft/libft.a
HEADER = -I ./includes/ -I ./libft/

all:$(NAME)

$(NAME):$(LIB)
	@mkdir $(OBJS_PATH)
	@gcc -c $(SRCS) $(HEADER)
	@mv $(OBJS_FILES) $(OBJS_PATH)
	@ar rc $(NAME) $(OBJS) $(LIB)
	@ranlib $(NAME)

$(LIB):
	@make -C $(LIB_PATH)
	@cp $(LIB) $(NAME)
clean:
	@make fclean -C $(LIB_PATH)
	@/bin/rm -rf $(OBJS_PATH)

fclean:clean
	@/bin/rm -f $(NAME)

re:fclean all
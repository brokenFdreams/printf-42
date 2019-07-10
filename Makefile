#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsinged <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/17 15:47:32 by fsinged           #+#    #+#              #
#    Updated: 2019/07/10 13:41:09 by fsinged          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRCS_PATH = ./src/
SRCS_FILES = ft_printf.c ft_error.c ft_flags.c ft_length_flag.c ft_octal.c \
	ft_double.c ft_hex.c ft_int.c ft_uint.c ft_str.c ft_char.c ft_percent.c \
	ft_binary.c ft_pointer.c ft_strnjoin.c ft_double_itoa.c \
	ft_double_convert.c ft_exponentiation.c
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_FILES))
OBJS_PATH = ./OBJS/
OBJS_FILES = $(SRCS_FILES:.c=.o)
OBJS = $(addprefix $(OBJS_PATH), $(OBJS_FILES))
LIB_PATH = ./libft/
LIB_SRCS_FILES = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
	ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c \
	ft_strncpy.c ft_strcat.c ft_strncat.c ft_strlcat.c ft_strchr.c \
	ft_strrchr.c ft_strstr.c ft_strnstr.c ft_strcmp.c ft_strncmp.c \
	ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_toupper.c ft_tolower.c ft_memalloc.c ft_memdel.c \
	ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c \
	ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_itoa_base.c \
	ft_max.c ft_min.c ft_sqrt.c ft_strpcat.c
LIB_OBJS_FILES = $(LIB_SRCS_FILES:.c=.o)
LIB_OBJS = $(addprefix $(LIB_PATH), $(LIB_OBJS_FILES))
HEADER = -I ./includes/ft_printf.h

all:$(NAME)

$(NAME):$(SRCS)
	@make -C $(LIB_PATH)
	@mkdir $(OBJS_PATH)
	@gcc -c $(SRCS) $(HEADER)
	@mv $(OBJS_FILES) $(OBJS_PATH)
	@ar rc $(NAME) $(OBJS) $(LIB_OBJS)
	@ranlib $(NAME)

clean:
	@make fclean -C $(LIB_PATH)
	@/bin/rm -rf $(OBJS_PATH)

fclean:clean
	@/bin/rm -f $(NAME)

re:fclean all
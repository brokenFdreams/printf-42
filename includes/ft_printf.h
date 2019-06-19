/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:37:32 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 14:58:06 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

# include <stdio.h>

# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_L 3
# define LENGTH_LL 4
# define LENGTH_J 5
# define LENGTH_Z 6
# define LENGTH_T 7
# define LENGTH_LLL 8

typedef struct	s_flags
{
	int			zero;
	int			minus;
	int			plus;
	int			space;
	int			hash;
	int			width;
	int			precision;
	int			length;
	int			bytes;
	char		*output;
}				t_flags;

int				ft_printf(char *str, ...);
char			*ft_int(va_list ap, t_flags *flags);
char			*ft_int_flags(char *nbr, t_flags *flags, int sign);
char			*ft_uint(va_list ap, t_flags *flags, char c);
char			*ft_uint_itoa(uintmax_t nbr);
char			*ft_double(va_list ap, t_flags *flags);
char			*ft_hex(va_list ap, t_flags *flags, int flag);
char			*ft_str(va_list ap, t_flags *flags, int flag);
char			*ft_char(va_list ap, t_flags *flags, int flag);
char			*ft_percent(t_flags *flags);
void			ft_error();
void			ft_init_flags(t_flags *flags);
int				ft_handle_flags(char **str, t_flags *flags);
int				ft_handle_width(char **str, t_flags *flags, va_list ap);
int				ft_handle_precision(char **str, t_flags *flags, va_list ap);
int				ft_handle_length(char **str, t_flags *flags);
void			ft_length(char **str, t_flags *flags, int length, int size);

#endif

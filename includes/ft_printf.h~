/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:37:32 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 15:24:21 by fsinged          ###   ########.fr       */
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
int				ft_int(va_list ap, t_flags *flags, char **save, char c);
int				ft_int_flags(char **nbr, t_flags *flags, int sign, char **save);
int				ft_int_width(char **save, int size, t_flags *flags, int sign);
int				ft_uint(va_list ap, t_flags *flags, char c, char **save);
char			*ft_uint_itoa(uintmax_t nbr, int base);
uintmax_t		ft_get_uint(va_list ap, t_flags *flags);
int				ft_double(va_list ap, t_flags *flags, char **save, char c);
char			*ft_double_itoa(long double nbr, t_flags *flags, int *sign);
int				ft_double_binary(long double nbr, char **mantissa, int *sign);
void			ft_double_revert(char *mantissa, char **num, int exp,
								t_flags *flags);
void			ft_double_addition(char *num, char *tmp, int size, int len);
void			ft_double_plusrem(char *num, int size);
int				ft_double_exp(int exponent, int base, char **exp);
int				ft_double_multi(char *exp, int base);
int				ft_hex(va_list ap, t_flags *flags, int flag, char **save);
int				ft_hex_flags(char **nbr, t_flags *flags, int flag, char **save);
int				ft_octal(va_list ap, t_flags *flags, char **save);
int				ft_binary(va_list ap, t_flags *flags, char **save);
int				ft_str(va_list ap, t_flags *flags, int flag, char **save);
int				ft_char(va_list ap, t_flags *flags, int flag, char **save);
int				ft_percent(t_flags *flags, char **save);
int				ft_pointer(va_list ap, t_flags *flags, char **save);
void			ft_error();
void			ft_init_flags(t_flags *flags);
int				ft_handle_flags(char **str, t_flags *flags);
int				ft_handle_width(char **str, t_flags *flags, va_list ap);
int				ft_handle_precision(char **str, t_flags *flags, va_list ap);
int				ft_handle_length(char **str, t_flags *flags);
void			ft_length(char **str, t_flags *flags, int length, int size);
char			*ft_strnjoin(char *s1, const char *s2, size_t n, size_t pos);
char			*ft_strmjoin(char *s1, const char *s2, size_t n, size_t pos);
void			ft_strrdel(char **power, char **tmp);

#endif

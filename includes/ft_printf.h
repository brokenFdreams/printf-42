/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:37:32 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:29:40 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdint.h>
# include "../libft/libft.h"

# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_LL 3
# define LENGTH_L 4
# define LENGTH_LLL 5
# define LENGTH_Z 6
# define LENGTH_J 7
# define LENGTH_T 8

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

int				ft_fill_nbr_f(char **save, int size, t_flags *flags);
int				ft_length_u(uintmax_t nbr);
int				ft_length_d(intmax_t nbr);
char			*ft_get_nbr(va_list ap, t_flags *flags);
char			*ft_get_nbr_u(va_list ap, t_flags *flags);
char			*ft_get_double(va_list ap, t_flags *flags);
char			*ft_get_hex(va_list ap, t_flags *flags, int flag);
char			*ft_get_str(va_list ap, t_flags *flags, int flag);
char			*ft_get_char(va_list ap, t_flags *flags, int flag);
char			*ft_get_percent(t_flags *flags);
void			ft_error();
void			ft_strdel(char **as);
void			ft_init_flags(t_flags *flags);
int				ft_handle_flags(char **str, t_flags *flags);
int				ft_handle_width(char **str, t_flags *flags, va_list ap);
int				ft_handle_precision(char **str, t_flags *flags, va_list ap);
int				ft_handle_length(char **str, t_flags *flags);
void			ft_length(char **str, t_flags *flags, int length, int size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 12:58:59 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/27 17:05:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** [flags][min field witdh][precision][length]conversion specifier
** [0-+ #][num or *][.num or .*][h l hhllLjz]dufcCsSxX
*/

void	ft_init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->minus = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->width = 0;
	flags->precision = 0;
	flags->length = 0;
}

/*
** Handle flags
*/

int		ft_handle_flags(char **str, t_flags	*flags)
{
	if (**str == '0')
		flags->zero = 1;
	else if (**str == '-')
		flags->minus = 1;
	else if (**str == '+')
		flags->plus = 1;
	else if (**str == ' ')
		flags->space = 1;
	else if (**str == '#')
		flags->hash = 1;
	else
		return (0);
	(*str)++;
	return (1);
}
/*
** Handle min field width
*/
int		ft_handle_width(char **str, t_flags *flags, va_list ap)
{
	int	width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
		{
			width = va_arg(ap, int);
			if (width < 0)
			{
				flags->minus = 1;
				width *= -1;
			}
			flags->width = width;
			width = 1;
		}
		else
			flags->width = width;
		while (width > 0)
		{
			width /= 10;
			(*str)++;
		}
		return (1);
	}
	return (0);
}

/*
** Handle precision
*/

int		ft_handle_precision(char **str, t_flags *flags, va_list ap)
{
	int	precision;

	if (**str == '.')
	{
		(*str)++;
		if (!ft_isdigit(**str) && **str != '*')
		{	
			flags->precision = -1;
			return (1);
		}
		if (**str == '*')
			precision = va_arg(ap, int);
		else
			precision = ft_atoi(*str);
		flags->precision = precision;
		if (flags->precision < 0 && flags->precision != -1)
			flags->precision = 0;
		if (**str == '*')
			precision = 1;
		else if (precision == 0)
			(*str)++;
		while (precision > 0)
		{
			precision /= 10;
			(*str)++;
		}
		return (1);
	}
	return (0);
}

/*
** Handle length
** ft_length(char **str, t_flags *flags, int length, int size)
*/
int		ft_handle_length(char **str, t_flags *flags)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		ft_length(str, flags, LENGTH_HH, 2);
	else if (**str == 'h')
		ft_length(str, flags, LENGTH_H, 1);
	else if (**str == 'l' && *(*str + 1) == 'l')
		ft_length(str, flags, LENGTH_LL, 2);
	else if (**str == 'l')
		ft_length(str, flags, LENGTH_L, 1);
	else if (**str == 'L')
		ft_length(str, flags, LENGTH_LLL, 1);
	else if (**str == 'z')
		ft_length(str, flags, LENGTH_Z, 1);
	else if (**str == 'j')
		ft_length(str, flags, LENGTH_J, 1);
	else if (**str == 't')
		ft_length(str, flags, LENGTH_T, 1);
	else
		return (0);
	return (1);
}

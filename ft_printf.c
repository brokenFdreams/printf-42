/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:32:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/28 16:13:24 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_specifier(char **str, t_flags *flags, va_list ap)
{
	if (**str == '%')
		return (ft_putstr("%", flags));
	else if (**str == 's' || **str == 'S')
		return (ft_putstr(va_arg(ap, char*), flags));
	else if (**str == 'd')
		return (ft_putnbr(ft_get_nbr(ap, flags)));
	else if (**str == 'c' || **str == 'C')
		return (ft_putchar((char)va_arg(ap, int)));
	else if (**str == 'f')
		return (ft_putdouble(ft_get_double(ap, flags), flags));
	else if (**str == 'u')
		return (ft_putnbr(ft_get_nbr_u(ap, flags)));
	else if (**str == 'x')
		return (ft_puthex(ft_get_nbr_u(ap, flags), 0, flags));
	else if (**str == 'X')
		return (ft_puthex(ft_get_nbr_u(ap, flags), 1, flags));
	return (0);
}

/*
** [flags][min field width][precision][length][specifier]
*/

int	ft_handle(char **str, t_flags *flags, va_list ap)
{
	int flag;

	flag = 0;
	while (**str == ' ')
	{
		(*str)++;
		flag = 1;
	}
	ft_init_flags(flags);
	if (flag)
		flags->space = 1;
	while (ft_handle_flags(str, flags));

	ft_handle_width(str, flags, ap);
	ft_handle_precision(str, flags, ap);
	ft_handle_length(str, flags);
	if (ft_isalpha(**str) || **str == '%')
		return (ft_check_specifier(str, flags, ap));
	return (0);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	int		bytes;
	t_flags	flags;

	va_start(ap, str);
	bytes = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			bytes += ft_handle(&str, &flags, ap);
		}
		else
			bytes += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (bytes);
}

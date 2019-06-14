/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:32:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/14 15:18:47 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include <stdio.h>

/*
** Check specifier and run function for this specifier
*/

char	*ft_check_specifier(char **str, t_flags *flags, va_list ap)
{
	if (**str == '%')
		return (ft_get_percent(flags));
	else if (**str == 's')
		return (ft_get_str(ap, flags, 0));
	else if (**str == 'S')
		return (ft_get_str(ap, flags, 1));
	else if (**str == 'd' || **str == 'i')
		return (ft_get_nbr(ap, flags));
	else if (**str == 'c')
		return (ft_get_char(ap, flags, 0));
	else if (**str == 'C')
		return (ft_get_char(ap, flags, 1));
	else if (**str == 'f')
		return (ft_get_double(ap, flags));
	else if (**str == 'u')
		return (ft_get_nbr_u(ap, flags));
	else if (**str == 'x')
		return (ft_get_hex(ap, flags, 0));
	else if (**str == 'X')
		return (ft_get_hex(ap, flags, 1));
	(*str)--;
	return (ft_strnew(0));
}

/*
** [flags][min field width][precision][length][specifier]
*/

char	*ft_handle(char **str, t_flags *flags, va_list ap)
{
	if (!(**str) || !(*str))
	{
		(*str)--;
		return (ft_strnew(0));
	}
	ft_init_flags(flags);
	while (ft_handle_flags(str, flags) || ft_handle_width(str, flags, ap) ||
		   ft_handle_precision(str,flags, ap) || ft_handle_length(str,flags));

	if (**str && (ft_isalpha(**str) || **str == '%'))
		return (ft_check_specifier(str, flags, ap));
	if(!(**str) || !(*str))
		(*str)--;
	return (ft_strnew(0));
}

char	*ft_handle_string(char **str)
{
	int 	i;
	char	*save;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if (!(save = ft_strnew(i)))
		ft_error();
	save = ft_strncpy(save, *str, i);
	*str = (*str) + i - 1;
	return (save);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	t_flags	flags;
	char	*save;
	char	*tmp;

	va_start(ap, str);
	flags.bytes = 0;
	flags.output = ft_strnew(flags.bytes);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			save = ft_handle(&str, &flags, ap);
		}
		else
			save = ft_handle_string(&str);
		str++;
		tmp = flags.output;
		flags.bytes += ft_strlen(save);
		flags.output = ft_strnew(flags.bytes + 1);
		if (tmp)
		{
			flags.output = ft_strjoin(flags.output, tmp);
			ft_strdel(&tmp);
		}
		flags.output = ft_strjoin(flags.output, save);
		ft_strdel(&save);
	}
	write(1, flags.output, flags.bytes);
	ft_strdel(&flags.output);
	va_end(ap);
	return (flags.bytes);
}

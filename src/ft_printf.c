/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:32:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:27:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
	return (0);
}

/*
** [flags][min field width][precision][length][specifier]
*/

char	*ft_handle(char **str, t_flags *flags, va_list ap)
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

char	*ft_handle_space(char **str, t_flags *flags)
{
	int 	i;
	char	*save;

	i = 0;
	while ((*str)[i] != '%' && (*str)[i])
		i++;
	if (!(save = (char*)malloc(sizeof(char) * (i + 1))))
		ft_error();
	save = ft_strncpy(save, *str, i);
	*str = (*str) + i - 1;
	flags->bytes += i;
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
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			save = ft_handle(&str, &flags, ap);
		}
		else
			save = ft_handle_space(&str, &flags);
		str++;
		tmp = flags.output;
		flags.output = ft_strjoin(flags.output, tmp);
		flags.output = ft_strjoin(flags.output, save);
		ft_strdel(&tmp);
		ft_strdel(&save);
	}
	write(1, save, flags.bytes + 1);
	va_end(ap);
	return (flags.bytes);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:32:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 15:28:22 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Check specifier and run function for this specifier
*/

static int	ft_check_specifier(char **str, t_flags *flags, va_list ap,
		char **save)
{
	int bytes;

	bytes = -1;
	bytes = **str == '%' ? ft_percent(flags, save) : bytes;
	bytes = **str == 's' ? ft_str(ap, flags, 0, save) : bytes;
	bytes = **str == 'S' ? ft_str(ap, flags, 1, save) : bytes;
	bytes = **str == 'd' || **str == 'i' ? ft_int(ap, flags, save) : bytes;
	bytes = **str == 'c' ? ft_char(ap, flags, 0, save) : bytes;
	bytes = **str == 'C' ? ft_char(ap, flags, 1, save) : bytes;
	bytes = **str == 'f' || **str == 'F' ? ft_double(ap, flags, save) : bytes;
	bytes = **str == 'u' || **str == 'U' ? ft_uint(ap, flags, **str, save)
		: bytes;
	bytes = **str == 'x' ? ft_hex(ap, flags, 32, save) : bytes;
	bytes = **str == 'X' ? ft_hex(ap, flags, 0, save) : bytes;
	bytes = **str == 'o' ? ft_octal(ap, flags, save) : bytes;
	bytes = **str == 'b' ? ft_binary(ap, flags, save) : bytes;
	if (bytes != -1)
		return (bytes);
	(*str)--;
	*save = ft_strnew(0);
	return (0);
}

/*
** save all flags
** [flags][min field width][precision][length][specifier]
*/

static int	ft_handle(char **str, t_flags *flags, va_list ap, char **save)
{
	if (!(**str) || !(*str))
	{
		(*str)--;
		*save = ft_strnew(0);
		return (0);
	}
	ft_init_flags(flags);
	while (ft_handle_flags(str, flags) || ft_handle_width(str, flags, ap) ||
			ft_handle_precision(str, flags, ap) || ft_handle_length(str, flags))
		;
	if (**str && (ft_isalpha(**str) || **str == '%'))
		return (ft_check_specifier(str, flags, ap, save));
	if (!(**str) || !(*str))
		(*str)--;
	*save = ft_strnew(0);
	return (0);
}

/*
** handle string before %
*/

static int	ft_handle_string(char **str, char **save)
{
	int		i;

	i = 0;
	while ((*str)[i] && (*str)[i] != '%')
		i++;
	if (!(*save = ft_strnew(i)))
		ft_error();
	*save = ft_strncpy(*save, *str, i);
	*str = (*str) + i - 1;
	return (i);
}

/*
** just for more space in ft_printf
*/

static void	ft_space(char **str, t_flags *flags, va_list ap)
{
	char	*save;
	char	*tmp;
	int		bytes;

	if (**str == '%')
	{
		(*str)++;
		bytes = ft_handle(str, flags, ap, &save);
	}
	else
		bytes = ft_handle_string(str, &save);
	(*str)++;
	tmp = flags->output;
	flags->output = ft_strnew(flags->bytes + bytes);
	flags->output = ft_strnjoin(flags->output, tmp, flags->bytes, 0);
	ft_strdel(&tmp);
	flags->output = ft_strnjoin(flags->output, save, bytes, flags->bytes);
	flags->bytes += bytes;
	ft_strdel(&save);
}

int			ft_printf(char *str, ...)
{
	va_list	ap;
	t_flags	flags;

	va_start(ap, str);
	flags.bytes = 0;
	flags.output = ft_strnew(flags.bytes);
	while (*str)
		ft_space(&str, &flags, ap);
	write(1, flags.output, flags.bytes);
	ft_strdel(&flags.output);
	va_end(ap);
	return (flags.bytes);
}

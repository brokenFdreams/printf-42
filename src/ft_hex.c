/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:10:58 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/09 12:39:45 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allcate new string, fill it '0'/'#' at the end/strat/after#
** return the index, where we're gona place our nbr
*/

static int	ft_hex_width(char **save, int length, t_flags *flags)
{
	int i;

	length = length > flags->precision ? length : flags->precision;
	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = flags->zero && !flags->minus && flags->hash && flags->precision < 0
		? 2 : 0;
	if (!(flags->zero && !flags->minus && flags->precision < 0) && flags->hash)
		length += 2;
	while (length + i < flags->width)
		if (flags->minus)
			(*save)[length++] = ' ';
		else
			(*save)[i++] = flags->zero && flags->precision < 0 ? '0' : ' ';
	return (flags->zero && !flags->minus && flags->precision < 0 ? 0 : i);
}

/*
** Allocate new string, fill flags and return result
** size = full size of string (nbr + hash)
*/

int			ft_hex_flags(char **nbr, t_flags *flags, int flag, char **save)
{
	int		size;
	int		length;
	int		i;

	length = !flags->precision && (*nbr)[0] == '0' ? 0 : ft_strlen(*nbr);
	size = length < flags->precision ? flags->precision : length;
	size += flags->hash ? 2 : 0;
	if (!(i = 0) && size < flags->width)
		i = ft_hex_width(save, length, flags);
	else if (!(*save = ft_strnew(size)))
		ft_error();
	if (flags->hash)
	{
		(*save)[i++] = '0';
		(*save)[i++] = !flag ? 'X' : 'x';
	}
	while (length < flags->precision && length++)
		(*save)[i++] = '0';
	*save = ft_strnjoin(*save, *nbr, length, i);
	while (flag && (*save)[i++])
		(*save)[i - 1] += ft_isalpha((*save)[i - 1]) ? flag : 0;
	ft_strdel(nbr);
	return (size < flags->width ? flags->width : size);
}

/*
** Read int convert it to the desired type (check length flag)
** convert int to hex and return its value in the string using flags
*/

int			ft_hex(va_list ap, t_flags *flags, int flag, char **save)
{
	char *num;

	num = ft_uint_itoa(ft_get_uint(ap, flags), 16);
	flags->hash = num[0] == '0' ? 0 : flags->hash;
	return (ft_hex_flags(&num, flags, flag, save));
}

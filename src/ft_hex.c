/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:10:58 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 16:43:03 by fsinged          ###   ########.fr       */
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

	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = flags->zero && !flags->minus && flags->hash ? 2 : 0;
	if ((!flags->zero && !flags->minus && flags->hash) ||
		(flags->minus && flags->hash))
		length += 2;
	while (length + i < flags->width)
		if (flags->minus)
			(*save)[length++] = ' ';
		else
			(*save)[i++] = flags->zero ? '0' : ' ';
	return (flags->zero && !flags->minus && flags->hash ? 0 : i);
}

/*
** Allocate new string, fill flags and return result
** size = full size of string (nbr + hash)
*/

static char	*ft_hex_flags(char *nbr, t_flags *flags, int flag)
{
	char	*save;
	int		size;
	int		length;
	int		i;

	if (flags->precision == 0 && nbr[0] == '0')
		ft_strdel(&nbr);
	else if (nbr[0] == '0')
		flags->hash = 0;
	length = ft_strlen(nbr);
	size = flags->hash && nbr != NULL ? length + 2 : length;
	if (!(i = 0) && size < flags->width)
		i = ft_hex_width(&save, length, flags);
	else if (!(save = ft_strnew(size)))
		ft_error();
	if (nbr == NULL)
		return (save);
	if (flags->hash)
	{
		save[i++] = '0';
		save[i++] = !flag ? 'X' : 'x';
	}
	save = ft_strncat(save, nbr, length);
	while (flag && save[i])
	{
		save[i] += ft_isalpha(save[i]) ? flag : 0;
		i++;
	}
	ft_strdel(&nbr);
	return (save);
}

/*
** Read int convert it to the desired type (check length flag)
** convert int to hex and return its value in the string using flags
*/

char		*ft_hex(va_list ap, t_flags *flags, int flag)
{
	return (ft_hex_flags(ft_uint_itoa(ft_get_uint(ap, flags), 16),
					flags, flag));
}

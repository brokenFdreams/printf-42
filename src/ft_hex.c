/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:10:58 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 17:00:09 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allcate new string, fill it '0'/'#' at the end/strat/after#
** return the index, where we're gona place our nbr
*/

static int	ft_hex_width(char **save, int size, t_flags *flags)
{
	int i;

	size -= flags->hash ? 2 : 0;
	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = 0;
	while (size + i < flags->width)
		if (flags->minus)
			(*save)[size++] = ' ';
		else
			(*save)[i++] = flags->zero ? '0' : ' ';
	return (flags->hash && !flags->minus ? i - 2 : i);
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

	length = ft_strlen(nbr);
	size = flags->hash ? length + 2 : length;
	i = 0;
	if (size < flags->width)
		i = ft_hex_width(&save, size, flags);
	else if (!(save = ft_strnew(size)))
		ft_error();
	if (flags->hash)
	{
		save[i++] = '0';
		save[i++] = !flag ? 'X' : 'x';
	}
		while (!falg && nbr[i])
		{
			nbr[i] += ft_isalpha(nbr[i]) ? flag : 0;
			i++;
		}
	save = ft_strjoin(save, nbr);
	ft_strdel(&nbr);
	return (save);
}

/*
** Read int convert it to the desired type (check length flag)
** convert int to hex and return its value in the string using flags
*/

char		*ft_hex(va_list ap, t_flags *flags, int flag)
{
	uintmax_t nbr;

	if (flags->length == LENGTH_HH)
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (flags->length == LENGTH_H)
		nbr = (unsigned short int)va_arg(ap, unsigned int);
	else if (flags->length == LENGTH_LL)
		nbr = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (flags->length == LENGTH_L)
		nbr = (unsigned long int)va_arg(ap, unsigned long int);
	else if (flags->length == LENGTH_J)
		nbr = va_arg(ap, uintmax_t);
	else if (flags->length == LENGTH_Z)
		nbr = va_arg(ap, size_t);
	else
		nbr = va_arg(ap, unsigned int);
	return (ft_hex_flags(ft_uint_itoa(nbr, 16), flags, flag));
}

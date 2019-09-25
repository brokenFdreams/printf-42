/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:32:43 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 15:22:01 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill it '0'/' ' at the end/start width - size times
** function also calls in ft_double
** return the index. where we're gona place our nbr
*/

int	ft_int_width(char **save, int length, t_flags *flags, int sign)
{
	int i;

	length = length > flags->precision ? length : flags->precision;
	length += flags->minus && (flags->plus || sign == -1 || flags->space)
		? 1 : 0;
	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = 0;
	while (length + i < flags->width)
		if (!flags->minus)
			(*save)[i++] = (flags->zero && flags->precision < 0) ? '0' : ' ';
		else
			(*save)[length++] = ' ';
	if ((flags->zero && flags->precision < 0)
		|| flags->minus)
		return (0);
	else if (sign == -1 || flags->plus)
		return (i - 1);
	return (i);
}

/*
** Allocate new string, fill flags and return size of save
** size = full size of string (nbr + sign)
** this function calls in ft_uint
*/

int	ft_int_flags(char **nbr, t_flags *flags, int sign, char **save)
{
	int		size;
	int		length;
	int		i;
	int		lengthcopy;

	length = flags->precision == 0 && (*nbr)[0] == '0' ? 0 : ft_strlen(*nbr);
	length = (*nbr)[0] == '\0' && (*nbr)[1] == 127 ? 1 : length;
	size = length < flags->precision ? flags->precision : length;
	size += (flags->plus || sign == -1 || flags->space) ? 1 : 0;
	if (!(i = 0) && size < flags->width)
		i = ft_int_width(save, length, flags, sign);
	else if (!(*save = ft_strnew(size)))
		ft_error();
	if (sign == -1)
		(*save)[i++] = '-';
	else if (flags->plus)
		(*save)[i++] = '+';
	else if (flags->space)
		(*save)[i == 0 ? i++ : 0] = ' ';
	lengthcopy = length;
	while ((*nbr)[0] != '\0' && length < flags->precision && length++)
		(*save)[i++] = '0';
	*save = ft_strnjoin(*save, *nbr, lengthcopy, i);
	ft_strdel(nbr);
	return (size < flags->width ? flags->width : size);
}

/*
** Read int, convert it to the desired type (check length flag)
** and return size of save
** ft_itoa_uint in file ft_uint.c
*/

int	ft_int(va_list ap, t_flags *flags, char **save, char c)
{
	intmax_t	nbr;
	int			sign;
	char		*num;

	if (c == 'D' || c == 'I')
		flags->length = flags->length == 0 ? LENGTH_L : flags->length + 1;
	if (flags->length == LENGTH_HH)
		nbr = (char)va_arg(ap, int);
	else if (flags->length == LENGTH_H)
		nbr = (short int)va_arg(ap, int);
	else if (flags->length == LENGTH_LL)
		nbr = (long long int)va_arg(ap, long long int);
	else if (flags->length == LENGTH_L)
		nbr = (long int)va_arg(ap, long int);
	else if (flags->length == LENGTH_J)
		nbr = (intmax_t)va_arg(ap, intmax_t);
	else if (flags->length == LENGTH_Z)
		nbr = (size_t)va_arg(ap, size_t);
	else
		nbr = (int)va_arg(ap, int);
	sign = nbr < 0 ? -1 : 1;
	num = ft_uint_itoa(nbr * sign, 10);
	return (ft_int_flags(&num, flags, sign, save));
}

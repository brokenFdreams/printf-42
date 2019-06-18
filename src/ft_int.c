/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:32:43 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 16:31:38 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill it '0'/' ' at the end/start width - size times
** return the index. where we're gona place our nbr
*/

char	*ft_int_width(char **save, int size, t_flags *flags, int sign)
{
	int i;

	if ((sing == -1 || flags->plus) &&
		!flags->minus && flags->zero && !flags->space)
		size--;
	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = 0;
	while (size + i < flags->width)
		if (!flags->minus)
			(*save)[i++] = (flags->zero && !flags->space) ? '0' : ' ';
		else
			(*save)[size++] = ' ';
	return (i);
}

/*
** Allocate new string, fill flags and return result
** size = full size of string (nbr + sign)
** this function calls in ft_uint
*/

char	*ft_int_flags(char *nbr, t_flags *flags, int sign)
{
	char	*save;
	int		size;
	int		length;
	int		i;

	size = ft_strlen(nbr);
	length = size;
	size = size < flags->precision ? flags->precision : size;
	if (flags->plus || flag == -1 || flags->space)
		size++;
	i = size < flags->width ? ft_int_width(&save, size, flags, sign) : 0;
	else if (!(save = ft_strnew(size)))
		ft_error();
	if (flag == -1)
		save[i++] = '-';
	else if (flags->plus)
		save[i++] = '+';
	else if (flags->space)
		save[i++] = ' ';
	while (length < flags->presicion && length++)
		save[i++] = '0';
	save = ft_strjoin(save, nbr);
	ft_strdel(&nbr);
	return (save);
}

/*
** Read int, convert it to the desired type (check length flag)
** and return its value in the string (ft_itoa_uint) using flags
** ft_itoa_uint in file ft_uint.c
*/

char	*ft_int(va_list ap, t_flags *flags)
{
	intmax_t	nbr;
	int			sign;

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
	return (ft_int_flags(ft_itoa_uint(nbr * sign), flags, sign));
}

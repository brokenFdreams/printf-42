/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:32:43 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/21 15:07:48 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill it '0'/' ' at the end/start width - size times
** function also calls in ft_double
** return the index. where we're gona place our nbr
*/

int			ft_int_width(char **save, int size, t_flags *flags, int sign)
{
	int i;

	if ((sign == -1 || flags->plus) && !flags->minus && !flags->space
		&& flags->zero && flags->precision == -1)
		size--;
	if (!(*save = ft_strnew(flags->width)))
		ft_error();
	i = 0;
	while (size + i < flags->width)
		if (!flags->minus)
			(*save)[i++] = (flags->zero && !flags->space &&
							flags->precision == -1) ? '0' : ' ';
		else
			(*save)[size++] = ' ';
	if (flags->zero && !flags->space && flags->precision == -1)
		return (0);
	return (i);
}

/*
** Allocate new string, fill flags and return result
** size = full size of string (nbr + sign)
** this function calls in ft_uint
*/

char		*ft_int_flags(char *nbr, t_flags *flags, int sign)
{
	char	*save;
	int		size;
	int		length;
	int		i;

	length = ft_strlen(nbr);
	size = length < flags->precision ? flags->precision : length;
	size += (flags->plus || sign == -1 || flags->space) ? 1 : 0;
	if (!(i = 0) && size < flags->width)
		i = ft_int_width(&save, size, flags, sign);
	else if (!(save = ft_strnew(size)))
		ft_error();
	if (flags->precision == 0 && nbr[0] = '0') //<- new code!!
		nbr[0] = '\0'; //<-new code!!
	else if (sign == -1) //<- HERE
		save[i++] = '-';
	else if (flags->plus)
		save[i++] = '+';
	else if (flags->space)
		save[0] = ' ';
	while (length < flags->precision && length++)
		save[i++] = '0';
	save = ft_strcat(save, nbr);
	ft_strdel(&nbr);
	return (save);
}

/*
** Read int, convert it to the desired type (check length flag)
** and return its value in the string (ft_itoa_uint) using flags
** ft_itoa_uint in file ft_uint.c
*/

char		*ft_int(va_list ap, t_flags *flags)
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
	return (ft_int_flags(ft_uint_itoa(nbr * sign, 10), flags, sign));
}

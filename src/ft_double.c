/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:14:52 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/09 14:21:20 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static int	ft_double_flags(char **nbr, int sign, t_flags *flags, char **save)
{
	int	size;
	int	length;
	int	i;

	length = ft_strlen(*nbr);
	size = (sign == -1 || flags->plus || flags->space) ? length + 1 : length;
	i = 0;
	if (size < flags->width)
		i = ft_int_width(save, size, flags, sign);
	else if (!(*save = ft_strnew(size)))
		ft_error();
	if (sign == -1)
		(*save)[i] = '-';
	else if (flags->plus)
		(*save)[i] = '+';
	else if (flags->space)
		(*save)[0] = ' ';
	*save = ft_strnjoin(*save, *nbr, length, i);
	ft_strdel(nbr);
	return (size < flags->width ? flags->width : size);
}

/*
** Read double, convert it to the desired type (check length)
*/

int			ft_double(va_list ap, t_flags *flags, char **save)
{
	long double	nbr;
	int			sign;
	char		*num;

	if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	sign = nbr >= 0 ? 1 : -1;
	flags->precision = flags->precision == -1 ? 6 : flags->precision;
	num = ft_double_itoa(nbr * sign, flags->precision);
	return (ft_double_flags(&num, sign, flags, save));
}

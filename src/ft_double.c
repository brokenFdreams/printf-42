/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:14:52 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/16 14:20:40 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static int	ft_double_flags(char **nbr, t_flags *flags, int sign, char **save)
{
	int	size;
	int	length;
	int	i;

	length = ft_strlen(*nbr);
	size = (sign == -1 || flags->plus || flags->space) ? length + 1 : length;
	i = 0;
	if (size < flags->width)
		i = ft_int_width(save, length, flags, sign);
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
	flags->precision = flags->precision == -1 ? 6 : flags->precision;
	num = ft_double_itoa(nbr, flags, &sign);
	flags->precision = -1;
	return (ft_double_flags(&num, flags, sign, save));
}

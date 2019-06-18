/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 14:45:00 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** itoa for double, there we're count integer and remainder
** then return result of function 
*/

static char	*ft_itoa_double(long double nbr, t_flags *flags)
{
	intmax_t	num;
	uintmax_t	ost;
	int			precision;

	num = (intmax_t)nbr;
	nbr -= num;
	ost = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	else if (flags->precision == 0 &&
			 ((int)(nbr * 10) > 5 || ((int)(nbr * 10) == 5 && num % 2 != 0)))
		return (ft_flags_double(ft_itoa_int(num + 1, flags),
								ft_itoa_uint(ost), flags));
}

/*
** Read double, convert it to the desired type (check length)
** and return its value in the string using flags
** flags - [+-# 0][width][precision][length(l, L)]
*/

char		*ft_get_double(va_list ap, t_flags *flags)
{
	long double nbr;

	if (flags->length == LENGTH_L)
		nbr = va_arg(ap, double);
	else if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, float);
	return (ft_itoa_double(nbr, flags));
}

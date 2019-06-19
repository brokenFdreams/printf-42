/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 14:05:11 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static char	*ft_double_flags(char *nbr, int sign, t_flags *flags)
{
	char	*save;
	
}

/*
** rounding integer and remainder
** nothing to return
*/

static void	ft_double_rounding(intmax_t *num, uintmax_t *rem, t_flags *flags)
{
	if ((flags->precision == 0 &&
		((int)(nbr * 10) > 5 || ((int)(nbr * 10) == 5 && num % 2 != 0))) ||
		(flags->precision > 0 && (ost + 1) % 10 == 0 &&
		(((int)(nbr * 10) == 5 && ost % 2 != 0) || (int)(nbr * 10) > 5)))
	{
		(*num)++;
		(*ost) = 0;
	}
	else if (flags->presicion > 0 &&
			(((int)(nbr * 10) == 5 && ost % 2 != 0) || (int)(nbr * 10) > 5))
		(*ost)++;
}

/*
** Allocate new string, writes a double to the string
** by gluing the integer like a string and the remainder
** return double in the string with rounding
*/

static char	*ft_double_itoa(intmax_t num, uintmax_t rem, t_flags *flags)
{
	char	*nbr;
	char	*integer;
	char	*remainder;

	ft_double_rounding(&num, &rem, flags);
	integer = num > 0 ? ft_uint_itoa(num) : ft_uint_itoa(num * -1);
	remainder = ft_uint_itoa(rem);
	size = ft_strlen(integer) + ft_strlen(remainder);
	size += flags->presicion == 0 ? 0 : 1;
	nbr = ft_strnew(size);
	nbr = ft_strjoin(integer);
	if (flags->precision > 0)
	{
		nbr = ft_strjoin(".");
		nbr = ft_strjoin(ft_remainder);
	}
	ft_strdel(&integer);
	ft_strdel(&remainder);
	return (nbr);
}

/*
** Count integer and remainder for separate double
** then return result of ft_double_itoa
*/

static char	*ft_double_separation(long double nbr, t_flags *flags)
{
	intmax_t	num;
	uintmax_t	rem;
	int			precision;
	int			sign;

	sign = nbr > 0 ? 1 : -1;
	num = (intmax_t)nbr;
	nbr -= num;
	rem = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	precision = flags->precision;
	nbr *= nbr < 0 ? -1 : 1;
	while (precision-- > 0)
	{
		nbr = nbr * 10;
		rem = rem * 10 + (unsigned int)nbr;
		nbr -= (int)nbr;
	}
	return (ft_double_flags(ft_double_itoa(num, rem, flags), sign, flags));
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
	return (ft_double_separation(nbr, flags));
}

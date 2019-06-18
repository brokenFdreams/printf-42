/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 17:19:51 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static char	*ft_double_flags(char *nbr, t_flags *flags)
{

}

/*
** Allocate new string, write down our double with rounding it
** return double in the string with rounding
*/

static char	*ft_double_itoa(intmax_t num. uintmax_t rem, t_flags *flags)
{
	if (flags->precision == 0 && 
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
	return (ft_double_flags(ft_double_itoa(nbr, rem, flags)), flags);
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

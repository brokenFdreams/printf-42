/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 13:16:52 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static int	ft_double_flags(char **nbr, int sign, t_flags *flags, char **save)
{
	int		size;
	int		length;
	int		i;

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
** rounding integer and remainder
** nothing to return
*/

static void	ft_double_rounding(intmax_t *num, uintmax_t *rem, t_flags *flags)
{
	if ((flags->precision == 0 && (*rem > 5 || (*rem == 5 && *num % 2 != 0)))
		|| (flags->precision > 0 && *rem % 10 == 5 && (*rem + 5) % 100 == 0 &&
		(*rem % 2 != 0 || *rem % 10 > 5)))
	{
		(*num)++;
		*rem = 0;
	}
	else if (flags->precision > 0 &&
			((*rem % 10 == 5 && *rem % 2 != 0) || *rem % 10 > 5))
		*rem = *rem + 10;
	*rem = *rem / 10;
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
	int		size;

	ft_double_rounding(&num, &rem, flags);
	integer = num > 0 ? ft_uint_itoa(num, 10) : ft_uint_itoa(-1 * num, 10);
	remainder = ft_uint_itoa(rem, 10);
	size = ft_strlen(integer) + flags->precision;
	size += flags->precision == 0 ? 0 : 1;
	nbr = ft_strnew(size);
	nbr = ft_strcat(nbr, integer);
	if (flags->precision > 0)
	{
		nbr = ft_strcat(nbr, ".");
		nbr = ft_strcat(nbr, remainder);
	}
	ft_strdel(&integer);
	ft_strdel(&remainder);
	return (nbr);
}

/*
** Count integer and remainder for separate double
** then return result of ft_double_itoa
*/

static int	ft_double_separation(long double nbr, t_flags *flags, char **save)
{
	intmax_t	num;
	uintmax_t	rem;
	int			precision;
	int			sign;
	char		*snum;

	sign = nbr > 0 ? 1 : -1;
	num = (intmax_t)nbr;
	nbr -= num;
	rem = 0;
	if (flags->precision == -1)
		flags->precision = 6;
	precision = flags->precision;
	nbr *= nbr < 0 ? -1 : 1;
	while (precision-- >= 0)
	{
		nbr = nbr * 10;
		rem = rem * 10 + (unsigned int)nbr;
		nbr -= (int)nbr;
	}
	snum = ft_double_itoa(num, rem, flags);
	return (ft_double_flags(&snum, sign, flags, save));
}

/*
** Read double, convert it to the desired type (check length)
** and return its value in the string using flags
** flags - [+-# 0][width][precision][length(l, L)]
*/

int			ft_double(va_list ap, t_flags *flags, char **save)
{
	long double nbr;

	if (flags->length == LENGTH_L)
		nbr = va_arg(ap, double);
	else if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = (float)va_arg(ap, double);
	return (ft_double_separation(nbr, flags, save));
}

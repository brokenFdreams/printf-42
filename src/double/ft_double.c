/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/03 13:31:33 by fsinged          ###   ########.fr       */
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
** Count remainder of double in binary system
** return its value in string
*/

static char	*ft_double_rembinary(long double nbr, size_t size)
{
	char	*rem;
	size_t	i;

	if (!(rem = ft_strnew(size)))
		ft_error();
	nbr = nbr - (intmax_t)nbr;
	i = 0;
	while (i < size)
	{
		nbr *= 2;
		rem[i++] = nbr >= 1 ? '1' : '0';
		nbr = nbr >= 1 ? nbr - 1 : nbr;
	}
	return (rem);
}

/*
** Count mantissa
** Return exponent
*/

static int	ft_double_mantissa(long double nbr, char **mantissa)
{
	size_t	size;
	int		exponent;
	char	*integer;
	char	*remnder;

	if (!(*mantissa = ft_strnew(65)))
		ft_error();
	integer = ft_uint_itoa(nbr, 2);
	if (integer[0] == '1')
		*mantissa = ft_strcat(*mantissa, integer);
	size = integer[0] == '1' ? ft_strlen(integer) : 0;
	remnder = ft_double_rembinary(nbr, 65 - size);
	*mantissa = ft_strnjoin(*mantissa, remnder, 65 - size, size);
	ft_strdel(&integer);
	ft_strdel(&remnder);
	if (size)
		return (size);
	while ((*mantissa)[size] == '0')
	{
		exponent--;
		size++;
	}
	return (exponent);
}

/*
** check for +/-inf, +/-0 and NaN
** Return if fond anuthing from list upper ^
*/

static void	ft_double_except(char *binary, char **num, int exp)
{
	int	i;
	int	mantissa;

	i = 0;
	while (i < 65 && binary[i] == '0')
		i++;
	mantissa = i == 65 ? 0 : -1;
	i = 0;
	while (i < 65 && binary[i] == '1')
		i++;
	mantissa = i == 65 ? 1 : mantissa;
	if (exp == 0 && mantissa == 0)
		*num = ft_strjoin("", "0");
	else if (exp == 1 && mantissa == 0)
		*num = ft_strjoin("", "INF");
}

/*
** Read double, convert it to the desired type (check length)
** and return its value in the string using flags
** flags - [+-# 0][width][precision][length(l, L)]
*/

int			ft_double(va_list ap, t_flags *flags, char **save)
{
	long double nbr;
	int			sign;
	int			exponent;
	char		*mantissa;
	char		*num;

	if (flags->length == LENGTH_L)
		nbr = va_arg(ap, double);
	else if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	sign = nbr >= 0 ? 1 : -1;
	exponent = ft_double_mantissa(nbr, &mantissa);
	if (exponent == 0)
		ft_double_except(mantissa, &num, 0);
	else if (exponent == 16383)
		ft_double_except(mantissa, &num, 1);
	if (nbr != nbr)
		*save = ft_strjoin("", "NaN")
	if (!num)
		num = ft_double_itoa(mantissa, exponent);
	ft_strdel(&mantissa);
	return (ft_double_flags(&num, sign, flags, save));
}

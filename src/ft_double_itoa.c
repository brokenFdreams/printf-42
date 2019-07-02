/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:50:28 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/02 17:39:55 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_print.h"

/*
** Count remainder of double
** return its value in string
*/

static char	*ft_double_rembinary(long double nbr, size_t size)
{
	char		*rem;
	long double	remnder;
	size_t		i;

	if (!(rem = ft_strnew(size)))
		ft_error();
	remnder = nbr - (intmaxt_t)nbr;
	i = 0;
	while (i < size)
	{
		nbr *= 2;
		remnder[i++] = nbr >= 1 ? '1' : '0';
		nbr = nbr >= 1 ? nbr - 1 : nbr;
	}
	return (remnder);
}

/*
** Count mantissa
** Return exponent
*/

static int	*ft_double_mantissa(long double nbr, char **mantissa)
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
	*mantissa = ft_strnjoin(*mantissa, remainder, 65 - size, size);
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

static char	*ft_double_except(char *binary, char **num, int exp)
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
		return ((*num = ft_strjoion("", "0")));
	else if (exp == 1 && mantissa == 0)
		return ((*num = ft_strjoin("", "INF")));
	return (NULL);
}

/*
** Plus remainder
*/

static void ft_double_plusrem(char **num, int size)
{
	char *fund;

	if (size = 0)
	{
		if (!(fund = ft_strjoin("0", *num)))
			ft_error();
		ft_strdel(num);
		(*num) = fund;
	}
	if ((*num)[size] == 9)
	{
		(*num)[size] = '0';
		ft_double_plusrem(*num, size - 1);
	}
	else if ((*num)[size] == '.')
		ft_double_plusrem(*num, size - 1);
	else
		(*num)[size] += 1;	
}

/*
** Addition in the string
** Return its value
*/

static void	ft_double_addition(char **num, char *tmp, int size, int len)
{
	int a;
	int b;

	b = 0;
	while (size >= 0 && len >= 0 && (*num)[size] != '.')
	{
		if (ft_isdigit((*num)[size]))
			a = (*num)[size] - '0';
		else
			a = 0;
		b += tmp[len--] - '0';
		a = a + b;
		b = a > 10 ? 1 : 0;
		(*num)[size--] = a > 10 ? a % 10 + '0' : a + '0';
	}
	if (b)
		ft_double_plusrem(num, size);
}

/*
** Revert double to decemical in string
** Return its value
*/

static void	ft_double_revert(char *mantissa, char **num, int exponent)
{
	char		*tmp;
	char		*remainder;
	uintmax_t	power;
	size_t		i;
	int			size;
	int			a;
	int			dot;
	int			len;

	size = 652;
	if (!(num = ft_strnew(size)))
		ft_error();
	power = ft_exponentiation(exponent, 2);
	i = 0;
	while (i < exponent)
	{
		tmp = ft_uint_itoa(power * (mantissa[i] - '0'));
		len = ft_strlen(tmp) - 1;
		ft_double_addition(num, tmp, len, len);
		i++;
		power /= 2;
		ft_strdel(&tmp);
	}
	i = ft_strlen(*num);
	(*num)[i] = '.';
	dot = i - 1;
	power = 5;
	while (i < size)
	{
		tmp = ft_uint_itoa(power * (mantissa[i] - '0'));
		len = ft_strlen(tmp);
		ft_double_addition(num, tmp, i, len);
		power *= 5;
		i++;
	}
}

/*
** Itoa for double
** Convert double to binary mantissa:65bit, and count exponent
*/

char		*ft_double_itoa(long double nbr)
{
	char	*num;
	char	*mantissa;
	int		size;
	int		exponent;

	nbr *= nbr >= 0 ? 1 : -1;
	exponent = ft_double_mantissa(nbr, &mantissa);
	if (exponent == 0 && ft_double_except(mantissa, &num, 0))
		return (num);
	else if (exponent == 16383 && ft_double_except(mantissa, &num, 1))
		return (num);
	if (nbr != nbr)
		return (ft_strjoin("", "NAN"));
	num = ft_double_revert(mantissa, &num, exponent);

	ft_strdel(&mantissa);
	return (num);
}

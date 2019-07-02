/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:50:28 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/02 15:45:36 by fsinged          ###   ########.fr       */
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

static char	*ft_double_revert(char *mantissa, char **num, int exponent)
{
	char	*integer;
	size_t	i;
	size_t	power;

	if (exponent >= 0)
	{
		if (!(integer = ft_strnew(652)))
			ft_error();
		i = 0;
		while (i < exponent)
			i++;
		integer =
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

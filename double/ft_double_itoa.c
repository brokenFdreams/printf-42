/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:33:26 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/03 15:40:54 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Check exceptions as +/-inf, +/-0
*/

static void	*ft_double_except(char *mantissa, char **num, int exp)
{
	int i;
	int mantisaa;

	i = 0;
	while (i < 65 && mantissa[i] == '0')
		i++;
	mantissa = i == 65 ? 0 : -1;
	i = 0;
	while (i < 65 && mantissa[i] == '1')
		i++;
	mantissa = i == 65 ? 1 : mantissa;
	if (exp == 0 && mantissa == 0)
		*num = ft_strjoin("", "0");
	else if (exp == 1 && mantissa == 0)
		*num = ft_strjoin("", "INF");
}

/*
** Get remainder in binary system to add to mantissa
*/

static char	*ft_double_remnder(long double nbr, int size)
{
	char	*rem;
	int		i;

	if (!(rem = ft_strnew(size)))
		ft_error();
	nbr = nbr - (intmax_t)nbr;
	i = 0;
	while (i < size)
	{
		nbr *= 2;
		rem[i++] = nbr >= 1 ? '1' : '0';
		nbr = nbr >= 1 ? nbr - 1.0 : nbr;
	}
	return (rem);
}

/*
** Get mantissa (convert double to binary)
** return exponent
*/

static int	ft_double_mantissa(long double nbr, char **mantissa)
{
	int		size;
	int		exponent;
	char	*integer;
	char	*remnder;

	if (!(*mantissa = ft_strnew(65)))
		ft_error();
	integer = ft_uint_itoa(nbr, 2);
	size = integer[0] == '1' ? ft_strlen(integer) : 0;
	*mantissa = ft_strnjoin(*mantissa, integer, 0, size);
	remnder = ft_double_remnder(nbr, 65 - size);
	*mantissa = ft_strnjoin(*mantissa, remnder, 65 - size, size);
	if (size)
		return (size - 1);
	exponent = 0;
	while ((*mantissa)[size] == '0')
	{
		exponent--;
		size++;
	}
	return (exponent);
}

/*
** Itoa for double
*/

char	*ft_double_itoa(long double nbr, int precision)
{
	char	*mantissa;
	char	*num;
	int		exponent;

	exponent = ft_double_mantissa(nbr, &mantissa);
	num = NULL;
	if (exponent == 0)
		ft_double_except(mantissa, &num, 0);
	else if (exponent == 16383)
		ft_double_except(mantissa, &num, 1);
	else if (nbr != nbr)
		num = ft_strjoin("", "NAN");
	if (!num)
		ft_double_revert(mantissa, &num, exponent, precision);
	ft_strdel(&mantissa);
	return (num);
}

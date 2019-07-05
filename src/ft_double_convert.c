/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/05 16:26:24 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Plus remainder
*/

static void	ft_double_plusrem(char *num, int size)
{
	if (num[size] == '9')
	{
		num[size] = '0';
		ft_double_plusrem(num, size - 1);
	}
	else if (num[size] == '.')
		ft_double_plusrem(num, size - 1);
	else if (num[size] == '\0')
		num[size] = '1';
	else
		num[size] += 1;
}

/*
** Addition number in string
*/

static void	ft_double_addition(char *num, char **tmp, int size, int len)
{
	int a;
	int b;

	b = 0;
	while (size >= 0 && len >= 0 && num[size] != '.')
	{
		if (ft_isdigit(num[size]))
			a = num[size] - '0';
		else
			a = 0;
		b += (*tmp)[len--] - '0';
		a = a + b;
		b = a >= 10 ? 1 : 0;
		num[size--] = a >= 10 ? a % 10 + '0' : a + '0';
	}
	if (b)
		ft_double_plusrem(num, size);
	ft_strdel(tmp);
}

/*
** Revert integer of double to decemical using string
*/

int	ft_double_i(char *mantissa, char **integer, int exponent)
{
	uintmax_t	power;
	char		*tmp;
	int			i;
	int			len;
	int			size;

	i = 0;
	power = ft_exponentiation(exponent, 2);
	tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
	size = ft_strlen(tmp);
	if (!(*integer = ft_strnew(size + 1)))
		ft_error();
	ft_double_addition(*integer, &tmp, size, size - 1);
	power /= 2;
	while (power > 0)
	{
		tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
		len = ft_strlen(tmp);
		ft_double_addition(*integer, &tmp, size, len - 1);
		power /= 2;
	}
	return (i);
}

/*
** Revert remainder of double to decemical using string
*/

void	ft_double_r(char *mantissa, char **remainder, int precision, int exp)
{
	uintmax_t	power;
	char		*tmp;
	int			size;
	int			len;
	int			i;

	i = 0;
	power = 5;
	if (!(*remainder = ft_strnew(652)))
		ft_error();
	size = 1;
	while (exp++ <= 0)
		(*remainder)[size++] = '0';
	while (mantissa[i])
	{
		tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
		len = ft_strlen(tmp) - 1;
		ft_double_addition(*remainder, &tmp, size, len);
		size++;
		power *= 5;
	}
	while (size <= precision + 1)
		*remainder[size++] = '0';
	i = precision + 1;
	if ((*remainder)[i] == '5')
	{
		i++;
		while ((*remainder)[i] && (*remainder)[i] == '0')
			i++;
		if ((*remainder)[i] && (*remainder)[i] != '0')
			ft_double_plusrem(*remainder, precision);
	}
	else if ((*remainder)[i] > '5' && (*remainder)[i] <= '9')
			ft_double_plusrem(*remainder, precision);
	(*remainder)[precision + 1] = '\0';
}

/*
** Revert double to decemical using string
*/

void		ft_double_revert(char *mantissa, char **num, int exponent,
							 int precision)
{
	char	*integer;
	char	*remainder;
	int		i;
	int		size;

	i = exponent >= 0 ? ft_double_i(mantissa, &integer, exponent) : 0;
	mantissa = exponent >= 0 ? mantissa + i : mantissa;
	integer = exponent >= 0 && integer[i] == '\0' ? integer++ : NULL;
	size = exponent >= 0 ? ft_strlen(integer) + precision + 1 : precision + 2;
	if (!(*num = ft_strnew(size)))
		ft_error();
	*num = exponent >= 0 ? ft_strcat(*num, integer) : ft_strcat(*num, "0");
	if (exponent >= 0)
		ft_strdel(&integer);
	if (precision > 0)
	{
		*num = ft_strcat(*num, ".");
		ft_double_r(mantissa, &remainder, precision, exponent);
		if (remainder[0] != '\0')
			ft_double_plusrem(*num, ft_strlen(*num) - 2);
		remainder++;
		*num = ft_strcat(*num, remainder);
		ft_strdel(&remainder);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 15:50:28 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/03 12:59:46 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Plus remainder
*/

static void	ft_double_plusrem(char **num, int size)
{
	char *fund;

	if (size == 0)
	{
		if (!(fund = ft_strjoin("0", *num)))
			ft_error();
		ft_strdel(num);
		(*num) = fund;
	}
	if ((*num)[size] == 9)
	{
		(*num)[size] = '0';
		ft_double_plusrem(num, size - 1);
	}
	else if ((*num)[size] == '.')
		ft_double_plusrem(num, size - 1);
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
	int			len;

	size = 652;
	if (!(*num = ft_strnew(size)))
		ft_error();
	power = ft_exponentiation(exponent, 2);
	i = 0;
	while (i < exponent)
	{
		tmp = ft_uint_itoa(power * (mantissa[i] - '0'), 10);
		len = ft_strlen(tmp) - 1;
		ft_double_addition(num, tmp, len, len);
		i++;
		power /= 2;
		ft_strdel(&tmp);
	}
	i = ft_strlen(*num);
	(*num)[i] = '.';
	power = 5;
	while (i < size)
	{
		tmp = ft_uint_itoa(power * (mantissa[i] - '0'), 10);
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

char		*ft_double_itoa(char *mantissa, int exponent)
{
	int		size;
	char	*num;

	ft_double_revert(mantissa, &num, exponent);
	return (num);
}

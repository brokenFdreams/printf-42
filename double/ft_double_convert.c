/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/03 15:45:04 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Plus remainder
*/

static void	ft_double_plusrem(char **num, int size)
{
	char *fund;

	if (size == -1)
	{
		if (!(fund = ft_strjoin("0", *num)))
			ft_error();
		ft_strdel(num);
		(*num) = fund;
		size = 0;
	}
	if ((*num)[size] == '9')
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
** Addition number in string
*/

static void	ft_double_addition(char **num, char **tmp, int size, int len)
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
	ft_strdel(tmp);
}

/*
** Revert integer of double to decemical using string
*/

static int	ft_double_r(char *mantissa, char **num, uintmax_t power, int pres)
{

}

/*
** Revert double to decemical using string
*/

void	ft_double_revert(char *mantissa, char **num, int exponent, int precision)
{
	uintmax_t	power;
	int			i;

	power = exponent >= 0 ? ft_expotentiation(exponent, 2);
	i = ft_double_r(mantissa, num, exponent, precision);
	
}

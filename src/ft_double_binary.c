/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_binary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/15 10:55:41 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/15 15:24:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** atoi_base
*/

static int	ft_double_exponent(char **exponent)
{
	int exp;
	int i;
	int power;

	i = 14;
	power = 1;
	exp = 0;
	while (i >= 0)
	{
		exp += ((*exponent)[i--] - '0') * power;
		power *= 2;
	}
	ft_strdel(exponent);
	return (exp - 16383);
}

/*
** Write double in string
*/

int			ft_double_binary(long double nbr, char **mantissa)
{
	__uint128_t	nb;
	__uint128_t	one;
	char		*exponent;
	int			i;
	int			j;

	one = 1;
	one <<= 127;
	i = 0;
	j = 48;
	if (!(exponent = ft_strnew(15)))
		ft_error();
	if (!(*mantissa = ft_strnew(63)))
		ft_error();
	ft_memcpy(&nb, &nbr, 16);
	while (++j && i < 15)
		exponent[i++] = ((__uint128_t)(one & (nb << j)) >> 127) + '0';
	i = 0;
	while (i < 63)
	{
		(*mantissa)[i++] = ((__uint128_t)(one & (nb << j)) >> 127) + '0';
		j++;
	}
	return (ft_double_exponent(&exponent));
}

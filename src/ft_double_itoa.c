/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:33:26 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/16 13:24:20 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Check exceptions as +/-inf, +/-0
*/

static void	ft_double_except(char *mantissa, char **num, int exp)
{
	int i;
	int mant;

	i = 0;
	while (i < 63 && mantissa[i] == '0')
		i++;
	mant = i == 63 ? 0 : -1;
	i = 0;
	while (i < 63 && mantissa[i] == '1')
		i++;
	mant = i == 63 ? 1 : mant;
	if (exp == 0 && mant == 0)
		*num = ft_strjoin("", "0");
	else if (exp == 1 && mant == 0)
		*num = ft_strjoin("", "inf");
}

/*
** Itoa for double
*/

char		*ft_double_itoa(long double nbr, t_flags *flags, int *sign)
{
	char	*mantissa;
	char	*num;
	int		exponent;

	exponent = ft_double_binary(nbr, &mantissa, sign);
	num = NULL;
	if (exponent == 0)
		ft_double_except(mantissa, &num, 0);
	else if (exponent == 16383)
		ft_double_except(mantissa, &num, 1);
	else if (nbr != nbr)
		num = ft_strjoin("", "nan");
	if (!num)
		ft_double_revert(mantissa, &num, exponent, flags);
	ft_strdel(&mantissa);
	return (num);
}

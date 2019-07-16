/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:33:26 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/16 16:26:55 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Check exceptions as +/-inf, +/-0
*/

static void	ft_double_except(char *mantissa, char **num, int exp,
							t_flags *flags)
{
	int i;
	int mant;

	i = 1;
	while (i < 63 && mantissa[i] == '0')
		i++;
	mant = i == 63 ? 0 : -1;
	if (exp == 1 && mant == 0 && !(flags->zero = 0))
		*num = ft_strjoin("", "inf");
	else if (exp == 0 && mant == 0 && mantissa[0] == '0')
	{
		if (!(*num = ft_strnew(flags->precision + 2)))
			ft_error();
		*num = flags->precision || flags->hash ?
			ft_strcpy(*num, "0.") : ft_strcpy(*num, "0");
		i = 2;
		while (i < flags->precision + 2)
			(*num)[i++] = '0';
	}
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
	if (nbr != nbr && (*sign = 1))
	{
		flags->plus = 0;
		flags->space = 0;
		flags->zero = 0;
		num = ft_strjoin("", "nan");
	}
	else if (exponent == -16383)
		ft_double_except(mantissa, &num, 0, flags);
	else if (exponent == 16384 && mantissa)
		ft_double_except(mantissa, &num, 1, flags);
	if (!num)
		ft_double_revert(mantissa, &num, exponent, flags);
	ft_strdel(&mantissa);
	return (num);
}

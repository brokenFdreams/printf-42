/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/10 17:01:44 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Just some code from function ft_double_i, because there 25 lines
*/

static int	ft_double_ispace(char **integer)
{
	if (!(*integer = ft_strnew(1)))
		ft_error();
	(*integer)[0] = '0';
	return (0);
}

/*
** Rounding number remainder (used in ft_double_convert.c)
*/

static void	ft_double_rounding(char *rem, int precision)
{
	int i;

	i = precision + 1;
	if (rem[i] == '5')
	{
		i++;
		while (rem[i] && rem[i] == '0')
			i++;
		if ((rem[i] && rem[i] != '0') ||
			(rem[precision] - '0') % 2 != 0)
			ft_double_plusrem(rem, precision);
	}
	else if (rem[i] > '5' && rem[i] <= '9')
		ft_double_plusrem(rem, precision);
	rem[precision + 1] = '\0';
}

/*
** Revert integer of double to decemical using string
*/

/*static */void	ft_double_i(char *mantissa, char **integer, int exponent)
{
	char	*power;
	char	*tmp;
	int		len;
	int		size;

	if (exponent < 0)
		ft_double_ispace(integer);
	else
	{
		len = ft_double_exp(exponent, 2, &power);
		size = ft_strlen(power + len);
		if (!(*integer = ft_strnew(size + 1)))
			ft_error();
		ft_double_addition(*integer, &power, size, len);
		len = ft_double_exp(0, 2, &power);
		while (exponent > 0)
		{
			tmp = mantissa[exponent--] == '0' ? ft_strjoin("", "0") :
				ft_strjoin("", power + len);
			len = ft_strlen(tmp) - 1;
			ft_double_addition(*integer, &tmp, size, len);
			len = ft_double_multi(power, 2);
		}
	}
}

/*
** Revert remainder of double to decemical using string
*/

/*static */void	ft_double_r(char *mantissa, char **rem, int precision, int exp)
{
	char	*power;
	char	*tmp;
	int		size;
	int		len;
	int		i;

	i = 0;
	if (!(*rem = ft_strnew(1024)))
		ft_error();
	size = 1;
	while (size < exp)
		(*rem)[size++] = '0';
	len = ft_double_exp(exp, 5, &power);
	while (mantissa[i])
	{
		tmp = mantissa[i++] == '0' ? ft_strjoin("", "0") :
			ft_strjoin("", power + len);
		len = ft_strlen(tmp) - 1;
		ft_double_addition(*rem, &tmp, size++, len);
		len = ft_double_multi(power, 5);
	}
	while (size <= precision + 1)
		*rem[size++] = '0';
	ft_double_rounding(*rem, precision);
}

/*
** Revert double to decemical using string
*/

void		ft_double_revert(char *mantissa, char **num, int exp,
							int precision)
{
	char	*integer;
	char	*remnder;
	int		size;
	int		i;

	ft_double_i(mantissa, &integer, exp);
	i = exp >= 0 ? exp : 0;
	mantissa = mantissa + i;
	size = integer[0] == '\0' ? ft_strlen(integer + 1) : ft_strlen(integer);
	size = exp >= 0 ? precision : precision + 1;
	size += precision ? 1 : 0;
	if (!(*num = ft_strnew(size)))
		ft_error();
	*num = !integer[0] ? ft_strcat(*num, integer + 1) :
		ft_strcat(*num, integer);
	ft_strdel(&integer);
	if (precision > 0)
	{
		exp = exp >= 0 ? -1 : exp;
		*num = ft_strcat(*num, ".");
		ft_double_r(mantissa, &remnder, precision, exp);
		if (remnder[0] != '\0')
			ft_double_plusrem(*num, ft_strlen(*num) - 2);
		*num = ft_strcat(*num, remnder + 1);
		ft_strdel(&remnder);
	}
}

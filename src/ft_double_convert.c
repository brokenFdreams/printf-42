/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/17 12:44:21 by fsinged          ###   ########.fr       */
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

static void	ft_double_i(char *mantissa, char **integer, int exponent)
{
	char	*power;
	char	*tmp;
	int		len;
	int		size;

	if (exponent < 0)
		ft_double_ispace(integer);
	else
	{
		len = ft_double_exp(exponent, 2, &tmp);
		size = ft_strlen(tmp + len);
		if (!(*integer = ft_strnew(size + 1)))
			ft_error();
		ft_double_addition(*integer, tmp, size, size + len - 1);
		ft_bzero(tmp + len, ft_strlen(tmp + len));
		len = ft_double_exp(exponent > 62 ? exponent - 62 : 0, 2, &power);
		while ((exponent = exponent > 62 ? 62 : exponent))
		{
			tmp = mantissa[exponent--] == '0' ? ft_strcpy(tmp, "0") :
				ft_strcpy(tmp, power + len);
			ft_double_addition(*integer, tmp, size, ft_strlen(tmp) - 1);
			len = ft_double_multi(power, 2);
		}
		ft_strrdel(&power, &tmp);
	}
}

/*
** Revert remainder of double to decemical using string
*/

static void	ft_double_r(char *mantissa, char **rem, int precision, int exp)
{
	char	*power;
	char	*tmp;
	int		size;
	int		len;
	int		i;

	if (!(*rem = ft_strnew(precision > 16382 ? precision + 2 : 16384)))
		ft_error();
	size = 1;
	while (!(i = 0) && size < exp)
		(*rem)[size++] = '0';
	len = ft_double_exp(exp, 5, &power);
	if (!(tmp = ft_strnew(precision > 16382 ? precision : 16384)))
		ft_error();
	while (mantissa[i])
	{
		tmp = mantissa[i++] == '0' ? ft_strcpy(tmp, "0") :
			ft_strcpy(tmp, power + len);
		ft_double_addition(*rem, tmp, size++, ft_strlen(tmp) - 1);
		len = ft_double_multi(power, 5);
	}
	ft_strrdel(&power, &tmp);
	while (size <= precision + 1)
		(*rem)[size++] = '0';
	ft_double_rounding(*rem, precision);
}

/*
** Revert double to decemical using string
*/

void		ft_double_revert(char *mantissa, char **num, int exp,
							t_flags *flags)
{
	char	*integer;
	char	*remnder;
	int		size;

	ft_double_i(mantissa, &integer, exp);
	mantissa += exp >= 0 && exp < 62 ? exp + 1 : 0;
	mantissa += exp > 62 ? 62 : 0;
	size = integer[0] ? ft_strlen(integer) : ft_strlen(integer + 1);
	ft_double_r(mantissa, &remnder, flags->precision, exp >= 0 ? 1 : exp * -1);
	if (remnder[0] != '\0')
		ft_double_plusrem(integer, integer[0] ? size - 1 : size);
	size += exp >= 0 ? flags->precision : flags->precision + 1;
	size += flags->precision > 0 || flags->hash ? 1 : 0;
	if (!(*num = ft_strnew(size)))
		ft_error();
	*num = !integer[0] ? ft_strcat(*num, integer + 1) :
		ft_strcat(*num, integer);
	*num = flags->hash || flags->precision > 0 ? ft_strcat(*num, ".") : *num;
	*num = flags->precision > 0 ? ft_strcat(*num, remnder + 1) : *num;
	ft_strrdel(&integer, &remnder);
}

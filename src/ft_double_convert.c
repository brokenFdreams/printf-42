/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/10 13:40:46 by fsinged          ###   ########.fr       */
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

static int	ft_double_i(char *mantissa, char **integer, int exponent)
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

static void	ft_double_r(char *mantissa, char **rem, int precision, int exp)
{
	uintmax_t	power;
	char		*tmp;
	int			size;
	int			len;
	int			i;

	i = 0;
	power = exp < 0 ? ft_exponentiation(exp * -1, 5) : 5;
	if (!(*rem = ft_strnew(652)))
		ft_error();
	size = 1;
	while (size < (exp * -1))
		(*rem)[size++] = '0';
	while (mantissa[i])
	{
		tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
		len = ft_strlen(tmp) - 1;
		ft_double_addition(*rem, &tmp, size, len);
		size++;
		power *= 5;
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

	i = exp >= 0 ? ft_double_i(mantissa, &integer, exp) :
		ft_double_ispace(&integer);
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
		*num = ft_strcat(*num, ".");
		ft_double_r(mantissa, &remnder, precision, exp);
		if (remnder[0] != '\0')
			ft_double_plusrem(*num, ft_strlen(*num) - 2);
		*num = ft_strcat(*num, remnder + 1);
		ft_strdel(&remnder);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_convert.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:42:49 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/05 17:11:55 by fsinged          ###   ########.fr       */
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
	i = precision + 1;
	if ((*rem)[i] == '5')
	{
		i++;
		while ((*rem)[i] && (*rem)[i] == '0')
			i++;
		if (((*rem)[i] && (*rem)[i] != '0') ||
			((*rem)[precision] - '0') % 2 != 0)
			ft_double_plusrem(*rem, precision);
	}
	else if ((*rem)[i] > '5' && (*rem)[i] <= '9')
			ft_double_plusrem(*rem, precision);
	(*rem)[precision + 1] = '\0';
}

/*
** Revert double to decemical using string
*/

void		ft_double_revert(char *mantissa, char **num, int exponent,
							 int precision)
{
	char	*tmp;
	int		i;
	int		size;

	i = exponent >= 0 ? ft_double_i(mantissa, &tmp, exponent) : 0;
	mantissa = exponent >= 0 ? mantissa + i : mantissa;
	tmp = exponent >= 0 && tmp[i] == '\0' ? tmp + 1 : NULL;
	size = exponent >= 0 ? ft_strlen(tmp) + precision : precision + 1;
	size = precision ? size + 1 : size;
	if (!(*num = ft_strnew(size)))
		ft_error();
	*num = tmp ? ft_strcat(*num, tmp) : ft_strcat(*num, "0");
	if (tmp)
		ft_strdel(&tmp);
	if (precision > 0)
	{
		*num = ft_strcat(*num, ".");
		ft_double_r(mantissa, &tmp, precision, exponent);
		if (tmp[0] != '\0')
			ft_double_plusrem(*num, ft_strlen(*num) - 2);
		tmp++;
		*num = ft_strcat(*num, tmp);
		ft_strdel(&tmp);
	}
}

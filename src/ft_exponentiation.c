/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponentiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:01:11 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/10 13:44:09 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Plus remainder
*/

void		ft_double_plusrem(char *num, int size)
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
** Addition numbers in strings
*/

void		ft_double_addition(char *num, char **tmp, int size, int len)
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
** Multiplication number in string
*/

static int	ft_double_multi(char *exp, int base)
{
	
	char	**tmp;
	int		i;
	int		j;
	int		k;

	i = 1023;
	j = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * 1024)))
		ft_error();
	while (exp[i])
	{
		if (!(tmp[j] = ft_strnew(2)))
			ft_error(0);
		tmp[j][1] = ((exp[i] - '0') * base) % 10 + '0';
		tmp[j][0] = ((exp[i] - '0') * base) / 10 + '0';
		tmp[j][0] = tmp[j][0] == '0' ? '\0' : tmp[j][0];
		j++;
		i--;
	}
	k = 0;
	i = 1023;
	ft_bzero(exp, 1024);
	while (k < j)
		ft_double_addition(exp, &tmp[k++], i--, 1);
	ft_strdel(tmp);
	while (i >= 0 && exp[i])
		i--;
	return (i + 1);
}

char		*ft_double_power(int exponent, int base)
{
	char	*exp;
	char	*ret;
	int		i;

	if (!(exp = ft_strnew(1024)))
		ft_error();
	exp[1023] = '1';
	while(exponent > 0)
	{
		i = ft_double_multi(exp, base);
		exponent--;
	}
	if (!(ret = ft_strnew(i)))
		ft_error();
	ret = ft_strcpy(ret, exp + i);
	ft_strdel(&exp);
	return (ret);
}

uintmax_t	ft_exponentiation(int exponent, int base)
{
	uintmax_t power;

	power = 1;
	while (exponent > 0)
	{
		power *= base;
		exponent--;
	}
	return (power);
}

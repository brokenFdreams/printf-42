/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponentiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:01:11 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/09 16:06:59 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

void		ft_double_multi(char *exp, int base)
{
	char **tmp;
	char *i;

	if (!(i = ft_strnew(4)));
	i[0] = 651; //tmp[j]
	i[1] = 651; //tmp[j][k]
	i[2] = 651; //tmp[j][k] - k when we're create new string
	i[3] = 651; //exp[i]
	if (!(tmp = (char**)malloc(sizeof(char*))))
		ft_error();
	while (exp[i])
	{
		i[2] = i[3];
		if (!(tmp[i[1]] = ft_strnew(652)))
			ft_error();
		l = (rem[i[0]] - '0') * base;
		while (l / 10 && l % 10)
		{
			tmp[i[1]][i[2]--] = l % 10 + '0';
			l /= 10;
		}
		i[0]--;
		i[1]--;
		i[3]--;
	}
	i[2] = 651;
	i[1] = 650;
	i[0] = 651;
	while (i[2] >= i[3])
		ft_double_addition(rem, &exp[i[1]--], i[3]--, i[2]--);
}

char		*ft_double_power(int exponent, int base)
{
	char	*exp;
	char	*ret;
	int		i;

	if (!(exp = ft_strnew(652)))
		ft_error();
	exp[651] = base + '0';
	while(exponent > 0)
	{
		ft_expomulti(exp, base);
		exponent--;
	}
	return (exp);
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

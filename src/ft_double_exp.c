/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_exp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 15:01:18 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/16 11:28:21 by fsinged          ###   ########.fr       */
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
	else if (num[size] == '\0')
		num[size] = '1';
	else
		num[size] += 1;
}

/*
** Addition numbers in strings
*/

void		ft_double_addition(char *num, char *tmp, int size, int len)
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
		b += tmp[len--] - '0';
		a = a + b;
		b = a >= 10 ? 1 : 0;
		num[size--] = a >= 10 ? a % 10 + '0' : a + '0';
	}
	if (b)
		ft_double_plusrem(num, size);
}

static void	ft_double_multispace(char *exp, char **tmp, int i, int j)
{
	int k;

	k = 0;
	while (k < j)
	{
		ft_double_addition(exp, tmp[k], i--, 1);
		ft_strdel(&(tmp[k++]));
	}
}

/*
** Multiplication number in string
*/

int			ft_double_multi(char *exp, int base)
{
	char	**tmp;
	int		i;
	int		j;

	i = 11452;
	if (!(tmp = (char**)malloc(sizeof(char*) * 11452)))
		ft_error();
	while (exp[i] && ((j = i == 11452 ? 0 : j) == 0 || 1))
	{
		if (!(tmp[j] = ft_strnew(2)))
			ft_error(0);
		tmp[j][1] = ((exp[i] - '0') * base) % 10 + '0';
		tmp[j][0] = ((exp[i--] - '0') * base) / 10 + '0';
		tmp[j][0] = tmp[j][0] == '0' ? '\0' : tmp[j][0];
		j++;
	}
	ft_bzero(exp, (i = 11452) + 1);
	ft_double_multispace(exp, tmp, i, j);
	ft_strddel(&tmp);
	while (i >= 0 && exp[i])
		i--;
	return (i + 1);
}

int			ft_double_exp(int exponent, int base, char **exp)
{
	int		i;

	if (!(*exp = ft_strnew(11452)))
		ft_error();
	(*exp)[11452] = '1';
	i = -1;
	while (exponent > 0)
	{
		i = ft_double_multi(*exp, base);
		exponent--;
	}
	*exp = i == -1 ? ft_strcpy(*exp, "1") : *exp;
	return (i == -1 ? 0 : i);
}

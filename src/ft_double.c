/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 13:45:25 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/01 13:39:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags, join our double to it and return result
*/

static int	ft_double_flags(char **nbr, int sign, t_flags *flags, char **save)
{
	int		size;
	int		length;
	int		i;

	length = ft_strlen(*nbr);
	size = (sign == -1 || flags->plus || flags->space) ? length + 1 : length;
	i = 0;
	if (size < flags->width)
		i = ft_int_width(save, size, flags, sign);
	else if (!(*save = ft_strnew(size)))
		ft_error();
	if (sign == -1)
		(*save)[i] = '-';
	else if (flags->plus)
		(*save)[i] = '+';
	else if (flags->space)
		(*save)[0] = ' ';
	*save = ft_strnjoin(*save, *nbr, length, i);
	ft_strdel(nbr);
	return (size < flags->width ? flags->width : size);
}

/*
** Get double in binary system
** Return its value in string
*/

static char	*ft_double_tobinary(long double nbr)
{
	char	*binary;
	char	*tmp;
	int		i;
	int		size;
	int		expression;

	i = 0;
	size = 65;
	if (!(binary = ft_strnew(size)))
		ft_error();
	tmp = ft_uint_itoa((uintmax_t)nbr)
	binary = ft_strcpy(binary, tmp);
	ft_strdel(&tmp);
	
	return (binary);
}

/*
** 
** return double as string
*/

static char *ft_double_itoa(long double nbr)
{
	char	*num;
	int		i;
	int		size;
	
}

/*
** Read double, convert it to the desired type (check length)
** and return its value in the string using flags
** flags - [+-# 0][width][precision][length(l, L)]
*/

int			ft_double(va_list ap, t_flags *flags, char **save)
{
	long double nbr;
	int			sign;

	if (flags->length == LENGTH_L)
		nbr = va_arg(ap, double);
	else if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	sign = nbr >= 0 ? 1 : -1;
	return (ft_double_flags(ft_double_itoa(nbr * sign), sign, flags, save));
}

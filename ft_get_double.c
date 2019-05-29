/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getdouble.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 16:11:44 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/29 16:59:29 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_d(intmax_t nbr)
{
	int		i;
	int		size;
	int		flag;
	char	*save;

	size = ft_length_nbr(nbr);
	flag = nbr < 0 ? -1 : 1;
	if (!flag || flags->plus)
		size++;
	if (!(save = (char*)malloc(sizeof(char) * size)))
		ft_error();
	i = size - 2;
	while (nbr / 10 || nbr % 10)
	{
		save[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (!flag)
		save[i] = '-';
	else if (flags->plus)
		save[i] = '+';
	save[size - 1] = '\0';
	flag->plus = 0;
	return (save);
}

char	*ft_fill_d_flags(char *num, char *ost, t_flags *flags)
{
	char	*save;
	int		i;
	int		size;

	size = ft_strlen(num + flags->precision + 2);
	if (!(save = ft_strnew(flags->width + 1)))
		ft_error();
	while (size <= flags->width)
	{
		if (flags->minus)
		{
			if (flags->zero)
				save[i] = '0';
			else
				save[i] = ' ';
		}
		else
			save[size + i - 1] = ' ';
		i++;
	}
	save = ft_strjoin(save, num);
	save = ft_strjoin(save, ".");
	save = ft_strjoin(save, ost);
	ft_strdel(&num);
	ft_strdel(&ost);
	return (save);
}

char	*ft_itoa_double(long doubel nbr, t_flags *flags)
{
	intmax_t	num;
	uintmax_t	ost;
	int			precision;

	num = (intmax_t)nbr;
	nbr -= num;
	if (flags->precision == 0)
		flags->precision = 6;
	precision = flags->precision;
	if (d < 0)
		d *= -1;
	ost = 0;
	while (precision > 0)
	{
		d = d * 10;
		ost = ost * 10 + (unsigned int)d;
		d -= (int)d;
		precision--;
	}
	return (ft_fill_d_flags(ft_itoa_d(num), ft_itoa_d(ost), flags));
}

char	*ft_get_double(va_list ap, t_flags *flags)
{
	long double nbr;

	if (flags->length == LENGTH_L)
		nbr = va_arg(ap, double);
	else if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = (float)va_arg(ap, double);
	return (ft_itoa_double(nbr, flags));
}

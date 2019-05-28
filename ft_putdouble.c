/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:21:27 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/28 13:13:26 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdouble(long double d, t_flags *flags)
{
	intmax_t	num;
	uintmax_t	ost;
	int			bytes;

	num = (int)d;
	bytes = ft_putnbr(num);
	bytes += ft_putchar('.');
	d -= num;
	if (flags->precision == 0)
		flags->precision = 6;
	if (d < 0)
		d *= -1;
	ost = 0;
	while (flags->precision > 0)
	{
		d = d * 10;
		ost = ost * 10 + (int)d;
		d -= (int)d;
		flags->precision--;
	}
	bytes += ft_putnbr_u(ost);
	return (bytes);
}

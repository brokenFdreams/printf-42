/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 16:20:18 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/28 13:34:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(intmax_t nbr)
{
	int bytes;

	bytes = 0;
//	if (nbr == -2147483648)
//		write(1, "-2147483648", 11);
	if (nbr < 0)
	{
		bytes += ft_putchar('-');
		bytes += ft_putnbr(nbr * (-1));
	}
	else if (nbr >= 10)
	{
		bytes += ft_putnbr(nbr / 10);
		bytes += ft_putnbr(nbr % 10);
	}
	else
		return (ft_putchar(nbr + '0'));
	return (bytes);
}

int	ft_putnbr_u(uintmax_t nbr)
{
	int bytes;

	bytes = 0;
	if (nbr >= 10)
	{
		bytes += ft_putnbr_u(nbr / 10);
		bytes += ft_putnbr_u(nbr % 10);
	}
	else
		return (ft_putchar(nbr + '0'));
	return (bytes);
}

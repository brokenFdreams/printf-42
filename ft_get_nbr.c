/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:35:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/28 13:41:48 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	ft_get_nbr(va_list ap, t_flags *flags)
{
	intmax_t nbr;

	if (flags->length == LENGTH_HH)
		nbr = (char)va_arg(ap, int);
	else if (flags->length == LENGTH_H)
		nbr = (short int)va_arg(ap, int);
	else if (flags->length == LENGTH_LL)
		nbr = (long long int)va_arg(ap, long long int);
	else if (flags->length == LENGTH_L)
		nbr = (long int)va_arg(ap, long int);
	else if (flags->length == LENGTH_J)
		nbr = (intmax_t)va_arg(ap, intmax_t);
	else if (flags->length == LENGTH_Z)
		nbr = (size_t)va_arg(ap, size_t);
	else
		nbr = (int)va_arg(ap, int);
	return (nbr);
}

uintmax_t	ft_get_nbr_u(va_list ap, t_flags *flags)
{
	uintmax_t nbr;

	if (flags->length == LENGTH_HH)
		nbr = (unsigned char)va_arg(ap, unsigned int);
	else if (flags->length == LENGTH_H)
		nbr = (unsigned short int)va_arg(ap, unsigned int);
	else if (flags->length == LENGTH_LL)
		nbr = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (flags->length == LENGTH_L)
		nbr = (unsigned long int)va_arg(ap, unsigned long int);
	else if (flags->length == LENGTH_J)
		nbr = va_arg(ap, uintmax_t);
	else if (flags->length == LENGTH_Z)
		nbr = (size_t)va_arg(ap, size_t);
	else
		nbr = (unsigned int)va_arg(ap, unsigned int);
	return (nbr);
}

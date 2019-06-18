/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 15:32:43 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 15:56:01 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Allocate new string, fill flags and return result
** size = full size of string (nbr + sign)
*/

char	*ft_int_flags(char *nbr, t_flags *flags, int sign)
{
	char	*save;
	int		size;
	int		i;

	size = ft_strlen(nbr);
	size += sign == -1 ? -1 : 0;
	if ((flags->space && flags->width == 0 && flags == 1 && !flags->plus &&
		 (flags->width = size)) || size <= flags->width)
}

/*
** Read int, convert it to the desired type (check length flag)
** and return its value in the string (ft_itoa_uint) using flags
** ft_itoa_uint in file ft_uint.c
*/

char	*ft_get_nbr(va_list ap, t_flags *flags)
{
	intmax_t	nbr;
	int			sign;

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
	sign = nbr < 0 ? -1 : 1;
	return (ft_int_flags(ft_itoa_uint(nbr * sign), flags, sign));
}

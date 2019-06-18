/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:42:27 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 15:46:02 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** length of uint for allocate memory for this number
** this function calls in ft_itoa_uint and ft_double
*/

int		ft_length_uint(unitmax_t nbr)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr / 10 || nbr % 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

/*
** itoa for uintmax_t type
** return only a number converting to string
** also this function calls in ft_int and ft_double
*/

char	*ft_itoa_uint(uintmax_t nbr)
{
	int		size;
	char	*save;

	size = ft_length_uint(nbr);
	if (!(save = ft_strnew(size)))
		ft_error();
	size--;
	while (size >= 0)
	{
		save[size--] = nbr % 10 + '0';
		nbr /= 10;
	}
	return (save);
}

/*
** Read uint, conver it to the desired type (check length flag)
** and return its value in the string using flags (result of ft_int_flags)
*/

char	*ft_uint(va_list ap, t_flags *flags, char c)
{
	uintmax_t nbr;

	if (c == 'U')
		flags->length = LENGTH_L;
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
		nbr = va_arg(ap, size_t);
	else
		nbr = va_arg(ap, unsigned int);
	return (ft_int_flags(ft_itoa_uint(nbr), flags, 1));
}
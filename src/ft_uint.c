/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 14:42:27 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 15:22:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** length of uint for allocate memory for this number
*/

static int	ft_uint_length(uintmax_t nbr, int base)
{
	int count;

	count = 0;
	if (nbr == 0)
		return (1);
	while (nbr / base || nbr % base)
	{
		count++;
		nbr /= base;
	}
	return (count);
}

/*
** itoa for uintmax_t type
** return only a number converting to string
** also this function calls in ft_int, ft_hex and ft_double
*/

char		*ft_uint_itoa(uintmax_t nbr, int base)
{
	int		size;
	char	*num;
	int		rem;

	size = ft_uint_length(nbr, base);
	if (!(num = ft_strnew(size)))
		ft_error();
	size--;
	while (size >= 0)
	{
		rem = nbr % base;
		num[size--] = rem >= 10 ? rem + 'A' - 10 : rem + '0';
		nbr /= base;
	}
	return (num);
}

/*
** Read uint, conver it to the desired type (check length flag)
** return it value
*/

uintmax_t	ft_get_uint(va_list ap, t_flags *flags)
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
		nbr = va_arg(ap, size_t);
	else
		nbr = va_arg(ap, unsigned int);
	return (nbr);
}

/*
** return uint value in the string using flags
*/

int			ft_uint(va_list ap, t_flags *flags, char c, char **save)
{
	char *num;

	flags->plus = 0;
	flags->space = 0;
	if (c == 'U')
		flags->length = flags->length == 0 ? LENGTH_L : flags->length + 1;
	num = ft_uint_itoa(ft_get_uint(ap, flags), 10);
	return (ft_int_flags(&num, flags, 1, save));
}

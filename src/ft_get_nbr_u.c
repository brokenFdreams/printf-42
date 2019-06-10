/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:06:17 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/10 14:06:12 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_length_u(uintmax_t nbr)
{
	int	count;

	count = 1;
	while (nbr / 10 || nbr % 10)
	{
		count++;
		nbr /= 10;
	}
	return (count);
}

static char	*ft_itoa_nbr(uintmax_t nbr, t_flags *flags)
{
	int		size;
	int		i;
	char	*save;

	size = ft_length_u(nbr);
	if (size <= flags->width)
		size = ft_fill_nbr_f(&save, size, flags);
	else if (!(save = ft_strnew(size)))
		ft_error();
	i = size - 2;
	while (nbr / 10 || nbr % 10)
	{
		save[i--] = nbr % 10 + '0';
		nbr /= 10;
	}
	save[size - 1] = '\0';
	return (save);
}

char		*ft_get_nbr_u(va_list ap, t_flags *flags)
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
	return (ft_itoa_nbr(nbr, flags));
}

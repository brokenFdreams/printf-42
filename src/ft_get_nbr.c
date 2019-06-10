/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_nbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:35:15 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/10 14:06:02 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_length_d(intmax_t nbr)
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

int			ft_fill_nbr_f(char **save, int size, t_flags *flags)
{
	int	i;

	i = 0;
	if (!(*save = ft_strnew(flags->width + 1)))
		ft_error();
	while (size + i <= flags->width)
	{
		if (!flags->minus)
		{
			if (flags->zero)
				(*save)[i] = '0';
			else
				(*save)[i] = ' ';
		}
		else
			(*save)[size + i - 1] = ' ';
		i++;
	}
	if (flags->minus)
		return (size);
	else
		return (size + i);
}

static char	*ft_itoa_d(intmax_t nbr, t_flags *flags)
{
	int		size;
	int		i;
	int		flag;
	char	*save;

	size = ft_length_d(nbr);
	flag = nbr < 0 ? -1 : 1;
	if (flag == -1 || flags->plus)
		size++;
	if (size <= flags->width)
		size = ft_fill_nbr_f(&save, size, flags);
	else if (!(save = ft_strnew(size)))
		ft_error();
	i = size - 2;
	while (nbr / 10 || nbr % 10)
	{
		save[i--] = nbr % 10 * flag + '0';
		nbr /= 10;
	}
	if (flag == -1)
		save[i] = '-';
	else if (flags->plus)
		save[i] = '+';
	save[size - 1] = '\0';
	return (save);
}

char		*ft_get_nbr(va_list ap, t_flags *flags)
{
	intmax_t	nbr;

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
	return (ft_itoa_d(nbr, flags));
}

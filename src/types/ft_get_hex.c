/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:19:37 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:39:00 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static int	ft_length_x(uintmax_t nbr, t_flags *flags)
{
	int size;

	size = 1;
	if (flags->hash)
		size += 2;
	while ((nbr / 16) > 0)
	{
		size++;
		nbr /= 16;
	}
	return (size);
}

static int	ft_fill_hex_f(char **save, int size, t_flags *flags, int flag)
{
	int i;

	i = 0;
	if (!(*save = ft_strnew(flags->width + 1)))
		ft_error();
	if (flags->hash && (flags->zero || flags->minus))
	{
		(*save)[0] = '0';
		if (flag)
			(*save)[1] = 'X';
		else
			(*save)[1] = 'x';
		if (!(flags->minus))
		{
			i = 2;
			size -= 2;
		}
	}
	while (size + i <= flags->width)
	{
		if (flags->minus)
			(*save)[size + i - 1] = ' ';
		else if (flags->zero)
			(*save)[i] = '0';
		else
			(*save)[i] = ' ';
		i++;
	}
	if (flags->minus)
		return (size);
	else
		return (size + i);
}

static char	*ft_itoa_x(uintmax_t nbr, t_flags *flags, int flag)
{
	int		i;
	int 	size;
	char	*save;
	int		num;

	size = ft_length_x(nbr, flags);
	if (size <= flags->width)
		size = ft_fill_hex_f(&save, size, flags, flag);
	else if (!(save = ft_strnew(size)))
		ft_error();
	i = size - 2;
	while (nbr / 16 || nbr % 16)
	{
		num = nbr % 16;
		nbr = nbr / 16;
		if (num < 10)
			save[i--] = num + '0';
		else if (flag == 0)
			save[i--] = num - 10 + 'a';
		else
			save[i--] = num - 10 + 'A';
	}
	save[size -1] = '\0';
	return (save);
}

char	*ft_get_hex(va_list ap, t_flags *flags, int flag)
{
	uintmax_t	nbr;

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
	return (ft_itoa_x(nbr, flags, flag));
}

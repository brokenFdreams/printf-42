/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:19:37 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 12:52:48 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_length_x(uintmax_t nbr, t_flags flags)
{
	int size;

	size = 1;
	if (flags->hash)
		size += 2;
	while ((num / 16) > 0)
	{
		size++;
		cnum /= 16;
	}
	return (size);
}

int		ft_fill_hex_f(char **save, int size, t_flags *flags)
{
	int i;

	i = 0;
	if (!(*save = ft_strnew(flags->width + 1)))
		ft_error();
	while (size + i <= 

}

char	*ft_itoa_x(uintmax_t nbr, int flag, t_flags *flags)
{
	int		i;
	int 	size;
	char	*save;

	size = ft_length_x(nbr, flags);
	if (size <= flags->width)
		
}

char	*ft_get_hex(va_list ap, int flag, t_flags *flags)
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
	return (ft_itoa_x(nbr, flag, flags)
/*
	str = (char*)malloc(sizeof(char) * (count + 1));
	str[count--] = '\0';
	while (count >= 0)
	{
		cnum = num % 16;
		num = num / 16;
		if (cnum < 10)
			str[count--] = cnum + '0';
		else if (flag == 0)
			str[count--] = cnum - 10 + 'a';
		else
			str[count--] = cnum - 10 + 'A';
	}
	cnum = ft_putstr(str, flags);
	ft_strdel(&str);
	return (cnum);
*/
}

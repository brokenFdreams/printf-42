/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:55:20 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/18 13:12:02 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_fill_flags(char **save, int size, t_flags *flags)
{
	int i;

	i = 0;
	while (i < size - 1)
	{
		if (!flags->minus)
		{
			if (flags->zero && !flags->space)
				(*save)[i] = '0';
			else
				(*save)[i] = ' ';
		}
		else if (flags->zero && !flags->space)
			(*save)[size - i - 1] = '0';
		else
			(*save)[size - i - 1] = ' ';
		i++;
	}
	if (!flags->minus)
		return (size);
	return (1);
}

char	*ft_get_char(va_list ap, t_flags *flags, int flag)
{
	char	*save;
	int		size;

	if (flags->width == 0)
		size = 1;
	else
		size = flags->width;
	if (!(save = ft_strnew(flags->width)))
		ft_error();
	size = ft_fill_flags(&save, size, flags);
	if (!flag)
		save[size - 1] = (char)va_arg(ap, int);
	return (save);
}

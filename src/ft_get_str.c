/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:42:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/11 16:05:30 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_fill_f(char *str, t_flags *flags)
{
	int		size;
	char	*save;
	int		i;

	size = ft_strlen(str);
	if (flags->precision && flags->precision < size)
		size = flags->precision;
	flags->precision = size;
	i = 0;
	if (flags->width && flags->width > size)
		save = ft_strnew(flags->width);
	else
		save = ft_strnew(size);
	if (flags->width && flags->width > size)
	{
		if (flags->minus)
			while (size < flags->width - 1)
				save[size++] = ' ';
		else
			while (size + i < flags->width - 1)
				save[i++] = ' ';
		save = ft_strncat(save, str, flags->precision);
	}
	else
		save = ft_strncpy(save, str, flags->precision);
	return (save);
}

char	*ft_get_str(va_list ap, t_flags *flags, int flag)
{
	if (flag == 0)
		return (ft_fill_f(va_arg(ap, char*), flags));
	return ("?");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_octal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 13:06:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 17:28:43 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** return octal convert to string using flags
*/

int	ft_octal(va_list ap, t_flags *flags, char **save)
{
	char	*num;
	int		size;

	num = ft_uint_itoa(ft_get_uint(ap, flags), 8);
	size = ft_strlen(num);
	if (flags->hash && num[0] != '0')
		flags->precision = flags->precision < size ? size + 1 :
			flags->precision + 1;
	else if (flags->hash && num[0] == '0')
		flags->precision = flags->precision == -1 ? 1 : flags->precision + 1;
	flags->hash = 0;
	flags->space = 0;
	flags->plus = 0;
	return (ft_int_flags(&num, flags, 1, save));
}

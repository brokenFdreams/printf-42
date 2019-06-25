/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:38:31 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 14:51:41 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**__________________FIX____It________________
*/

/*
** Allocate new string, put there char with flags
** return string with char and editing by flags
*/

int	ft_char(va_list ap, t_flags *flags, int flag, char **save)
{
	char	*num;
	int		c;

	c = va_arg(ap, int);
	num = ft_strnew(2);
	if (c == 0)
	{
		flags->space = 0;
		flags->precision = -1;
		num[1] = 127;
	}
	num[0] = c;
	return (ft_int_flags(&num, flags, 1, save));
}

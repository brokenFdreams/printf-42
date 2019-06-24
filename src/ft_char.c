/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:38:31 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 17:26:19 by fsinged          ###   ########.fr       */
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

char	*ft_char(va_list ap, t_flags *flags, int flag)
{
	char	*save;
	char	c;

	c = (char)va_arg(ap, int);
	save = ft_strnew(1);
	save[0] = c;
	return (ft_int_flags(save, flags, 1));
}

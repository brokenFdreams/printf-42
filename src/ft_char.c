/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:38:31 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 15:01:13 by fsinged          ###   ########.fr       */
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

	save = ft_strnew(1);
	save[0] = (char)va_arg(ap, int);
	return (ft_int_flags(save, flags, 1));
}

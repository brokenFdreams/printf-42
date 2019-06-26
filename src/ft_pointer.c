/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:56:32 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/26 12:47:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** print memory and return size of save
*/

int	ft_pointer(va_list ap, t_flags *flags, char **save)
{
	char *num;

	flags->length = LENGTH_L;
	flags->hash = 1;
	num = ft_uint_itoa(ft_get_uint(ap, flags), 16);
	return (ft_hex_flags(&num, flags, 32, save));
}

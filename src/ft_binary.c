/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:48:23 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 13:20:52 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_binary(va_list ap, t_flags *flags, char **save)
{
	char *num;

	num = ft_uint_itoa(ft_get_uint(ap, flags), 2);
	return (ft_int_flags(&num, flags, 1, save));
}

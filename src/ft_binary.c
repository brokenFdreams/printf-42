/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:48:23 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 16:53:56 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_binary(va_list ap, t_flags *flags)
{
	return (ft_int_flags(ft_uint_itoa(ft_get_uint(ap, flags), 2), flags, 1));
}

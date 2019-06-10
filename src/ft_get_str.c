/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:42:38 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/10 14:06:31 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_get_str(va_list ap, t_flags *flags, int flag)
{
	if (flag == 0)
		return (va_arg(ap, char*));
	return ("?");
}

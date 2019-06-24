/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:42:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 17:08:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** COSTIL'
*/

char	*ft_str(va_list ap, t_flags *flags, int flag)
{
	char	*save;
	char	*tmp;
	size_t	size;

	tmp = va_arg(ap, char*);
	size = tmp == NULL ? 6 : ft_strlen(tmp);
	size = flags->precision != -1 ? flags->precision : size;
	save = ft_strnew(size);
	save = tmp ? ft_strncpy(save, tmp, size) : ft_strncpy(save, "(null)", size);
	flags->precision = -1;
	return (ft_int_flags(save, flags, 1));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:42:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/08 16:03:08 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** COSTIL'
*/

int	ft_str(va_list ap, t_flags *flags, int flag, char **save)
{
	char	*str;
	char	*tmp;
	size_t	size;

	tmp = va_arg(ap, char*);
	size = tmp == NULL ? 6 : ft_strlen(tmp);
	size = flags->precision < size && flags->precision != -1 ? flags->precision
		: size;
	str = ft_strnew(size);
	str = tmp ? ft_strncpy(str, tmp, size) : ft_strncpy(str, "(null)", size);
	flags->plus = 0;
	flags->space = 0;
	flags->precision = -1;
	return (ft_int_flags(&str, flags, 1, save));
}

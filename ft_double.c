/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:00:52 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/01 13:08:49 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*ft_double_binary(long double nbr, t_flags *flags)
{
	

}
/*
** Read double, conver it to the desired type (check length)
** and return its value in the string formated by flags
*/

int		ft_double(va_list ap, t_flags *flags, char **save)
{
	long double nbr;

	if (flags->length == LENGTH_LLL)
		nbr = va_arg(ap, long double);
	else
		nbr = va_arg(ap, double);
	return (ft_double_flags(nbr, flags, save);
}

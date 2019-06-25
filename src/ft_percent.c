/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:44:19 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/25 13:05:29 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** COSTIL'
*/

int	ft_percent(t_flags *flags, char **save)
{
	char *num;

	num = ft_strnew(1);
	num[0] = '%';
	flags->space = 0;
	return (ft_int_flags(&num, flags, 1, save));
}

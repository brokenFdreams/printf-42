/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:04:54 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 14:51:08 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** 5 functions, so few
** code for ft_flags.c
*/

void	ft_length(char **str, t_flags *flags, int length, int size)
{
	*str += size;
	if (length > flags->length)
		flags->length = length;
}

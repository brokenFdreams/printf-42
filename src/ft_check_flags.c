/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 14:04:39 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:26:41 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_check_nbr_f(t_flags *flags)
{
	if (flags->plus)
		flags->space = 0;
	if (flags->minus)
		flags->zero = 0;
}

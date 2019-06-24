/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:44:19 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/24 16:41:52 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** COSTIL'
*/

char	*ft_percent(t_flags *flags)
{
	char *save;

	save = ft_strnew(1);
	save[0] = '%';
	flags->space = 0;
	return (ft_int_flags(save, flags, 1));
}

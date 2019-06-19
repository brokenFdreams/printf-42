/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 16:42:10 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 16:57:21 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** COSTIL'
*/

char	*ft_str(va_list ap, t_flags *flags, int flag)
{
	char *save;
	char *tmp;

	tmp = va_arg(ap, char*);
	save = ft_strnew(ft_strlen(tmp));
	save = ft_strcpy(save, tmp);
	return (save);
}

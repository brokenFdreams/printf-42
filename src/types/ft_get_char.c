/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 15:55:20 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:25:12 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_get_char(va_list ap, t_flags *flags, int flag)
{
	char *save;

	if (!(save = (char*)malloc(sizeof(char) * 2)))
		  ft_error();
	if (flag)
		save[0] = (char)va_arg(ap, int);
	save[1] = '\0';
	return (save);
}

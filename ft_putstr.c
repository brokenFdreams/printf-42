/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:46:11 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/27 17:06:13 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, t_flags *flags)
{
	int i;

	i = 0;
	if (s == NULL)
		return (ft_putstr("(null)", flags));
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
	return (i);
}

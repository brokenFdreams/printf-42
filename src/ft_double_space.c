/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 14:28:21 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/08 14:32:13 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Rounding number remainder (used in ft_double_convert.c)
*/

void	ft_double_rounding(char *rem, int precision)
{
	int i;

	i = precision + 1;
	if (rem[i] == '5')
	{
		i++;
		while (rem[i] && rem[i] == '0')
			i++;
		if ((rem[i] && rem[i] != '0') ||
			(rem[precision] - '0') % 2 != 0)
			ft_double_plusrem(rem, precision);
	}
	else if (rem[i] > '5' && rem[i] <= '9')
		ft_double_plusrem(rem, precision);
	rem[precision + 1] = '\0';
}

/*
** Just some code from function ft_double_i, because there 25 lines
*/

int		ft_double_ispace(char **integer)
{
	if (!(*integer = ft_strnew(1)))
		ft_error();
	(*integer)[0] = '0';
	return (0);
}


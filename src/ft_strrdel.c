/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/11 16:30:37 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/11 16:32:11 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strrdel(char **power, char **tmp)
{
	if (power && *power)
	{
		free(*power);
		*power = NULL;
	}
	if (tmp && *tmp)
	{
		free(*tmp);
		*tmp = NULL;
	}
}

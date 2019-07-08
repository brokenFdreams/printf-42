/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exponentiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 13:01:11 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/08 13:42:25 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

uintmax_t	ft_exponentiation(int exponent, int base)
{
	uintmax_t power;

	power = 1;
	while (exponent > 0)
	{
		power *= base;
		exponent--;
	}
	return (power);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:35:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/10 13:33:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char        *ft_double_power(int exponent, int base);

int		main(void)
{
	printf("%s\n", ft_double_power(1023, 2));
	printf("\n%s\n", ft_double_power(1026, 5));
	return (0);
}

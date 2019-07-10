/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:35:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/10 16:35:23 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char        *ft_double_power(int exponent, int base);

int		main(void)
{
	char *str;
//	char *tmp;

	ft_double_exp(0, 2, &str);
	printf("%s\n", str);
//	ft_strdel(&str);
//	tmp = ft_double_power(1026, 5);
//	printf("\n%s\n", tmp);
//	ft_strdel(&tmp);
	return (0);
}

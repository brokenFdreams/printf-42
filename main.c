/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:53:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/10 15:42:46 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned char c = 0x64;
	double l = 3.14;
	int k = 100;

/*
	ft_printf("mine double %7.1lf\n", l);
	ft_printf("mine float %7.1f\n", (float)l);
	ft_printf("mine long double %7.1Lf\n", (long double)l);
	printf("origin double %7.1lf\n", l);
	printf("origin float %7.1f\n", (float)l);
	printf("origin long double %7.1Lf\n", (long double)l);
*/
	ft_printf("_______mine______\n");
	ft_printf("mine 3.1 %.0lf\n", 3.1);
    ft_printf("mine 3.2 %.0lf\n", 3.2);
	ft_printf("mine 3.3 %.0lf\n", 3.3);
	ft_printf("mine 3.4 %.0lf\n", 3.4);
	ft_printf("mine 3.5 %.0lf\n", 3.5);
	ft_printf("mine 3.6 %.0lf\n", 3.6);
	ft_printf("mine 3.7 %.0lf\n", 3.7);
	ft_printf("mine 3.8 %.0lf\n", 3.8);
	ft_printf("mine 3.9 %.0lf\n", 3.9);

	ft_printf("______origin______\n");
	printf("origin 3.1 %.0lf\n", 2.1);
    printf("origin 3.2 %.0lf\n", 2.2);
	printf("origin 3.3 %.0lf\n", 2.3);
	printf("origin 3.4 %.0lf\n", 2.4);
	printf("origin 3.5 %.0lf\n", 2.5);
    printf("origin 3.6 %.0lf\n", 2.6);
	printf("origin 3.7 %.0lf\n", 2.7);
	printf("origin 3.8 %.0lf\n", 2.8);
    printf("origin 3.9 %.0lf\n", 2.9);





/*
	ft_printf("mine %5hhu\n", 300);
	printf("origin %5hhu\n", 300);
	ft_printf("mine %d\n", 2147483648);
	printf("origin %d\n", 2147483648);
	ft_printf("mine 0x64 %-#7x [%#7X]\n", -100, -100);
	printf("original 0x64 %-#7x [%#7X]\n", -100, -100);
	ft_printf("mine 100 %x [%X]\n", k, k);
	printf("original 100 %x [%X]\n", k, k);
*/
//	ft_printf("mine %s", "loool\n");
//	printf("original %s", "loool\n");
//	ft_printf("mine %+-0# 4.7s\n", "ll");
//	printf("orginal %+-0# 4.7s\n", "ll");
	return (0);
}

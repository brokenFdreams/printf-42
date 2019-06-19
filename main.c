/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:53:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/19 13:13:10 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	unsigned char c = 0x64;
	double l = 3.14;
	int k = 100;

	ft_printf("%5d\n", -42);
	ft_printf("%-15u\n", 4294967295);
/*
	ft_printf("mine double %7.1lf\n", l);
	ft_printf("mine float %7.1f\n", (float)l);
	ft_printf("mine long double %7.1Lf\n", (long double)l);
	printf("origin double %7.1lf\n", l);
	printf("origin float %7.1f\n", (float)l);
	printf("origin long double %7.1Lf\n", (long double)l);
*/
/*
	ft_printf("mine 3.15 %.1f\n", 0.15);
	ft_printf("mine 3.25 %.1f\n", 0.25);
    ft_printf("mine 3.35 %.1f\n", 0.35);
    ft_printf("mine 3.45 %.1f\n", 0.45);
    ft_printf("mine 3.55 %.1f\n", 0.55);
    ft_printf("mine 3.65 %.1f\n", 0.65);
    ft_printf("mine 3.75 %.1f\n", 0.75);
    ft_printf("mine 3.85 %.1f\n", 0.85);
    ft_printf("mine 3.95 %.1f\n", 0.95);

	ft_printf("\n");
	printf("origin 3.15 %.1f\n", 0.15);
	printf("origin 3.25 %.1f\n", 0.25);
	printf("origin 3.35 %.1f\n", 0.35);
	printf("origin 3.45 %.1f\n", 0.45);
	printf("origin 3.55 %.1f\n", 0.55);
	printf("origin 3.65 %.1f\n", 0.65);
	printf("origin 3.75 %.1f\n", 0.75);
	printf("origin 3.85 %.1f\n", 0.85);
	printf("origin 3.95 %.1f\n", 0.95);
*/

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

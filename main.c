/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:53:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/30 16:34:53 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	unsigned char c = 0x64;
	double l = 3.14;
	int k = 100;
/*
	ft_printf("mine double %lf\n", l);
	ft_printf("mine float %f\n", (float)l);
	ft_printf("mine long double %Lf\n", (long double)l);
	printf("origin double %lf\n", l);
    printf("origin float %f\n", (float)l);
    printf("origin long double %Lf\n", (long double)l);
*/
	ft_printf("mine %hhu\n", 300);
	printf("origin %hhu\n", 300);
	ft_printf("mine %d\n", 2147483648);
	printf("origin %d\n", 2147483648);
//	ft_printf("mine 0x64 %x [%X]\n", c, c);
//	printf("original 0x64 %x [%X]\n", c, c);
//	ft_printf("mine 100 %x [%X]\n", k, k);
//	printf("original 100 %x [%X]\n", k, k);
//	ft_printf("%lf\n", 3.14);
//	printf("%lf\n", 3.14);

	return (0);
}

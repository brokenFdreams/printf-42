/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 14:53:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/06/26 12:59:13 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int i;
	unsigned long l;
	char *str;

	printf("printf:%d\n", printf("{%f}{%lf}", -1444565444646.6465424242242454654,
			    -1444565444646.6465424242242454654l));
	printf("ft_printf:%d\n", ft_printf("{%f}{%lf}",
	-1444565444646.6465424242242454654, -1444565444646.6465424242242454654l));
	printf("printf:%d\n", printf("{%f}{%lf}", 1444565444646.6465424242242, 
			   1444565444646.6465424242242l));
	printf("ft_printf:%d\n", ft_printf("{%f}{%lf}", 1444565444646.6465424242242,
								 1444565444646.6465424242242l));

/*
	printf("printf:%d\n", printf("{%#.3o}", 1));
	printf("ft_printf:%d\n", ft_printf("{%#.3o}", 1));
	printf("printf:%d\n", printf("{%p}", &i));
	printf("ft_printf:%d\n", ft_printf("{%p}", &i));
	printf("printf:%d\n", printf("{%p}", &l));
	printf("ft_printf:%d\n", ft_printf("{%p}", &l));
	printf("printf:%d\n", printf("{%p}", &str));
	printf("ft_printf:%d\n", ft_printf("{%p}", &str));
	printf("printf:%d\n", printf("{%.0p, %.p}", 0, 0));
	printf("ft_printf:%d\n", ft_printf("{%.0p, %.p}", 0, 0));
	printf("printf:%d\n", printf("{%05p}", 0));
	printf("ft_printf:%d\n", ft_printf("{%05p}", 0));
	printf("printf:%d\n", printf("{%5p}", 0));
	printf("ft_printf:%d\n", ft_printf("{%5p}", 0));
	printf("printf:%d\n", printf("{%p}", 0));
	printf("ft_printf:%d\n", ft_printf("{%p}", 0));
	printf("printf:%d\n", printf("{%.*s}", -5, "42"));
	printf("ft_printf:%d\n", ft_printf("{%.*s}", -5, "42"));
	printf("printf:%d\n", printf("{%#o}", 0));
	printf("ft_printf:%d\n", ft_printf("{%#o}", 0));
	printf("printf:%d\n", printf("{%.5c}", 42));
	printf("ft_printf:%d\n", ft_printf("{%.5c}", 42));
	printf(".4x:printf:%d\n", printf("{%.4x}", 42));
	printf(".4x:ft_printf:%d\n", ft_printf("{%.4x}", 42));
	printf("15.4x:printf:%d\n", printf("{%15.4x}", 42));
	printf("15.4x:ft_printf:%d\n", ft_printf("{%15.4x}", 42));
	printf("4.15x:printf:%d\n", printf("{%4.15x}", 42));
	printf("4.15x:ft_printf:%d\n", ft_printf("{%4.15x}", 42));
	printf("4.15x:printf:%d\n", printf("{%.4x}", 42424242));
	printf("4.15x:ft_printf:%d\n", ft_printf("{%.4x}", 42424242));
	printf(".4X:printf:%d\n", printf("{%.4X}", 42));
	printf(".4X:ft_printf:%d\n", ft_printf("{%.4X}", 42));
	printf(".4x:printf:%d\n", printf("{%.4x}", 42));
	printf(".4x:ft_printf:%d\n", ft_printf("{%.4x}", 42));
	printf("printf:%d\n", printf("{% 03d}", 0));
	printf("ft_printf:%d\n", ft_printf("{% 03d}", 0));

	int i = 2147483647;
	long l = 2147483647;
	long long ll = 9223372036854775807;
	intmax_t im = 9223372036854775807;

	ft_printf("j:%jd, z:%zd, u:%u, i:%i, l:%ld, ll:%lld\n", im, (size_t)i, i, i, l, ll);
	printf("j:%jd, z:%zd, u:%u, i:%i, l:%ld, ll:%lld\n", im, (size_t)i, i, i, l, ll);

	printf("ft_printf: %d\n", ft_printf("{%*3d}", 5, 0));
	printf("printf: %d\n", printf("{%*3d}", 5, 0));
	char i;

	i = 0;
	printf("%d:ft_printf: %d\n", i, ft_printf("null %c and text", i));
	printf("%d:printf: %d\n", i, printf("null %c and text", i));


	printf("ft_printf - %d\n", ft_printf("[% 10.5d]", 4242));
	printf("printf - %d\n", printf("[% 10.5d]", 4242));
	printf("ft_printf - %d\n", ft_printf("[%10.5d]", 4242));
    printf("printf - %d\n", printf("[%10.5d]", 4242));

	unsigned char c = 0x64;
	double l = 3.14;
	int k = 100;

    printf("% u\n", 4294967295);
    printf("%+u\n", 4294967295);
	ft_printf("% u\n", 4294967295);
    ft_printf("%+u\n", 4294967295);

	ft_printf("%-5d\n", -42);
	ft_printf("%-15jd\n", -4294967295);


	ft_printf("mine double %7.10lf\n", l);
	ft_printf("mine float %7.1f\n", (float)l);
	ft_printf("mine long double %7.1Lf\n", (long double)l);
	printf("origin double %7.10lf\n", l);
	printf("origin float %7.1f\n", (float)l);
	printf("origin long double %7.1Lf\n", (long double)l);


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
//	ft_printf("FUCK %d\n", 3);
	return (0);
}

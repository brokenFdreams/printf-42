/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/10 12:35:06 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/25 15:11:03 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <float.h>

int		main(void)
{
/*
	printf("%f\n", -5.9999999);
	printf("%f\n", 3.9999999);
	ft_printf("%f\n", -5.9999999);
	ft_printf("%f\n", 3.9999999);
	printf("pr%Lf\n", 999.999999l);
	ft_printf("ft%Lf\n", 999.999999l);
	printf("pr%.9Lf\n", -99.99999999l);
	ft_printf("ft%.9Lf\n", -99.99999999l);
	printf("pr%.10Lf\n", 0.87650894255l);
	ft_printf("ft%.10Lf\n", 0.87650894255l);
	printf("pr%.10Lf\n", -56.47852012685l);
	ft_printf("ft%.10Lf\n", -56.47852012685l);
*/

	long double inf = DBL_MAX/DBL_MIN;
	long double ninf = -DBL_MAX/DBL_MIN;
	long double nan = inf * 0;


	printf("%LF\n", inf);
	ft_printf("%LF\n", inf);
	printf("%LF\n", ninf);
	ft_printf("%LF\n", ninf);
	printf("%LF\n", nan);
	ft_printf("%LF\n", nan);
	printf("%F\n", -0.0);
	ft_printf("%F\n", -0.0);
	printf("%F\n", +0.0);
	ft_printf("%F\n", +0.0);
	printf("%F\n", 0.0);
	ft_printf("%F\n", 0.0);
//	printf("%.2000f\n", 623.28376510723481);
//	ft_printf("%.2000f\n", 623.28376510723481);

	return (0);
}

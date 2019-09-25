/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:59:30 by fsinged           #+#    #+#             */
/*   Updated: 2019/09/02 15:26:59 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>
#include <float.h>
#include <math.h>

int	main(void)
{
	double max = DBL_MAX;
	double min = DBL_MIN;

//	ft_printf("%f", 123.25);
//	printf("max:%f\n", DBL_MAX);
//	printf("max:%f\n", -DBL_MAX);
//	printf("min:%.1024f\n", DBL_MIN);
	printf("max:%Lf\n", LDBL_MAX);
	printf("min:%.16383Lf\n", LDBL_MIN);
//	printf("min:%.2000f\n", -DBL_MIN);
//	ft_printf("mmax:%f\n", DBL_MAX);
//	ft_printf("mmax:%f\n", -DBL_MAX);
//	ft_printf("mmin:%.1024f\n", DBL_MIN);
	ft_printf("max:%Lf\n",LDBL_MAX);
	ft_printf("mmin:%.16383Lf\n", LDBL_MIN);
//	ft_printf("mmin:%.2000f\n", -DBL_MIN);

//	printf("%f\n", 99368744177664.25);
//	ft_printf("%f\n", 99368744177664.25);
//	long double l = 1234.56;
//	ft_printf("%Lf\n", l);
//	printf("%Lf\n", l);
//	ft_printf("%f\n", 123321432523454.25);
//	ft_printf("ft_printf{%f}{%lf}{%Lf}\n", 1444565444646.6465424242242,
//		1444565444646.6465424242242, 1444565444646.6465424242242l);
//	printf("printf{%f}{%lf}{%Lf}", 1444565444646.6465424242242,
//		1444565444646.6465424242242, 1444565444646.6465424242242l);
/*
	char *mantissa;
	char *num;
	char *frt;
	char *rem;
	int exp;
	int size;

	exp = ft_double_mantissa(312.6, &mantissa);
	printf("exp:%d mantissa:%s\n", exp, mantissa);

//	size =  ft_double_exp(exp, 2, &num);
//	printf("size:%d num:%s:size:%d:\n", size, num + size, ft_strlen(num + size));
//	ft_double_i(mantissa, &frt, exp);
	mantissa += exp >= 0 ? exp + 1 : 0;
	exp = exp >= 0 ? 1 : exp * -1;
	ft_double_r(mantissa, &rem, 9, exp);
//	frt = frt[0] == '\0' ? frt + 1 : frt;
	printf("%s\n", rem + 1);
	ft_double_revert(mantissa, &num, exp, 0);
	printf("num:%s\n", num); 
	printf("%.8f\n", 312.15);
//	ft_printf("%.8f\n", -3.85);
*/
/*
	printf(":printf:%d\n", printf("%-5c", '\0'));
	printf(":ft_printf:%d\n", ft_printf("%-5c", '\0'));
	printf(":printf:%d\n", printf("%.09s", "hi low"));
	ft_printf(":ft_printf:%d\n", ft_printf("%.09s", "hi low"));
*/
/*
//  CHECK FT_DOUBLE_ITOA FUCCNTION
	printf("%s\n", ft_double_itoa(1.13, 3));
*/
/*
//  CHECK FT_DOUBLE_REVERT FUNCTION
	char *num;
	char *mantissa;
	long double nbr = 1.13;
	int	exponent = ft_double_mantissa(nbr, &mantissa);

	printf("exp:%d mantissa:%s\n", exponent, mantissa);
	ft_double_revert(mantissa, &num, exponent, 3);
	printf("%s\n", num);
*/
/*
//  CHECK ALL FUNCITONS IN FT_DOUBLE_CONVERT EXCEPT REVERT
	char *mantissa;
	char *integer;
	char *remainder;
	long double nbr = 0.12;
	int exponent = ft_double_mantissa(nbr, &mantissa);

	printf("exp:%d mantissa:%s\n", exponent, mantissa);
	ft_double_i(mantissa, &integer, exponent);
	mantissa += exponent >= 0 ? exponent + 1 : 0;
	ft_double_r(mantissa, &remainder, 2, exponent);
	if (remainder[0] == '1')
		ft_double_plusrem(integer, ft_strlen(integer) - 1);
	remainder++;
	printf("%s.%s\n", integer, remainder);
	printf("%.10lf\n", 0.12);
*/
	return (0);
}

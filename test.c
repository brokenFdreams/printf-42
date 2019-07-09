/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:59:30 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/09 15:23:46 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int ft_double_mantissa(long double nbr, char **mantissa);
void    ft_double_r(char *mantissa, char **remainder, int precision, int exp);
int ft_double_i(char *mantissa, char **integer, int exponent);
void ft_double_plusrem(char *num, int size);

int	main(void)
{
	char *mantissa;
	char *num;
	int exp;

	printf("%ju\n", ft_exponentiation(65, 2));
	printf("%s\n", ft_uint_itoa(2818306651739822853, 2));
	exp = ft_double_mantissa(3.85, &mantissa);
	printf("exp:%d mantissa:%s\n", exp, mantissa);
	ft_double_revert(mantissa, &num, exp, 8);
	printf("num:%s\n", num); 
	ft_printf("%.8f\n", -3.85);
/*	printf(":printf:%d\n", printf("%-5c", '\0'));
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
	uintmax_t power = ft_exponentiation(exponent, 2);

	printf("exp:%d mantissa:%s\n", exponent, mantissa);
	mantissa += ft_double_i(mantissa, &integer, exponent);
	ft_double_r(mantissa, &remainder, 2, exponent);
	if (remainder[0] == '1')
		ft_double_plusrem(integer, ft_strlen(integer) - 1);
	remainder++;
	printf("%s.%s\n", integer, remainder);
	printf("%.10lf\n", 0.12);
*/
	return (0);
}

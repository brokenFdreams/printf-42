/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:59:30 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/05 16:27:46 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int ft_double_mantissa(long double nbr, char **mantissa);
void    ft_double_r(char *mantissa, char **remainder, int precision, int exp);
int ft_double_i(char *mantissa, char **integer, int exponent);
/*
static void ft_double_r(char *mantissa, char **remainder, int precision, int exp)
{
	uintmax_t	power;
	char		*tmp;
	int			size;
	int			len;
	int			i;

	i = 0;
	power = 5;
	if (!(*remainder = ft_strnew(652)))
		ft_error();
	size = 1;
	while (exp++ <= 0)
		(*remainder)[size++] = '0';
	while (mantissa[i])
	{
		tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
		len = ft_strlen(tmp) - 1;
		printf("tmp:%s rem:%s\n", tmp, *remainder + 1);
		ft_double_addition(*remainder, &tmp, size, len);
		size++;
		power *= 5;
	}
	while (size <= precision + 1)
		(*remainder)[size++] = '0';
	i = precision + 1;
	if ((*remainder)[i] == '5')
	{
		i++;
		while ((*remainder)[i] && (*remainder)[i] == '0')
			i++;
		if ((*remainder)[i] && (*remainder)[i] != '0')
			ft_double_plusrem(*remainder, precision);
	}
	else if ((*remainder)[i] > '5' && (*remainder)[i] <= '9')
			ft_double_plusrem(*remainder, precision);
	(*remainder)[precision + 1] = '\0';
}
*/

int	main(void)
{

/*
  CHECK FT_DOUBLE_ITOA FUCCNTION
printf("%s\n", ft_double_itoa(1.13, 3));
*/

//  CHECK FT_DOUBLE_REVERT FUNCTION
	char *num;
	char *mantissa;
	long double nbr = 122.132;
	int	exponent = ft_double_mantissa(nbr, &mantissa);

	printf("exp:%d mantissa:%s\n", exponent, mantissa);
	ft_double_revert(mantissa, &num, exponent, 3);
	printf("%s\n", num);

/*
//  CHECK ALL FUNCITONS IN FT_DOUBLE_CONVERT EXCEPT REVERT
	char *mantissa;
	char *integer;
	char *remainder;
	long double nbr = 122.12;
	int exponent = ft_double_mantissa(nbr, &mantissa);
	uintmax_t power = ft_exponentiation(exponent, 2);

	mantissa += ft_double_i(mantissa, &integer, exponent);
	ft_double_r(mantissa, &remainder, 4, exponent);
	remainder++;
	printf("%s.%s\n", integer, remainder);
*/
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:59:30 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/05 14:05:21 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

int ft_double_mantissa(long double nbr, char **mantissa);
int ft_double_i(char *mantissa, char **integer, int exponent);

static void ft_double_plusrem(char *num, int size)
{
    if (num[size] == '9')
    {
        num[size] = '0';
        ft_double_plusrem(num, size - 1);
    }
    else if (num[size] == '.')
        ft_double_plusrem(num, size - 1);
    else if (num[size] == '\0')
        num[size] = '1';
    else
        num[size] += 1;
}

static void ft_double_addition(char *num, char **tmp, int size, int len)
{
    int a;
    int b;

    b = 0;
    while (size >= 0 && len >= 0 && num[size] != '.')
    {
        if (ft_isdigit(num[size]))
            a = num[size] - '0';
        else
            a = 0;
        b += (*tmp)[len--] - '0';
        a = a + b;
        b = a >= 10 ? 1 : 0;
        num[size--] = a > 10 ? a % 10 + '0' : a + '0';
    }
    if (b)
        ft_double_plusrem(num, size);
    ft_strdel(tmp);
}

void    ft_double_r(char *mantissa, char **remainder, int precision)
{
    uintmax_t   power;
    char        *tmp;
    int         i;
    int         len;
    int         size;

    i = 0;
    power = 5;
    if (!(*remainder = ft_strnew(652)))
        ft_error();
    size = 0;
    while (mantissa[i])
    {
        tmp = ft_uint_itoa(power * (mantissa[i++] - '0'), 10);
        len = ft_strlen(tmp) - 1;
		if (len + 1 > size)
			size = len + 1;
        ft_double_addition(*remainder, &tmp, size, len);
        size++;
        power *= 5;
    }
    i = precision + 1;
    if ((*remainder)[i] == '5')
    {
        while ((*remainder)[i] && (*remainder)[i++] == '0')
            i++;
        if ((*remainder)[i] && (*remainder)[i] != '0')
            if (((*remainder)[precision] - '0') % 2 != 0)
                ft_double_plusrem(*remainder, precision);
    }
    (*remainder)[precision + 1] = '\0';
}

int	main(void)
{
	char *mantissa;
	char *integer;
	char *remainder;
	long double nbr = 122.12;
	int exponent = ft_double_mantissa(nbr, &mantissa);
	uintmax_t power = ft_exponentiation(exponent, 2);

//	integer = ft_uint_itoa((uintmax_t)nbr, 2);
//	mantissa = ft_strnew(65);
//	mantissa = ft_strnjoin(mantissa, integer, ft_strlen(integer), 0);
	printf("exp:%d ", exponent);
	printf("%s\n", mantissa);
	printf("exp:%d ", ft_double_mantissa(0.00005, &mantissa));
	printf("%s\n", mantissa);
//	printf("%d\n", exponent);
//	mantissa += ft_double_i(mantissa, &integer, exponent);
//	printf("%s\n", mantissa);
//	ft_double_r(mantissa, &remainder, 2);
//	printf("%d\n", ft_double_i(mantissa, &integer, exponent));
//	printf("%ju\n", power);
//	printf("%s.%s\n", integer, remainder);
	return (0);
}

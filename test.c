/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:59:30 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/01 14:05:06 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"
#include <stdio.h>

static char *ft_double_rem_binary(long double rem, int length)
{
    char    *remainder;
    int     i;
    int    size;

    i =0;
    size = 64 - length;
    if (!(remainder = ft_strnew(size)))
        ft_error();
    while (i < size)
    {
		rem *= 2;
		remainder[i++] = rem>= 1 ? '1' : '0';
		rem = rem >= 1 ? rem - 1 : rem;
    }   
    return (remainder);
}

/*                                                                                
** Get double in binary system                                                    
** Return its value in string                                                     
*/

static char *ft_double_tobinary(long double nbr)
{
    char    *binary;
    char    *tmp;
    int     i;
    int     size;

    i = 0;
    size = 65;
    if (!(binary = ft_strnew(size)))
        ft_error();
    tmp = ft_itoa_base((uintmax_t)nbr, 2);
	binary = ft_strcpy(binary, tmp);
    ft_strdel(&tmp);
    tmp = ft_double_rem_binary(nbr - (uintmax_t) nbr, ft_strlen(binary));
    binary = ft_strcat(binary, ".");
    binary = ft_strcat(binary, tmp);
    ft_strdel(&tmp);
    return (binary);
}

int	main(void)
{
	printf("%s\n", ft_double_tobinary(12.14));
	return (0);
}

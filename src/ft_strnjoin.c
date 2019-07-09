/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 12:05:34 by fsinged           #+#    #+#             */
/*   Updated: 2019/07/09 13:45:09 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** for more speed
** Copy of strncat, but more faster
*/

char	*ft_strnjoin(char *s1, const char *s2, size_t n, size_t pos)
{
	size_t j;

	j = 0;
	while (s1[pos] != '\0')
		pos++;
	if (s2[j] == '\0' && n == 1)
		s1[pos] = '\0';
	else
		while (s2[j] != '\0' && j < n)
		{
			s1[pos + j] = s2[j];
			j++;
		}
	return (s1);
}

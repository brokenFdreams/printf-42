/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsinged <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 16:19:37 by fsinged           #+#    #+#             */
/*   Updated: 2019/05/29 13:26:50 by fsinged          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_puthex(va_list ap, int flag, t_flags *flags)
{
	char			*str;
	int				count;
	unsigned int	cnum;

	count = 1;
	cnum = num;
	while ((cnum / 16) > 0)
	{
		cnum /= 16;
		count++;
	}
	str = (char*)malloc(sizeof(char) * (count + 1));
	str[count--] = '\0';
	while (count >= 0)
	{
		cnum = num % 16;
		num = num / 16;
		if (cnum < 10)
			str[count--] = cnum + '0';
		else if (flag == 0)
			str[count--] = cnum - 10 + 'a';
		else
			str[count--] = cnum - 10 + 'A';
	}
	cnum = ft_putstr(str, flags);
	ft_strdel(&str);
	return (cnum);
}

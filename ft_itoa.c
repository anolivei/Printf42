/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:24:29 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/06 03:14:19 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	num;
	
	if (n == 0)
		return ("0");
	num = n < 0 ? n * (-1) : n;
	len = n <= 0 ? 1 : 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	num = n < 0 ? n * (-1) : n;
	if (n < 0)
		str[0] = '-';
	while (num  > 9)
	{
		str[len-- - 1] = ((num % 10) + '0');
		num = num / 10;
	}
	str[len - 1] = ((num % 10) + '0');
	return (str);
}

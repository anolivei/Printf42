/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:47:00 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/06 03:06:38 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtox(unsigned long int  n, const char *base, char c)
{
	char				*str;
	unsigned long int	len;
	unsigned long int	num;
	
	if (n == 0)
		return ("0");
	num = n;
	len = 0;
	while (num)
	{
		num = num / 16;
		len++;
	}
	str = (char *)malloc(sizeof (char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	num = n;
	while (len-- > 0)
	{
		str[len] = base[n % 16];
		n = n / 16;
	}
	return ((ft_strlen(str) > 8 && c != 'p') ? &str[1] : str);
}

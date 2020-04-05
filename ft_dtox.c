/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtox.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 21:47:00 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 18:29:17 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_dtox(uintmax_t n, const char *base)
{
	char		*str;
	int			len;
	uintmax_t	num;
	
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
	while (len-- > 0)
	{
		str[len] = base[n % 16];
		n = n / 16;
	}
	return (str);
}



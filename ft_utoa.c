/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 03:29:24 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/15 05:08:52 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int u)
{
	int		len;
	unsigned int	n;
	char		*str;

	len = u == 0 ? 1 : 0;
	n = u;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len--] = u % 10 + '0';
		u = u / 10;
	}
	return (str);
}

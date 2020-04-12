/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 06:00:00 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 02:11:56 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_utoa(unsigned int u)
{
	char			*str;
	int				len;
	unsigned int	num;

	num = u;
	len = u == 0 ? 1 : 0;
	while (num > 0)
	{
		num = num / 10;
		len++;
	}
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == 0)
		return (0);
	str[len] = '\0';
	num = u;
	while (num > 9)
	{
		str[len-- - 1] = ((num % 10) + '0');
		num = num / 10;
	}
	str[len - 1] = ((num % 10) + '0');
	return (str);
}

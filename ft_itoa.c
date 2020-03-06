/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 04:15:20 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/01 20:04:15 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

static int	count_digits(int n)
{
	int		i;
	unsigned int	num;
	
	i = 0;
	if (n < 0)
	{
		num = n * (-1);
		i = 1;
	}
	else
		num = n;
	while (num > 0)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char		*itoa;
	unsigned int	num;
	int		n_digits;
	int		i;
	
	i = 0;
	n_digits = count_digits (n);
	itoa = (char *)malloc(sizeof(char) * (n_digits + 1));
	if (itoa == 0)
		return (0);
	if (n < 0)
	{
		itoa[i] = '-';
		num = n * (-1);
		i++;
	}
	else
		num = n;
	if (num >= 0  && num <= 9)
	{
		itoa[i] = num + 48;
		num = num / 10;
	}
	else if (num > 0)
	{
		while (i < n_digits)
		{
			itoa[i] = num % 10 + 48;
			i++;
			ft_itoa(num / 10);

		}
	}
	itoa[i] = '\0';
	return (itoa);
}

int	main(void)
{
	printf("%s\n", ft_itoa(158282));
}

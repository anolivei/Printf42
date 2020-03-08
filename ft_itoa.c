/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 19:24:29 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/04 18:22:57 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(int n)
{
	int				n_digits;
	unsigned int	num;

	n_digits = 0;
	if (n < 0)
		num = n * (-1);
	else
		num = n;
	while (num > 0)
	{
		num = num / 10;
		n_digits++;
	}
	return (n_digits);
}

static int	power(int n_digits)
{
	int p10;

	p10 = 1;
	while (n_digits > 0)
	{
		p10 = p10 * 10;
		n_digits--;
	}
	return (p10);
}

char		*ft_itoa(int n)
{
	char			*itoa;
	int				p10;
	int				i;
	unsigned int	num;

	if (!(itoa = (char *)malloc((count_digits(n) + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	if (n < 0)
	{
		num = num * (-1);
		itoa[i++] = '-';
	}
	else
		num = n;
	p10 = power(count_digits(n) - 1);
	while (p10 > 0)
	{
		itoa[i++] = (num / p10 % 10 + 48);
		p10 = p10 / 10;
	}
	itoa[i] = '\0';
	return (itoa);
}

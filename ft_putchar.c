/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 22:14:06 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 16:33:15 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putchar_len(const char *c, int len)
{
	ft_putchar(*c);
	len++;
	return (len);
}

void	ft_putchar_int(int len, int i, char c)
{
	while (len-- > i)
		ft_putchar(c);
}

int		ft_putchar_minus(char *str, t_flags flag, int len, int *i)
{
	if (str[*i] == '-')
	{
		ft_putchar('-');
		if (flag.precision)
			len = len + 1;
		*i = 1;
	}
	return (len);
}

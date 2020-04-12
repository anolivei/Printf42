/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_aux.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:26:04 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 17:28:33 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int_5(char *str, t_flags flag, int len_s, int len)
{
	int i;

	i = 0;
	if (flag.justify == 0)
	{
		if (str[0] == '-')
			ft_putchar_int(flag.width, flag.precision + 1, ' ');
		else
			ft_putchar_int(flag.width, flag.precision, ' ');
	}
	len = ft_putchar_minus(str, flag, 0, &i) + flag.precision;
	ft_putchar_int(len, len_s, '0');
	ft_putstr(&str[i]);
	if (flag.justify == 1)
	{
		if (str[0] == '-')
			ft_putchar_int(flag.width, flag.precision + 1, ' ');
		else
			ft_putchar_int(flag.width, flag.precision, ' ');
	}
	len = flag.width > flag.precision ? flag.width : flag.precision;
	return (str[0] == '-' && flag.width <= flag.precision ? len + 1 : len);
}

int	ft_print_int_6(char *str, t_flags flag, int len_s, int len)
{
	int i;

	i = 0;
	if (flag.width > len_s && flag.precision <= len_s)
	{
		if (flag.zero && flag.precision < 0)
		{
			ft_putchar_minus(str, flag, flag.width, &i);
			ft_putchar_int(flag.width, len_s, '0');
		}
		else
			ft_putchar_int(flag.width, len_s, ' ');
		ft_putstr(&str[i]);
		return (flag.width);
	}
	else
	{
		len = flag.precision;
		len = ft_putchar_minus(str, flag, len, &i);
		ft_putchar_int(len, len_s, '0');
		ft_putstr(&str[i]);
		return (str[0] == '-' ? flag.precision + 1 : flag.precision);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:01:25 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/03 01:27:30 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_just(char *str, int len)
{
		while (len-- > ft_strlen(str))
				ft_putchar(' ');
}

int	ft_print_int(int arguments, t_flags flag, int len)
{
	char	*str;

	str = ft_itoa(arguments);
	if ((flag.width == 0 || flag.width <= ft_strlen(str))  && flag.dot == 0)
	{
		len = ft_putstr(str);
		return (len);
	}
	else if (flag.width > ft_strlen(str))
	{
		if (flag.justify == 0)
			ft_putchar_just(str, flag.width);
		ft_putstr(str);
		if (flag.justify == 1)
			ft_putchar_just(str, flag.width);
		return (flag.width);
	}
	return (0);

}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:01:25 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/04 02:22:24 by anolivei         ###   ########.fr       */
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
	int		len_s;
	int		i;

	str = ft_itoa(arguments);
	len_s = ft_strlen(str);
	if ((flag.width == 0 || flag.width <= len_s)  && flag.precision <= len_s)
	{
		len = ft_putstr(str);
		return (len);
	}
	else if (flag.width > len_s && flag.zero == 0)
	{
		if (flag.justify == 0)
			ft_putchar_just(str, flag.width);
		ft_putstr(str);
		if (flag.justify == 1)
			ft_putchar_just(str, flag.width);
		return (flag.width);
	
	}
	else if (flag.precision > len_s || (flag.zero && flag.width > len_s))
	{
		i = 0;
		len = flag.zero ? flag.width : flag.precision;
		if (str[i] == '-')
		{
			ft_putchar('-');
			if (flag.precision)
				len = len + 1;
			i++;
		}
		while (len-- > len_s)
			ft_putchar('0');
		ft_putstr(&str[i]);
		len = flag.zero ? flag.width : flag.precision;
		len = (str[0] == '-' && flag.precision) ? flag.precision + 1 : len;
		return (len);
	}
	return (0);

}

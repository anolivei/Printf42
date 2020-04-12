/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:01:25 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 17:33:28 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_int_1(char *str, t_flags flag)
{
	if (str[0] == '0' && !flag.width)
		return (0);
	else if (str[0] == '0' && flag.width)
		return (ft_putstr(" "));
	else
		return (ft_putstr(str));
}

static int	ft_print_int_2(char *str, t_flags flag, int len_s)
{
	if (flag.justify)
	{
		ft_putstr(str[0] == '0' ? " " : str);
		ft_putchar_int(flag.width, len_s, ' ');
	}
	else if (flag.width > len_s)
	{
		ft_putchar_int(flag.width, len_s, ' ');
		ft_putstr(str[0] == '0' ? " " : str);
	}
	else
		ft_putchar_int(flag.width, 0, ' ');
	return (flag.width);
}

static int	ft_print_int_3(char *str, t_flags flag, int len_s)
{
	if (flag.justify == 0)
		ft_putchar_int(flag.width, len_s, ' ');
	ft_putstr(str);
	if (flag.justify == 1)
		ft_putchar_int(flag.width, len_s, ' ');
	return (flag.width);
}

static int	ft_print_int_4(char *str, t_flags flag, int len_s, int len)
{
	int i;

	i = 0;
	if (flag.width >= 0 && flag.precision > len_s)
	{
		len = flag.precision + ft_putchar_minus(str, flag, len, &i);
		ft_putchar_int(len, len_s, '0');
		ft_putstr(&str[i]);
		return (str[0] == '-' ? flag.precision + 1 : flag.precision);
	}
	else
	{
		len = flag.zero ? flag.width : flag.precision;
		len = ft_putchar_minus(str, flag, len, &i);
		ft_putchar_int(len, len_s, '0');
		ft_putstr(&str[i]);
		i = flag.zero ? flag.width : flag.precision;
		return ((str[0] == '-' && flag.precision) ? flag.precision + 1 : i);
	}
}

int			ft_print_int(char *str, t_flags flag, int len_s)
{
	len_s = ft_strlen(str);
	if (flag.dot && !flag.precision && flag.width <= len_s)
		return (ft_print_int_1(str, flag));
	if (flag.precision == 0 && flag.width > 0 && flag.dot)
		return (ft_print_int_2(str, flag, len_s));
	if ((!flag.width || flag.width <= len_s) && flag.precision <= len_s)
	{
		if (str[0] == '-' && flag.precision == len_s && flag.width <= len_s)
			return (ft_putstr(ft_strjoin("-0", &str[1])));
		return (ft_putstr(str));
	}
	if (flag.width > len_s && flag.zero == 0 && flag.precision < len_s)
		return (ft_print_int_3(str, flag, len_s));
	if ((flag.precision > len_s && flag.width <= len_s && !flag.zero) ||
			(flag.zero && flag.width > len_s && !flag.precision) ||
			(flag.precision >= len_s && flag.zero && flag.width <= len_s))
		return (ft_print_int_4(str, flag, len_s, 0));
	if (flag.width > len_s && flag.precision >= len_s)
		return (ft_print_int_5(str, flag, len_s, 0));
	else
		return (ft_print_int_6(str, flag, len_s, 0));
}

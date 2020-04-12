/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:43:11 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 05:17:49 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_string_w(char *str, t_flags flag, int ret, int len)
{
	char c;

	c = flag.zero == 1 ? '0' : ' ';
	if (flag.dot == 0)
	{
		if (flag.justify > 0)
			ft_putstr(str);
		while (ret-- > len)
			write(1, &c, 1);
		if (flag.justify == 0)
			ft_putstr(str);
		return (flag.width > len ? flag.width : len);
	}
	else
	{
		while (ret-- > 0)
			write(1, &c, 1);
		return (flag.width);
	}
}

static int	ft_print_string_w_j(char *str, t_flags flag, int ret, int len)
{
	char c;

	c = flag.zero == 1 ? '0' : ' ';
	if (flag.dot == 0)
	{
		ft_putstr(str);
		while (len-- > ft_strlen(str))
			write(1, &c, 1);
		return (flag.width > ft_strlen(str) ? flag.width : ft_strlen(str));
	}
	else
	{
		while (ret-- > 0)
			write(1, &c, 1);
		return (flag.width);
	}
}

static void	ft_print_string_putchar(char *str, t_flags flag)
{
	int i;

	i = 0;
	while (i < flag.precision && str[i])
		ft_putchar(str[i++]);
}

static int	ft_print_string_w_p(char *str, t_flags flag, int ret, int len)
{
	char	c;

	c = flag.zero == 1 ? '0' : ' ';
	if (flag.justify > 0)
		ft_print_string_putchar(str, flag);
	if (flag.precision >= len)
	{
		while (ret-- > len)
			write(1, &c, 1);
		ret = flag.width > len ? flag.width : len;
	}
	if (flag.precision < len)
	{
		while (ret-- > flag.precision)
			write(1, &c, 1);
		if (flag.width > flag.precision)
			ret = flag.width;
		else
			ret = flag.precision;
	}
	if (flag.justify == 0)
		ft_print_string_putchar(str, flag);
	return (ret);
}

int			ft_print_string(char *str, t_flags flag, int ret)
{
	if (str == NULL)
		str = "(null)";
	if (flag.precision < 0)
		flag.precision = ft_strlen(str);
	if (flag.width == 0 && flag.precision == 0)
	{
		if (flag.dot == 0)
			return (ft_putstr(str));
		else
			return (0);
	}
	if (flag.width > 0 && flag.precision == 0)
		return (ft_print_string_w(str, flag, ret, ft_strlen(str)));
	if (flag.width == 0 && flag.precision > 0)
	{
		ft_print_string_putchar(str, flag);
		return (flag.precision < ft_strlen(str) ? flag.precision :
				ft_strlen(str));
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision == 0)
		return (ft_print_string_w_j(str, flag, ret, ft_strlen(str)));
	if (flag.width > 0 && flag.precision > 0)
		return (ft_print_string_w_p(str, flag, ret, ft_strlen(str)));
	return (0);
}

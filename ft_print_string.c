/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:43:11 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 22:02:07 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str, t_flags flag, int ret)
{
	int len;
	int i;
	char c;
	
	c = flag.zero == 1 ? '0' : ' ';
	if (str == NULL)
		str = "(null)";
	i = 0;
	len = ft_strlen(str);
	ret = flag.width;
	if (flag.precision < 0)
		flag.precision = len;
	if (flag.width == 0 && flag.precision == 0) 
	{
		if (flag.dot == 0)
		{
			ret = ft_putstr(str);
			return (ret);
		}
		else
			return (0);
	}
	if (flag.width > 0 && flag.precision == 0)
	{
		if (flag.dot == 0)
		{
			if (flag.justify > 0)
				ft_putstr(str);
			while (ret-- > len)
				write(1, &c, 1);
			if (flag.justify == 0)
				ft_putstr(str);
			ret = flag.width > len ? flag.width : len;
			return (ret);
		}
		else
		{
			while (ret-- > 0)
				write(1, &c, 1);
			return (flag.width);
		}
	}
	if (flag.width == 0 && flag.precision > 0)
	{
		while (i < flag.precision && str[i])
			ft_putchar(str[i++]);
		return (flag.precision < len ? flag.precision : len);
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision == 0)
	{
		if (flag.dot == 0)
		{
			ft_putstr(str);
			while (len-- > ft_strlen(str))
				write(1, &c, 1);
			len = flag.width > ft_strlen(str) ? flag.width : ft_strlen(str);
			return (len);
		}
		else
		{
			while (ret-- > 0)
				write(1, &c, 1);
			return (flag.width);
		}
	}
	if (flag.width > 0 && flag.precision > 0)
	{
		if (flag.justify > 0)
		{
			while (i < flag.precision && str[i])
				ft_putchar(str[i++]);
		}
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
		{
			while (i < flag.precision && str[i])
				ft_putchar(str[i++]);
		}
		return (ret);
	}	
	return (0);	
}

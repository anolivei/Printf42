/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:43:11 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/14 22:03:45 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str, t_flags flag, int ret)
{
	int len;
	int i;
	
	i = 0;
	len = ft_strlen(str);
	ret = flag.width;
	if (flag.width == 0 && flag.precision == 0)
	{
		ret = ft_putstr(str);
		return (ret);
	}
	if (flag.width > 0 && flag.precision == 0)
	{
		if (flag.justify > 0)
			ft_putstr(str);
		while (ret-- > len)
			write(1, " ", 1);
		if (flag.justify == 0)
			ft_putstr(str);
		ret = flag.width > ft_strlen(str) ? flag.width : ft_strlen(str);
		return (ret);
	}
	if (flag.width == 0 && flag.precision > 0)
	{
		while (i < flag.precision && str[i])
			ft_putchar(str[i++]);
		return (flag.precision < len ? flag.precision : len);
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision == 0)
	{
		ft_putstr(str);
		while (len-- > ft_strlen(str))
			write(1, " ", 1);
		len = flag.width > ft_strlen(str) ? flag.width : ft_strlen(str);
		return (len);
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
				write(1, " ", 1);
			ret = flag.width > len ? flag.width : len;
		}
		if (flag.precision < len)
		{
			while (ret-- > flag.precision)
				write(1, " ", 1);
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

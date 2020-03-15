/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:43:11 by anolivei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/15 02:02:25 by anolivei         ###   ########.fr       */
=======
/*   Updated: 2020/03/14 06:11:23 by anolivei         ###   ########.fr       */
>>>>>>> parent of 524cd60... manodoceu
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str, t_flags flag, int len)
{
	int i;
<<<<<<< HEAD
	char c;
	
	c = flag.zero == 1 ? '0' : ' ';
	if (str == NULL)
		str = "(null)";
	i = 0;
	len = ft_strlen(str);
	ret = flag.width;
	if (flag.width == 0 && flag.precision == 0) 
	{
		if (flag.dot == 0)
		{
			ret = ft_putstr(str);
			return (ret);
		}
		else
			return (0);
=======

	i = 0;
	len = flag.width;
	if (flag.width == 0 && flag.justify == 0 && flag.precision == 0)
	{
		len = ft_putstr(str);
		return (len);
>>>>>>> parent of 524cd60... manodoceu
	}
	if (flag.width > 0 && flag.justify == 0 && flag.precision == 0)
	{
<<<<<<< HEAD
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
=======
		while (len-- > (int)ft_strlen(str))
			write(1, " ", 1);
		ft_putstr(str);
		len = flag.width > (int)ft_strlen(str) ? flag.width : ft_strlen(str);
		return (len);
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision == 0)
	{
		ft_putstr(str);
		while (len-- > (int)ft_strlen(str))
			write(1, " ", 1);
		len = flag.width > (int)ft_strlen(str) ? flag.width : ft_strlen(str);
		return (len);
>>>>>>> parent of 524cd60... manodoceu
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision > 0)
	{
<<<<<<< HEAD
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
=======
		while (i < flag.precision && str[i])
			ft_putchar(str[i++]);
		i = flag.width > flag.precision ? flag.width : flag.precision;	
		while (len-- > (int)ft_strlen(str))
			write(1, " ", 1);
		len = flag.width > (int)ft_strlen(str) ? flag.width : ft_strlen(str);
		return (len);
>>>>>>> parent of 524cd60... manodoceu
	}	
	return (0);	
}

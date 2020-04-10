/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/31 22:01:25 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/10 16:24:38 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void ft_putchar_space(char *str, int len)
{
		while (len-- > ft_strlen(str))
				ft_putchar(' ');
}

static int ft_putchar_minus (char *str, t_flags flag, int len, int *i)
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

static void ft_putchar_just_minus(char *str, t_flags flag, int len)
{
	len = flag.width;
	if (str[0] == '-')
	{
		while (len-- > flag.precision + 1)
			ft_putchar(' ');
	}
	else
	{
		while (len-- > flag.precision)
			ft_putchar(' ');
	}
}

int	ft_print_int(char *str, t_flags flag, int len)
{
	int		len_s;
	int		i;
	
//	printf("p %i\n", flag.precision);
	i = 0;
	len_s = ft_strlen(str);
	if (flag.dot && !flag.precision && flag.width <= len_s)
	{
		if (str[0] == '0' && flag.width == 0)
			return (0);
		else if (str[0] == '0' && flag.width)
		{
			write(1, " ", 1);
			return (1);
		}
		else
		{
			len = ft_putstr(str);
			return (len);
		}
	}
	else if (flag.precision == 0 && flag.width > 0 && flag.dot)
	{
		if (flag.justify)
		{
			len = flag.width;
			if (str[0] == '0')
					ft_putchar(' ');
			else
				ft_putstr(str);
			while (len-- > len_s)
				ft_putchar(' ');
			return (flag.width);
		}
		else
		{
			len = flag.width;
			while (len-- > 0)
				ft_putchar(' ');
			return (flag.width);
		}
	}
	else if ((flag.width == 0 || flag.width <= len_s)  && flag.precision <= len_s)
	{
	//	printf("entrou");
		if (str[0] == '-' && flag.precision == len_s && flag.width < len_s)
		{
			ft_putstr("-0");
			ft_putstr(&str[1]);
			return (flag.precision + 1);
		}
		len = ft_putstr(str);
		return (len);
	}
	else if (flag.width > len_s && flag.zero == 0 && flag.precision < len_s)
	{
		if (flag.justify == 0)
			ft_putchar_space(str, flag.width);
		ft_putstr(str);
		if (flag.justify == 1)
			ft_putchar_space(str, flag.width);
		return (flag.width);
	
	}
	else if ((flag.precision > len_s && flag.width <= len_s && !flag.zero) || (flag.zero && flag.width > len_s && !flag.precision) || (flag.precision >= len_s && flag.zero && flag.width <= len_s))
	{
		if (flag.width >= 0 && flag.precision > len_s )
		{
			len = flag.precision;
			if (str[0] == '-')
			{
				ft_putchar('-');
				i = 1;
				len++;			}
			while (len-- > len_s)
				ft_putchar('0');
			ft_putstr(&str[i]);
			return (str[0] == '-' ? flag.precision + 1 : flag.precision);
		}
		else
		{	
			len = flag.zero ? flag.width : flag.precision;
			len = ft_putchar_minus(str, flag, len, &i);
			while (len-- > len_s)
				ft_putchar('0');
			ft_putstr(&str[i]);
			len = flag.zero ? flag.width : flag.precision;
			len = (str[0] == '-' && flag.precision) ? flag.precision + 1 : len;
			return (len);
		}
	}
	else if (flag.width > len_s && flag.precision >= len_s)
	{
		if (flag.justify == 0)
			ft_putchar_just_minus(str, flag, len);
		len = 0;
		len = ft_putchar_minus(str, flag, len, &i);
		len = len + flag.precision;
		while (len-- > len_s)
			ft_putchar('0');
		ft_putstr(&str[i]);
		if (flag.justify == 1)
			ft_putchar_just_minus(str, flag, len);
		return (flag.width > flag.precision ? flag.width : flag.precision);
	}
	else if (flag.width && flag.precision && flag.zero)
	{
//		printf("entrou");
		if (flag.width > len_s && flag.precision <= len_s)
		{
			if (flag.precision < 0)
				flag.precision = flag.precision * (-1);
			len = flag.precision > len_s ? flag.width - flag.precision : flag.width;
			ft_putchar_space(str, len);
			len = flag.precision;
			while (len-- > len_s)
				ft_putchar('0');
			ft_putstr(str);
			return (flag.width);
		}
		if (flag.width < len_s && flag.precision > len_s)
		{
			len = flag.precision;
			len = ft_putchar_minus(str, flag, len, &i);
			while (len-- > len_s)
				ft_putchar('0');
			ft_putstr(&str[i]);
			return (str[0] == '-'? flag.precision + 1 : flag.precision);
		}
	}
	return (0);
}

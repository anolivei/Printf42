/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:35:24 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 18:51:13 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	arguments;
	int		len;
	int		i;
	t_flags	flag;
	va_start(arguments, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			flag = ft_clean_flags();
			i++;
			while(format[i] != '\0' && ft_strchr(FLAGS, format[i]) == 1)
			{
				flag = ft_verify_flags(format[i], arguments, flag);
				i++;	
			}
			if (format[i] == '\0')
				return (0);
			len = len + ft_verify_type(format[i++], arguments, flag);
		}
		if (format[i] != '\0')
		{
			len = ft_putchar_len(&format[i], len);
			i++;
		}
	}
	return (len);
}

int	ft_verify_type(char c, va_list arguments, t_flags flag)
{
	int len;
	
	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(arguments, int), flag, len);
	if (c == 's')
		len = ft_print_string(va_arg(arguments, char*), flag, len);
	if (c == '%')
		len = ft_print_pct('%', flag, len);
	if (c == 'd' || c == 'i')
		len = ft_print_int(ft_itoa(va_arg(arguments, int)), flag, len);
	if (c == 'u')
		len = ft_print_u(ft_utoa(va_arg(arguments, int)), flag, len);
	if (c == 'x')
		len = ft_print_hexa(ft_dtox(va_arg(arguments, unsigned long int), HEXA_LOWER), flag, len);
	if (c == 'X')
		len = ft_print_hexa(ft_dtox(va_arg(arguments, unsigned long int), HEXA_UPPER), flag, len);
/*	if (c == 'p')
		len = ft_print_pointer(va_arg(arguments, unsigned long int), flag);*/
	return (len);
}

t_flags	ft_verify_star(va_list arguments, t_flags flag)
{
	if (flag.dot == 0)
		flag.width = va_arg(arguments, int);
	else
		flag.precision = va_arg(arguments, int);
	if (flag.width < 0)
	{
		flag.justify = 1;
		flag.width = flag.width * (-1);
		flag.zero = 0;
	}
	return (flag);
}

t_flags	ft_verify_flags(const char c, va_list arguments, t_flags flag) 
{
	if (c == '0' && flag.justify == 0 && flag.width == 0)
		flag.zero = 1;
	else if (c == '*')
		ft_verify_star(arguments, flag);
	else if (c == '.')
		flag.dot = 1;
	else if (c == '-')
	{
		flag.justify = 1;
		flag.zero = 0;
	}
	else if (ft_strchr(DECIMAL, c))
	{
		if (flag.dot == 1)
			flag.precision = (flag.precision * 10) + (c - '0');
		else
			flag.width = (flag.width * 10) + (c - '0');
	}
	return (flag);
}

int	ft_putchar_len(const char *c, int len)
{
	ft_putchar(*c);
	len++;
	return (len);
}

t_flags	ft_clean_flags(void)
{
	t_flags flag;

	flag.zero = 0;
	flag.dot = 0;
	flag.width = 0;
	flag.precision = 0;
	flag.justify = 0;
	return (flag);
}
	

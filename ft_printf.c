/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:35:24 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 02:47:58 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;
	t_flags	flag;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i] != '\0')
	{
		while (format[i] == '%')
		{
			flag = ft_clean_flags();
			i++;
			while (format[i] != '\0' && ft_strchr(FLAGS, format[i]) == 1)
				flag = ft_verify_flags(format[i++], args, flag);
			if (format[i] == '\0')
				return (0);
			len = len + ft_verify_type(format[i++], args, flag);
		}
		if (format[i] != '\0' && format[i] != '%')
			len = ft_putchar_len(&format[i++], len);
	}
	return (len);
}

int		ft_verify_type(char c, va_list args, t_flags flag)
{
	int len;

	len = 0;
	if (c == 'c')
		len = ft_print_char(va_arg(args, int), flag, len);
	if (c == 's')
		len = ft_print_string(va_arg(args, char*), flag, len);
	if (c == '%')
		len = ft_print_pct('%', flag, len);
	if (c == 'd' || c == 'i')
		len = ft_print_int(ft_itoa(va_arg(args, int), len), flag, len);
	if (c == 'u')
		len = ft_print_int(ft_utoa(va_arg(args, int)), flag, len);
	if (c == 'x')
		len = ft_print_int(ft_dtox(va_arg(args, unsigned long int),
					HEXA_LOWER, c), flag, len);
	if (c == 'X')
		len = ft_print_int(ft_dtox(va_arg(args, unsigned long int),
					HEXA_UPPER, c), flag, len);
	if (c == 'p')
		len = ft_print_pointer(ft_dtox(va_arg(args, unsigned long int),
					HEXA_LOWER, c), flag, len);
	return (len);
}

t_flags	ft_verify_star(va_list args, t_flags flag)
{
	if (flag.dot == 0)
		flag.width = va_arg(args, int);
	else
		flag.precision = va_arg(args, int);
	if (flag.width < 0)
	{
		flag.justify = 1;
		flag.width = flag.width * (-1);
		flag.zero = 0;
	}
	return (flag);
}

t_flags	ft_verify_flags(const char c, va_list args, t_flags flag)
{
	if (c == '0' && flag.justify == 0 && flag.width == 0)
		flag.zero = 1;
	else if (c == '*')
		flag = ft_verify_star(args, flag);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 04:43:11 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/14 06:11:23 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_string(char *str, t_flags flag, int len)
{
	int i;

	i = 0;
	len = flag.width;
	if (flag.width == 0 && flag.justify == 0 && flag.precision == 0)
	{
		len = ft_putstr(str);
		return (len);
	}
	if (flag.width > 0 && flag.justify == 0 && flag.precision == 0)
	{
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
	}
	if (flag.width > 0 && flag.justify > 0 && flag.precision > 0)
	{
		while (i < flag.precision && str[i])
			ft_putchar(str[i++]);
		i = flag.width > flag.precision ? flag.width : flag.precision;	
		while (len-- > (int)ft_strlen(str))
			write(1, " ", 1);
		len = flag.width > (int)ft_strlen(str) ? flag.width : ft_strlen(str);
		return (len);
	}	
	return (0);	
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 19:33:44 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 20:35:49 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(char *str, t_flags flag, int len)
{
	char *s1;
	char *s2;

	s2 = "0x";
	s1 = ft_strjoin(s2, str);
	if (flag.precision == 0 && flag.dot == 1)
	{
		if (flag.width == 0)
		{
			len = ft_putstr(s2);
			return (len);
		}
		else
		{
			len = flag.width;
			while (len-- > 2)
				ft_putchar(' ');
			ft_putstr(s2);
			return (flag.width);
		}
	}
	else if (flag.precision > flag.width && flag.precision > ft_strlen(str))
	{
		len = ft_putstr(s2);
		len = len + ft_print_int(str, flag, len);
		return (len);
	}
	else
		len = ft_print_int(s1, flag, len);
	return (len);
}

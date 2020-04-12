/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 19:33:44 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 01:53:19 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer(char *str, t_flags flag, int len)
{
	char *s1;
	char *s2;

	s1 = "0x";
	s2 = ft_strjoin(s1, str);
	if (flag.precision == 0 && flag.dot == 1)
	{
		if (flag.width == 0)
			return (len = ft_putstr(s1));
		else
		{
			len = flag.width;
			while (len-- > 2)
				ft_putchar(' ');
			ft_putstr(s1);
			return (flag.width);
		}
	}
	else if (flag.precision > flag.width && flag.precision > ft_strlen(str))
		return (len = (ft_putstr(s1) + ft_print_int(str, flag, len)));
	else
		return (len = ft_print_int(s2, flag, len));
}

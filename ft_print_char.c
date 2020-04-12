/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/08 21:43:53 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/11 03:43:48 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_flags flag, int len)
{
	len = flag.width;
	if (flag.justify == 0 && flag.width == 0)
	{
		write(1, &c, 1);
		len = 1;
		return (len);
	}
	else if (flag.justify == 0 && flag.width > 0)
	{
		while (len-- > 1)
			write(1, " ", 1);
		write(1, &c, 1);
		len = flag.width;
		return (len);
	}
	else if (flag.justify == 1)
	{
		write(1, &c, 1);
		while (len-- > 1)
			write(1, " ", 1);
		len = flag.width;
		return (flag.width == 0 ? 1 : len);
	}
	return (0);
}

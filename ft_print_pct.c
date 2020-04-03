/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 03:13:39 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/31 21:58:58 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pct(char c, t_flags flag, int len)
{
	char space;

	space = flag.zero == 1 ? '0' : ' ';
	len = flag.width;
	if (flag.justify == 0 && flag.width == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	else if (flag.justify == 0 && flag.width > 0)
	{
		while (len-- > 1)
			write(1, &space, 1);
		write(1, &c, 1);
		return (flag.width);
	}
	else if (flag.justify == 1 && flag.width > 0)
	{
		write(1, &c, 1);
		while (len-- > 1)
			write(1, &space, 1);
		return (flag.width);
	}
	return (0);
}

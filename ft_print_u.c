/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 06:39:31 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 07:46:34 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_u(unsigned int u, t_flags flag, int len)
{
	char *str;

	str = ft_utoa(u);
	if (u >= 4294967295)
	{
		len = ft_putstr(str);
		flag.width = flag.width;
	}
	else
		len = ft_print_int(u, flag, len);
	return (len);
}

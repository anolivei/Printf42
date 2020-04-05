/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/05 18:18:59 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/05 18:25:18 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hexa(unsigned long int n, char *base, t_flags flag, int len)
{
	char *str;

	str = ft_dtox(n, base);
	len = ft_print_string(str, flag, len);
	return (len);
}

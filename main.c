/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:05:59 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/14 06:06:49 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int t_orig;
	int t_mine;
// CHAR
//	t_mine = ft_printf("printfm: %15c", 'c');
//	printf("(%d)\n", t_mine);
//	t_orig = printf("printfo: %15c", 'c');
//	printf("(%d)\n",t_orig);
// STRING
	t_mine = ft_printf("printfm: %-5.3s", "corona");
	printf("(%d)\n", t_mine);
	t_orig = printf("printfo: %-5.3s", "corona");
	printf("(%d)\n",t_orig);

	return (0);
}

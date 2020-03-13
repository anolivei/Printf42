/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:05:59 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/13 00:30:00 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int t_orig;
	int t_mine;

	t_mine = ft_printf("printfm: %-5c", 'c');
	//printf("(%d)",t_mine);

	t_orig = printf("(%d)ntfo: %-5c",t_mine ,'c');
	printf("(%d)\n",t_orig);
	return (0);
}

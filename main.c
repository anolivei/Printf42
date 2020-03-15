/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:05:59 by anolivei          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/15 01:52:17 by anolivei         ###   ########.fr       */
=======
/*   Updated: 2020/03/14 06:06:49 by anolivei         ###   ########.fr       */
>>>>>>> parent of 524cd60... manodoceu
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
<<<<<<< HEAD
	t_mine = ft_printf("printfm: %08s", "oioioi");
	printf("(%d)\n", t_mine);
	t_orig = printf("printfo: %08s", "oioioi");
=======
	t_mine = ft_printf("printfm: %-5.3s", "corona");
	printf("(%d)\n", t_mine);
	t_orig = printf("printfo: %-5.3s", "corona");
>>>>>>> parent of 524cd60... manodoceu
	printf("(%d)\n",t_orig);

	return (0);
}

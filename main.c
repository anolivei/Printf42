/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:05:59 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/15 05:52:34 by anolivei         ###   ########.fr       */
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
//	t_mine = ft_printf("printfm: %08s", "oioioi");
//	printf("(%d)\n", t_mine);
//	t_orig = printf("printfo: %08s", "oioioi");
//	printf("(%d)\n",t_orig);
// UNSIGNED INT
//	char *utoa;
//	utoa = ft_utoa(5);
//	printf("%s\n", utoa);
//	INT
	char *itoa;
	itoa = ft_itoa('\0');
	printf("%s\n", itoa);
	return (0);
}

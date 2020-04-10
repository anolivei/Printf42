/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 21:05:59 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/10 19:13:01 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int		a = -5;
//	int		b = 4;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
//	int		f = 42;
//	int		g = 25;
//	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
//	char	*n = "abcdefghijklmnop";
//	char	*o = "-a";
//	char	*p = "-12";
//	char	*q = "0";
//	char	*r = "%%";
//	char	*s = "-2147483648";
//	char	*t = "0x12345678";
//	char	*u = "-0";

	int t_orig;
	int t_mine;
//	char *t_mine;
// CHAR
//	t_mine = ft_printf("printfm: %15c", 'c');
//	printf("(%d)\n", t_mine);
//	t_orig = printf("printfo: %15c", 'c');
//	printf("(%d)\n",t_orig);
//
// STRING
//	t_mine = ft_printf("printfm: %08s", "oioioi");
//	printf("(%d)\n", t_mine);
//	t_orig = printf("printfo: %08s", "oioioi");
//	printf("(%d)\n",t_orig);
//
// UNSIGNED INT
//	char *utoa;
//	utoa = ft_utoa(5);
//	printf("%s\n", utoa);
//
//	ITOA
//	char *itoa;
//	itoa = ft_itoa('\0');
//	printf("%s\n", itoa);
//	return (0);
//
//	INT
//	t_mine = ft_printf("printfm: %-8i", 17);
//	printf("(%d)\n", t_mine);
//	t_orig = printf("printfo: %-8i", 17);
//	printf("(%d)\n",t_orig);
//
//	UTOA
//	t_mine = ft_utoa(0);
//	printf("%s\n", t_mine);
//
//	DTOX
//		ft_printf("sou lindo %d",10);
//		t_mine = ft_dtox(0, HEXA_UPPER, 'x');
//		printf("%s\n", t_mine);
//  
//STAR
//
//PRINTF	
	t_mine = ft_printf("printfm: %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
	printf("(%d)\n",t_mine);
	t_orig = printf("printfo: %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X, %0*u, %0*x, %0*X", a, i, a, i, a, i, a, j, a, j, a, j, a, k, a, k, a, k, a, l, a, l, a, l, a, m, a, m, a, m, a, c, a, c, a, c, a, d, a, d, a, d, a, e, a, e, a, e);
	printf("(%d)\n",t_orig);
}

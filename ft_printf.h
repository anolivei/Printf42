/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:48:50 by anolivei          #+#    #+#             */
/*   Updated: 2020/04/12 04:19:49 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*
** INCLUDES
*/

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

/*
**	DEFINES
*/

# define FLAGS			"-0.*0123456789"
# define DECIMAL		"0123456789"
# define HEXA_LOWER		"0123456789abcdef"
# define HEXA_UPPER		"0123456789ABCDEF"

/*
**	STRUCTURE
*/

typedef struct	s_flags
{
	int		zero;
	int		dot;
	int		width;
	int		precision;
	int		justify;
}				t_flags;

/*
** PRINTERS
*/

int				ft_printf(const char *format, ...);
int				ft_print_pct(char c, t_flags flag, int len);
int				ft_print_char(char c, t_flags flag, int len);
int				ft_print_string(char *str, t_flags flag, int ret, int i);
int				ft_print_int(char *s, t_flags flag, int len);
int				ft_print_pointer(char *str, t_flags flag, int len);

/*
**	UTILS
*/

int				ft_strlen(const char *str);
int				ft_strchr(char *s, int c);
char			*ft_strjoin(char *s1, char *s2);
int				ft_putchar(char c);
int				ft_putchar_len(const char *c, int len);
int				ft_putstr(char *c);
char			*ft_utoa(unsigned int u);
char			*ft_itoa(int n, int len);
char			*ft_dtox(unsigned long int n, const char *base, char c);
int				ft_verify_type(char c, va_list arguments, t_flags flag);
t_flags			ft_verify_star(va_list arguments, t_flags flag);
t_flags			ft_verify_flags(const char c, va_list arguments, t_flags flag);
t_flags			ft_clean_flags(void);

#endif

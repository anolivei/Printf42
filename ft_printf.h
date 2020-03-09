/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anolivei <anolivei@student.42sp.org>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 22:48:50 by anolivei          #+#    #+#             */
/*   Updated: 2020/03/08 22:42:05 by anolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct	s_flags
{
	int zero;
	int dot;
	int width;
	int precision;
	int justify;
	char type;
}		t_flags;

# define CONVERSIONS	"cspdiuxX%"
# define FLAGS		"-0.*0123456789"
# define DECIMAL	"0123456789"
# define HEXA_LOWER	"0123456789abcdef"
# define HEXA_UPPER	"0123456789ABCDEF"
# define MIN_INT	-2147483648

int		ft_printf(const char *format, ...);
t_flags	ft_verify_star(va_list arguments, t_flags flag);
t_flags	ft_verify_flags(const char *c, va_list arguments, t_flags flag);
t_flags	ft_clean_flags(void);
int		ft_putchar_len(const char *c, int len);
char	*ft_strchr(const char *s, int c);
int		ft_verify_type(char c, va_list arguments, t_flags flag);
int		ft_print_char(char c, t_flags flag);
int		ft_print_int(va_list arguments, t_flags flag);
int		ft_print_string(va_list arguments, t_flags flag);
int		ft_print_hexa(va_list arguments, char *lower_upper,  t_flags flag);
int		ft_print_pointer(va_list arguments, t_flags flag);
int		ft_print_u(va_list arguments, t_flags flag);
int		ft_print_percent(t_flags flag);
size_t	ft_strlen(const char *str);

#endif

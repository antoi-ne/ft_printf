/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:41:29 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/11 12:33:49 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

#include <stdio.h>
#include <string.h>

# define FLAG_LEFT BIT_0
# define FLAG_FILL_0 BIT_1
# define FLAG_WIDTH BIT_2
# define FLAG_PREC BIT_3

# define FLAG_SET "-0.*"
# define NBRS_SET "0123456789"
# define SPEC_SET "cspdiuxX%"

typedef enum	e_spec
{
	CHAR = 0,
	STRING = 1,
	POINTER = 2,
	INTEGER = 3,
	UINTEGER = 4,
	HEX = 5,
	CHEX = 6,
	PERCENT = 7
}				t_spec;

typedef struct	s_format
{
	t_uint8		flag;
	t_int64		width;
	t_int64		precision;
	t_spec		specifier;
}				t_format;

int				ft_printf(const char *format, ...);

t_uint64		ft_parse(const char *s, va_list *va);

t_uint64		ft_parse_flags(t_format *fmt, char *s);
t_uint64		ft_parse_width(t_format *fmt, char *s, va_list *va);
t_uint64		ft_parse_precision(t_format *fmt, char *s, va_list *va);
t_uint64		ft_parse_specifier(t_format *fmt, char *s);

#endif
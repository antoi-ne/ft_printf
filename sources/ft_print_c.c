/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_c.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/02/13 12:45:49 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_print_c(t_format *fmt, va_list *va)
{
	char		arg;
	t_uint64	i;

	i = 0;
	arg = (char)va_arg(*va, int);
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putchar_fd(arg, 1);
		while (i < (fmt->width - 1))
		{
			ft_putchar_fd(' ', 1);
			i++;
		}
		if (!(fmt->flag & FLAG_LEFT))
			ft_putchar_fd(arg, 1);
	}
	else
		ft_putchar_fd(arg, 1);
}
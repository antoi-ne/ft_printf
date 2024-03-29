/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 12:18:43 by ancoulon          #+#    #+#             */
/*   Updated: 2020/03/06 12:10:27 by ancoulon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_d(t_format *fmt, va_list *va, t_int32 *ret)
{
	t_int64		arg;

	arg = (t_int64)va_arg(*va, int);
	if (fmt->flag & FLAG_FILL_0 && fmt->flag & FLAG_WIDTH &&
	(!(fmt->flag & FLAG_PREC) || fmt->precision < 0) && arg < 0)
	{
		fmt->precision = fmt->width - 1;
		fmt->flag |= FLAG_PREC;
		fmt->flag &= ~FLAG_WIDTH;
	}
	if (fmt->flag & FLAG_FILL_0 && fmt->flag & FLAG_WIDTH &&
	fmt->flag & FLAG_PREC && fmt->precision < 0)
		fmt->flag &= ~FLAG_PREC;
	if (fmt->flag & FLAG_WIDTH)
	{
		if (fmt->flag & FLAG_LEFT)
			ft_putnbr_pf(fmt, arg, DEC_BASE, ret);
		ft_printpad((fmt->flag & FLAG_PREC) ? 0 : fmt->flag & FLAG_FILL_0,
		fmt->width - ft_nbrlen(fmt, arg, DEC_BASE), ret);
		if (!(fmt->flag & FLAG_LEFT))
			ft_putnbr_pf(fmt, arg, DEC_BASE, ret);
	}
	else
		ft_putnbr_pf(fmt, arg, DEC_BASE, ret);
}

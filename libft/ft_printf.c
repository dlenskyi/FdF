/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:14:17 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/30 13:14:19 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	run_project(const char *s, t_gen *g)
{
	set_flgs(&g->flg);
	g->mod = arg_reset;
	validate_flgs(s, g);
	if (!s[g->i])
		return ;
	check_params(g);
	parse_str(s, g);
}

void	set_flgs(t_flg *flg)
{
	flg->hash = 0;
	flg->zero = 0;
	flg->plus = 0;
	flg->minus = 0;
	flg->space = 0;
	flg->width = 0;
	flg->prec = -1;
	flg->negative = 0;
}

void	parse_str(const char *s, t_gen *g)
{
	if (s[g->i] == '%')
		manage_percent(g);
	else if ((s[g->i] == 'd' || s[g->i] == 'i') &&
			g->mod != arg_z)
	{
		if (g->flg.prec >= 0)
			g->flg.zero = 0;
		manage_di(g);
	}
	else if ((s[g->i] == 'c' || s[g->i] == 's' || s[g->i] == 'S' ||
			s[g->i] == 'C') && g->mod != arg_l)
		manage_cs(g, s[g->i]);
	else if (ft_strchr(BASE, s[g->i]))
		manage_box(g, s[g->i]);
	else if (s[g->i] == 'u' || s[g->i] == 'U' || s[g->i] == 'D' ||
			((s[g->i] == 'd' || s[g->i] == 'i') && g->mod == arg_z))
		manage_u(g, s[g->i]);
	else if (s[g->i] == 'f' || s[g->i] == 'F')
		manage_f(g, s[g->i]);
	else if (s[g->i] == 'p' || s[g->i] == 'P')
		manage_p(g, s[g->i]);
	else if (s[g->i] == 'n')
		manage_n(g);
	else if (s[g->i])
		print_nonvalid(g, s[g->i]);
}

int		ft_printf(const char *format, ...)
{
	t_gen	g;

	ft_bzero(&g, sizeof(g));
	va_start(g.ap, format);
	while (format[g.i])
	{
		if (format[g.i] == '{')
			check_if_color(format, &g);
		else if (format[g.i] == '%' && !format[g.i + 1])
			return (g.back);
		else if (format[g.i] == '%' && format[g.i + 1] != '%')
		{
			g.i += 1;
			run_project(format, &g);
		}
		else if (format[g.i] == '%' && format[g.i + 1] == '%')
		{
			g.back += write(1, "%", 1);
			g.i += 2;
		}
		else
			g.back += write(1, &format[g.i++], 1);
	}
	va_end(g.ap);
	return (g.back);
}

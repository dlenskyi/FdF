/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:16:48 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/11 18:15:41 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

inline void			manage_di(t_gen *g)
{
	long	buf;
	long	nb;

	if (g->mod == arg_L)
	{
		buf = va_arg(g->ap, int);
		nb = buf;
		g->result = ft_itoa((int)nb);
	}
	else
	{
		buf = va_arg(g->ap, long);
		nb = (long long)buf;
		if (g->mod == arg_hh)
			g->result = ft_itoa((char)nb);
		else if (g->mod == arg_h)
			g->result = ft_itoa((short)nb);
		else if (g->mod == arg_reset)
			g->result = ft_itoa((int)nb);
		else if (g->mod == arg_l || g->mod == arg_t ||
			g->mod == arg_ll || g->mod == arg_j)
			g->result = ft_ltoa(nb);
	}
	print_udi(g);
}

inline void			manage_u(t_gen *g, char var)
{
	long	buf;

	g->flg.space = 0;
	g->flg.plus = 0;
	buf = va_arg(g->ap, long);
	if (buf == LLONG_MIN)
		g->result = ft_strdup("-9223372036854775808");
	else if (g->mod == arg_z || g->mod == arg_t)
		g->result = ft_ltoa_u((size_t)buf);
	else if (g->mod == arg_j)
		g->result = ft_ltoa_u((uintmax_t)buf);
	else if (g->mod == arg_ll || g->mod == arg_l || var == 'D' || var == 'U' ||
		g->mod == arg_L)
		g->result = ft_ltoa_u((unsigned long)buf);
	else if (g->mod == arg_h)
		g->result = ft_ltoa_u((unsigned short)buf);
	else if (g->mod == arg_hh)
		g->result = ft_ltoa_u((unsigned char)buf);
	else if (g->mod == arg_reset)
		g->result = ft_ltoa_u((unsigned int)buf);
	print_udi(g);
}

void				manage_cs(t_gen *g, char var)
{
	int		character;
	char	*str;

	g->flg.minus ? g->flg.zero = 0 : 0;
	if (var == 'c' || var == 'C')
	{
		character = va_arg(g->ap, int);
		print_c(g, character, var);
	}
	else if (var == 's' || var == 'S')
	{
		str = va_arg(g->ap, char *);
		if (!str)
		{
			print_null_cs(g, var);
			return ;
		}
		g->result = ft_strdup(str);
		print_s(g, var);
	}
}

void				manage_box(t_gen *g, char var)
{
	unsigned long	nb;
	long			buf;

	nb = 0;
	buf = va_arg(g->ap, long);
	if (g->mod == arg_ll || g->mod == arg_l ||
		g->mod == arg_z || g->mod == arg_j || g->mod == arg_t || var == 'O')
		nb = (unsigned long)buf;
	else if (g->mod == arg_h)
		nb = (unsigned short)buf;
	else if (g->mod == arg_hh)
		nb = (unsigned char)buf;
	else if (g->mod == arg_reset)
		nb = (unsigned int)buf;
	(var == 'B' || var == 'b') ? g->result = ft_ltoa_base_u(nb, 2) : 0;
	(var == 'o' || var == 'O') ? g->result = ft_ltoa_base_u(nb, 8) : 0;
	(var == 'x' || var == 'X') ? g->result = ft_ltoa_base_u(nb, 16) : 0;
	if (var == 'B' || var == 'O' || var == 'X')
		ft_str_toupper(g->result);
	if (g->flg.minus)
		g->flg.zero = 0;
	print_box(g, var, (long)nb);
}

void				manage_f(t_gen *g, char var)
{
	long double	nb;
	long double	tmp;

	if (g->mod == arg_L)
		nb = va_arg(g->ap, long double);
	else
	{
		tmp = va_arg(g->ap, double);
		nb = tmp;
	}
	if (nb != nb || (nb * 2 == nb && nb != 0))
	{
		g->back += (var == 'f') ?
		write(1, "nan", 3) : write(1, "NAN", 3);
		g->i += 1;
		return ;
	}
	else if (nb * 2 == nb && nb != 0)
	{
		g->back += (var == 'f') ?
		write(1, "inf", 3) : write(1, "INF", 3);
		g->i += 1;
		return ;
	}
	print_float(g, nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_mods.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 10:58:51 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/03 10:58:52 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	validate_mods(const char *s, t_gen *g)
{
	if (s[g->i] == 'h' && s[g->i + 1] != 'h' && g->mod == arg_reset)
		g->mod = arg_h;
	else if (s[g->i] == 'h' && s[g->i + 1] == 'h' && g->mod == arg_reset)
	{
		g->mod = arg_hh;
		g->i += 1;
	}
	else if (s[g->i] == 'l' && s[g->i + 1] != 'l')
		g->mod = arg_l;
	else if (s[g->i] == 'l' && s[g->i + 1] == 'l')
	{
		g->mod = arg_ll;
		g->i += 1;
	}
	else if (s[g->i] == 'L')
		g->mod = arg_L;
	else if (s[g->i] == 'j')
		g->mod = arg_j;
	else if (s[g->i] == 'z')
		g->mod = arg_z;
	else if (s[g->i] == 't')
		g->mod = arg_t;
}

void	validate_width(t_gen *g)
{
	g->flg.width = va_arg(g->ap, int);
	if (g->flg.width < 0)
	{
		g->flg.width = -g->flg.width;
		g->flg.minus = 1;
	}
}

void	validate_precision(const char *s, t_gen *g)
{
	if (g->flg.prec >= 0)
	{
		g->i += 1;
		return ;
	}
	if (s[g->i] == '.' && s[g->i + 1] == '*')
	{
		g->flg.prec = va_arg(g->ap, int);
		g->i += 2;
	}
	if (s[g->i] == '.')
	{
		g->i += 1;
		g->flg.prec = ft_atoi(s + g->i);
		while (s[g->i] >= '0' && s[g->i] <= '9')
			g->i += 1;
	}
}

void	validate_flgs(const char *s, t_gen *g)
{
	while (ft_strchr(FLAGS, s[g->i]))
	{
		s[g->i] >= 'L' && s[g->i] <= 'z' ? validate_mods(s, g) : 0;
		s[g->i] == ' ' ? g->flg.space = 1 : 0;
		s[g->i] == '#' ? g->flg.hash = 1 : 0;
		s[g->i] == '0' ? g->flg.zero = 1 : 0;
		s[g->i] == '-' ? g->flg.minus = 1 : 0;
		s[g->i] == '+' ? g->flg.plus = 1 : 0;
		s[g->i] == '*' ? validate_width(g) : 0;
		if (s[g->i] == '.')
			validate_precision(s, g);
		else if (s[g->i] >= '1' && s[g->i] <= '9' && g->flg.prec <= 0)
		{
			g->flg.width = ft_atoi(s + g->i);
			while (s[g->i] >= '0' && s[g->i] <= '9')
				g->i += 1;
		}
		else if (!s[g->i])
			return ;
		else
			g->i += 1;
	}
}

void	check_params(t_gen *g)
{
	if (g->flg.plus)
		g->flg.space = 0;
	if (g->flg.minus)
		g->flg.zero = 0;
}

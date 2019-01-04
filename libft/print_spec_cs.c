/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_cs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 11:34:37 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/07 11:34:37 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_cs(t_gen *g, char c)
{
	size_t	len;

	len = ft_strlen(g->result);
	if (c == 'c' || c == 'C')
	{
		while (g->flg.width-- > 1)
		{
			if (g->flg.zero)
				g->back += write(1, "0", 1);
			else
				g->back += write(1, " ", 1);
		}
	}
	else if (c == 's' || c == 'S')
	{
		while (g->flg.width-- > (int)len)
		{
			if (g->flg.zero)
				g->back += write(1, "0", 1);
			else
				g->back += write(1, " ", 1);
		}
	}
}

void	print_c(t_gen *g, char c, char var)
{
	if (g->flg.minus)
	{
		g->back += write(1, &c, 1);
		print_width_cs(g, var);
	}
	else
	{
		print_width_cs(g, var);
		g->back += write(1, &c, 1);
	}
	g->i += 1;
}

void	if_null_s(t_gen *g, int len)
{
	if (g->flg.minus)
	{
		g->back += write(1, "(null)", (size_t)len);
		while (g->flg.width-- > len)
			g->back += (g->flg.zero == 1 ?
						write(1, "0", 1) : write(1, " ", 1));
	}
	else
	{
		while (g->flg.width-- > len)
			g->back += (g->flg.zero == 1 ?
						write(1, "0", 1) : write(1, " ", 1));
		g->back += write(1, "(null)", (size_t)len);
	}
}

void	print_null_cs(t_gen *g, char c)
{
	int	len;

	if (g->flg.prec < 0)
		len = 6;
	else
		len = g->flg.prec;
	if (c == 'c' || c == 'C')
	{
		while (g->flg.width-- > 1)
		{
			if (g->flg.zero)
				g->back += write(1, "0", 1);
			else
				g->back += write(1, " ", 1);
		}
		g->back += write(1, "\0", 1);
	}
	else if (c == 's' || c == 'S')
		if_null_s(g, len);
	g->i += 1;
}

void	print_s(t_gen *g, char c)
{
	char	*buf;

	if (g->flg.prec >= 0 && g->flg.prec < (int)ft_strlen(g->result))
	{
		buf = ft_strsub(g->result, 0, (size_t)g->flg.prec);
		free(g->result);
		g->result = buf;
	}
	if (!g->flg.minus)
	{
		print_width_cs(g, c);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	else
	{
		g->back += write(1, g->result, ft_strlen(g->result));
		print_width_cs(g, c);
	}
	ft_strdel(&g->result);
	g->i += 1;
}

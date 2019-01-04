/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_box.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 12:33:15 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/07 12:33:16 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_box(t_gen *g, char var)
{
	int	length;
	int	i;

	length = (int)ft_strlen(g->result);
	i = -1;
	if (g->flg.hash && g->result && g->result[0] != '0')
	{
		g->flg.width -= ((var == 'o' || var == 'O') ? 1 : 0);
		g->flg.width -= ((var == 'x' || var == 'X') ? 2 : 0);
	}
	if (g->flg.prec >= 0)
	{
		while (g->flg.width > g->flg.prec + ++i && g->flg.width > i + length)
			g->back += write(1, " ", 1);
		while (g->flg.width > i++ + length)
			g->back += write(1, "0", 1);
	}
	else
	{
		while (g->flg.width > ++i + length)
			g->back += (g->flg.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	}
}

void	if_precision_box(t_gen *g, char var)
{
	int		len;
	char	*buf;
	char	*tmp;
	int		i;

	len = (int)ft_strlen(g->result);
	if (!g->flg.prec && g->result[0] == '0')
		g->result[0] = '\0';
	if (g->flg.prec > len)
	{
		if ((var == 'o' || var == 'O') && g->flg.hash)
			g->flg.prec--;
		i = g->flg.prec - len;
		buf = ft_strnew(i);
		while (--i >= 0)
			buf[i] = '0';
		tmp = ft_strjoin(buf, g->result);
		ft_strdel(&g->result);
		g->result = tmp;
		ft_strdel(&buf);
	}
}

void	print_hash_box(t_gen *g, char var, long nb)
{
	if (g->flg.hash && g->result && nb)
	{
		if ((var == 'o' || var == 'O') && g->flg.hash)
			g->back += write(1, "0", 1);
		else if (var == 'x')
			g->back += write(1, "0x", 2);
		else if (var == 'X')
			g->back += write(1, "0X", 2);
	}
	else if ((var == 'o' || var == 'O') && g->flg.hash && g->flg.prec >= 0)
		g->back += write(1, "0", 1);
}

void	print_box(t_gen *g, char var, long nb)
{
	if_precision_box(g, var);
	if (g->flg.minus)
	{
		print_hash_box(g, var, nb);
		g->back += write(1, g->result, ft_strlen(g->result));
		print_width_box(g, var);
	}
	else if (g->flg.zero)
	{
		print_hash_box(g, var, nb);
		print_width_box(g, var);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	else
	{
		print_width_box(g, var);
		print_hash_box(g, var, nb);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	g->i += 1;
	ft_strdel(&g->result);
}

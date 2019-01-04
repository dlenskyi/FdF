/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:51:56 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/06 18:51:56 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_udi(t_gen *g)
{
	int		i;
	int		length;
	int		j;

	i = -1;
	j = -1;
	if ((int)ft_strlen(g->result) > g->flg.prec)
		length = (int)ft_strlen(g->result);
	else
		length = g->flg.prec;
	if (g->flg.negative || g->flg.space || g->flg.plus)
		g->flg.width -= 1;
	if (g->flg.prec >= 0)
	{
		while ((int)ft_strlen(g->result) < length - ++j)
			g->back += write(1, "0", 1);
		while (g->flg.width - ++i > length)
			g->back += write(1, " ", 1);
	}
	else
		while (g->flg.width - ++i > length)
			g->back += (g->flg.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
}

void	if_sign_udi(t_gen *g)
{
	char	*buf;

	if (g->result[0] == '-' && g->result)
	{
		buf = ft_strdup(g->result + 1);
		free(g->result);
		g->result = buf;
		g->flg.negative = 1;
		g->flg.space = 0;
		g->flg.plus = 0;
	}
}

void	print_sign_udi(t_gen *g)
{
	if (g->flg.plus)
		g->back += write(1, "+", 1);
	else if (g->flg.space)
		g->back += write(1, " ", 1);
	else if (g->flg.negative)
		g->back += write(1, "-", 1);
}

void	if_precision_udi(t_gen *g)
{
	char	*buf;
	int		length;
	int		i;
	char	*res;

	if_sign_udi(g);
	length = (int)ft_strlen(g->result);
	if (g->flg.prec == 0 && g->result[0] == '0')
		g->result[0] = '\0';
	else if (g->flg.prec > length)
	{
		i = g->flg.prec - length;
		buf = ft_strnew(i);
		while (i-- > 0)
			buf[i] = '0';
		res = ft_strjoin(buf, g->result);
		ft_strdel(&buf);
		ft_strdel(&g->result);
		g->result = res;
	}
}

void	print_udi(t_gen *g)
{
	if_precision_udi(g);
	if (g->flg.zero)
	{
		print_sign_udi(g);
		print_width_udi(g);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	else if (g->flg.minus)
	{
		print_sign_udi(g);
		g->back += write(1, g->result, ft_strlen(g->result));
		print_width_udi(g);
	}
	else
	{
		print_width_udi(g);
		print_sign_udi(g);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	g->i += 1;
	ft_strdel(&g->result);
}

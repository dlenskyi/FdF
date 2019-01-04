/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:51:22 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/07 14:51:22 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_p(t_gen *g)
{
	int	length;

	length = (int)ft_strlen(g->result);
	while (g->flg.width-- > length)
		g->back += write(1, " ", 1);
}

void	if_precision_p(t_gen *g)
{
	int		i;
	int		len;
	char	*tmp;
	char	*buf;

	i = -1;
	len = (int)ft_strlen(g->result);
	if (g->flg.prec > len)
	{
		buf = ft_strnew(g->flg.prec - len);
		while (++i < g->flg.prec - len)
			buf[i] = '0';
		tmp = ft_strjoin(buf, g->result);
		free(g->result);
		g->result = tmp;
		free(buf);
	}
	buf = ft_strjoin("0x", g->result);
	ft_strdel(&g->result);
	g->result = buf;
}

void	print_p(t_gen *g, char var)
{
	if (g->flg.zero && g->flg.prec == -1)
		g->flg.prec = g->flg.width - 2;
	if_precision_p(g);
	if (var == 'P')
		ft_str_toupper(g->result);
	if (g->flg.minus)
	{
		g->back += write(1, g->result, ft_strlen(g->result));
		print_width_p(g);
	}
	else
	{
		print_width_p(g);
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	g->i += 1;
	ft_strdel(&g->result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mods2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 18:14:23 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/06 18:14:24 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	manage_p(t_gen *g, char var)
{
	long			tmp;
	unsigned long	ptr;

	tmp = va_arg(g->ap, long);
	ptr = (unsigned long)tmp;
	if (!g->flg.prec)
		g->result = ft_strdup("\0");
	else
		g->result = ft_ltoa_base_u(ptr, 16);
	print_p(g, var);
}

void	manage_n(t_gen *g)
{
	int *buf;

	buf = va_arg(g->ap, int *);
	*buf = g->back;
	g->i += 1;
}

void	manage_percent(t_gen *g)
{
	if (g->flg.minus)
	{
		g->back += write(1, "%", 1);
		while (g->flg.width-- > 1)
			g->back += write(1, " ", 1);
	}
	else
	{
		while (g->flg.width-- > 1)
		{
			if (g->flg.zero)
				g->back += write(1, "0", 1);
			else
				g->back += write(1, " ", 1);
		}
		g->back += write(1, "%", 1);
	}
	g->i += 1;
}

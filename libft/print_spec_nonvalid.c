/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_nonvalid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 19:23:34 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/07 19:23:37 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_nonvalid(t_gen *g)
{
	while (g->flg.width-- > 1)
	{
		if (g->flg.zero)
			g->back += write(1, "0", 1);
		else
			g->back += write(1, " ", 1);
	}
}

void	print_nonvalid(t_gen *g, char c)
{
	if (g->flg.minus)
	{
		g->back += write(1, &c, 1);
		print_width_nonvalid(g);
	}
	else
	{
		print_width_nonvalid(g);
		g->back += write(1, &c, 1);
	}
	g->i += 1;
}

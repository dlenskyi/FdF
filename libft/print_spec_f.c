/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_spec_f.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:59:41 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/08 14:59:42 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	print_width_f(t_gen *g)
{
	int i;
	int length;

	i = -1;
	length = (int)ft_strlen(g->result) + g->flg.space + g->flg.plus;
	if (g->flg.prec >= 0)
	{
		while (g->flg.width - ++i > length)
		{
			if (g->flg.zero)
				g->back += write(1, "0", 1);
			else
				g->back += write(1, " ", 1);
		}
		i = 0;
		while ((int)ft_strlen(g->result) < length - ++i)
			g->back += write(1, "0", 1);
	}
	else
	{
		while (g->flg.width - ++i > length)
			g->back += (g->flg.zero == 1 ?
			write(1, "0", 1) : write(1, " ", 1));
	}
}

char	*get_precision_f(char *precision, int prec, long double *nb, char *str)
{
	int		j;
	char	*tmp;
	double	k;

	j = -1;
	k = 0.5;
	while (++j < prec)
		k *= 0.1;
	*nb += (!j && prec == 6) || !((int)nb) ? 0 : k;
	if (*nb < 1)
	{
		j = -1;
		while (++j < prec)
		{
			*nb *= 10;
			*str = (int)*nb + '0';
			tmp = precision;
			precision = ft_strjoin(tmp, str);
			free(tmp);
			*nb -= (int)*nb;
		}
	}
	else if (*nb >= 1 && prec == 6)
		precision = ft_strdup("000000");
	return (precision);
}

void	if_precision_f(t_gen *g, long double nb)
{
	char			*buf;
	char			*precision;
	long double		tmp;
	char			*str;

	precision = ft_strnew(1);
	str = ft_strnew(1);
	if (!nb)
		tmp = (double)nb;
	tmp = nb;
	nb = nb < 0 ? -nb : nb;
	nb -= (long)nb;
	precision = get_precision_f(precision, (g->flg.prec >= 0 ?
				g->flg.prec : 6), &nb, str);
	if (nb > 1 && nb < 2)
		tmp += 1;
	buf = (!tmp) ? if_zero_minus(tmp) : ft_ltoa(tmp);
	if (g->flg.prec == 0 && g->flg.hash)
	{
		g->result = ft_strjoin(buf, ".");
		free(buf);
	}
	else
		check_prec_f(g, buf, precision);
}

void	check_prec_f(t_gen *g, char *buf, char *precision)
{
	char	*number;

	if (!g->flg.prec)
	{
		g->result = ft_strdup(buf);
		free(buf);
	}
	else
	{
		number = ft_strjoin(buf, ".");
		g->result = number;
		g->result = ft_strjoin(number, precision);
		ft_strdel(&number);
		ft_strdel(&buf);
		ft_strdel(&precision);
	}
}

void	print_float(t_gen *g, long double nb)
{
	if_precision_f(g, nb);
	if (g->flg.minus)
	{
		if (nb > 0 && (g->flg.plus || g->flg.space))
			g->back += (g->flg.plus == 1 ?
			write(1, "+", 1) : write(1, " ", 1));
		g->back += write(1, g->result, ft_strlen(g->result));
		print_width_f(g);
	}
	else
	{
		print_width_f(g);
		if (nb >= 0 && (g->flg.plus || g->flg.space))
			g->back += (g->flg.plus == 1 ?
			write(1, "+", 1) : write(1, " ", 1));
		g->back += write(1, g->result, ft_strlen(g->result));
	}
	g->i += 1;
	ft_strdel(&g->result);
}

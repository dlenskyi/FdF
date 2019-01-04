/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 13:46:50 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/11 13:46:51 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

void	set_effect(const char *s, t_gen *g)
{
	if (!ft_strncmp(s + g->i, "{SET:BO}", 8))
		g->back += write(1, "\x1B[1m", 4);
	else if (!ft_strncmp(s + g->i, "{SET:FT}", 8))
		g->back += write(1, "\x1B[2m", 4);
	else if (!ft_strncmp(s + g->i, "{SET:IT}", 8))
		g->back += write(1, "\x1B[3m", 4);
	else if (!ft_strncmp(s + g->i, "{SET:UL}", 8))
		g->back += write(1, "\x1B[4m", 4);
	else if (!ft_strncmp(s + g->i, "{SET:BL}", 8))
		g->back += write(1, "\x1B[5m", 4);
	else if (!ft_strncmp(s + g->i, "{SET:RE}", 8))
		g->back += write(1, "\x1B[7m", 4);
	else
		return ;
	g->i += 8;
}

void	set_light_color(const char *s, t_gen *g)
{
	if (!ft_strncmp(s + g->i, "{LT:BLK}", 8))
		g->back += write(1, "\x1B[90m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:RED}", 8))
		g->back += write(1, "\x1B[91m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:GRN}", 8))
		g->back += write(1, "\x1B[92m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:YEL}", 8))
		g->back += write(1, "\x1B[93m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:BLU}", 8))
		g->back += write(1, "\x1B[94m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:MGT}", 8))
		g->back += write(1, "\x1B[95m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:CYN}", 8))
		g->back += write(1, "\x1B[96m", 5);
	else if (!ft_strncmp(s + g->i, "{LT:WHT}", 8))
		g->back += write(1, "\x1B[97m", 5);
	else
		return ;
	g->i += 8;
}

void	set_background_color(const char *s, t_gen *g)
{
	if (!ft_strncmp(s + g->i, "{BGC:BLK}", 9))
		g->back += write(1, "\x1B[40m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:RED}", 9))
		g->back += write(1, "\x1B[41m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:GRN}", 9))
		g->back += write(1, "\x1B[42m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:YEL}", 9))
		g->back += write(1, "\x1B[43m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:BLU}", 9))
		g->back += write(1, "\x1B[44m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:MGT}", 9))
		g->back += write(1, "\x1B[45m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:CYN}", 9))
		g->back += write(1, "\x1B[46m", 5);
	else if (!ft_strncmp(s + g->i, "{BGC:WHT}", 9))
		g->back += write(1, "\x1B[47m", 5);
	else
		return ;
	g->i += 9;
}

void	set_basic_color(const char *s, t_gen *g)
{
	if (!ft_strncmp(s + g->i, "{BLK}", 5))
		g->back += write(1, "\x1B[30m", 5);
	else if (!ft_strncmp(s + g->i, "{RED}", 5))
		g->back += write(1, "\x1B[31m", 5);
	else if (!ft_strncmp(s + g->i, "{GRN}", 5))
		g->back += write(1, "\x1B[32m", 5);
	else if (!ft_strncmp(s + g->i, "{YEL}", 5))
		g->back += write(1, "\x1B[33m", 5);
	else if (!ft_strncmp(s + g->i, "{BLU}", 5))
		g->back += write(1, "\x1B[34m", 5);
	else if (!ft_strncmp(s + g->i, "{MGT}", 5))
		g->back += write(1, "\x1B[35m", 5);
	else if (!ft_strncmp(s + g->i, "{CYN}", 5))
		g->back += write(1, "\x1B[36m", 5);
	else if (!ft_strncmp(s + g->i, "{WHT}", 5))
		g->back += write(1, "\x1B[37m", 5);
	else
		return ;
	g->i += 5;
}

void	check_if_color(const char *s, t_gen *g)
{
	int tmp;

	tmp = g->i;
	if (!ft_strncmp(s + g->i, "{OFF}", 5))
	{
		g->back += write(1, "\x1B[0m", 4);
		g->i += 5;
		return ;
	}
	else if (!ft_strncmp(s + g->i, "{SET:", 5))
		set_effect(s, g);
	else if (!ft_strncmp(s + g->i, "{BGC:", 5))
		set_background_color(s, g);
	else if (!ft_strncmp(s + g->i, "{LT:", 4))
		set_light_color(s, g);
	else
		set_basic_color(s, g);
	if (tmp == g->i)
		g->back += write(1, &s[g->i++], 1);
}

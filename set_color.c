/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 18:17:32 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 18:17:34 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_pos	curr_pos(int x, int y, t_fdf_size *size)
{
	t_fdf_pos	pos;
	int			current;

	current = y * size->length_x + x;
	pos.x = x;
	pos.y = y;
	pos.z = size->arrof_struct[current];
	if (size->arrof_color[current] < 0)
		pos.color = set_default_color(size, pos.z);
	else
		pos.color = size->arrof_color[current];
	return (pos);
}

double		percentage(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int			set_default_color(t_fdf_size *size, int z)
{
	double percent;

	percent = percentage(size->min_z, size->max_z, z);
	if (percent < 0.2)
		return (0x0ac266);
	else if (percent < 0.4)
		return (0x0ac281);
	else if (percent < 0.6)
		return (0x07f0d5);
	else if (percent < 0.8)
		return (0xaff0e8);
	else
		return (0xfafafa);
}

int			manage_gradient(int start, int end, double percent)
{
	return ((int)((1 - percent) * start + percent * end));
}

int			set_color(t_fdf_pos current, t_fdf_pos end,
			t_fdf_pos start, t_fdf_pos delta)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current.color == end.color)
		return (current.color);
	percent = (delta.x > delta.y) ? percentage(start.x, end.x, current.x) :
			percentage(start.y, end.y, current.y);
	red = manage_gradient((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percent);
	green = manage_gradient((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percent);
	blue = manage_gradient(start.color & 0xFF, end.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

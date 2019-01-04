/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:11:19 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 16:11:20 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		convert_to_iso(int *x, int *y, int z)
{
	int prev_y;
	int prev_x;

	prev_x = *x;
	prev_y = *y;
	*x = (prev_x - prev_y) * cos(0.523599);
	*y = -z + (prev_y + prev_x) * sin(0.523599);
}

static void		rotate_y(int *x, int *z, double beta)
{
	int prev_x;

	prev_x = *x;
	*x = prev_x * cos(beta) + *z * sin(beta);
	*z = -prev_x * sin(beta) + *z * cos(beta);
}

static void		rotate_z(int *x, int *y, double gamma)
{
	int prev_x;
	int prev_y;

	prev_x = *x;
	prev_y = *y;
	*x = prev_x * cos(gamma) - prev_y * sin(gamma);
	*y = prev_x * sin(gamma) + prev_y * cos(gamma);
}

static void		rotate_x(int *z, int *y, double alpha)
{
	int prev_y;

	prev_y = *y;
	*y = prev_y * cos(alpha) + *z * sin(alpha);
	*z = -prev_y * sin(alpha) + *z * cos(alpha);
}

t_fdf_pos		projection(t_fdf_pos pos, t_fdf_gen *g)
{
	pos.x *= g->rotation->zoom;
	pos.y *= g->rotation->zoom;
	pos.z *= g->rotation->zoom / g->rotation->division;
	pos.x -= (g->size->length_x * g->rotation->zoom) / 2;
	pos.y -= (g->size->length_y * g->rotation->zoom) / 2;
	rotate_x(&pos.z, &pos.y, g->rotation->alpha);
	rotate_y(&pos.x, &pos.z, g->rotation->beta);
	rotate_z(&pos.x, &pos.y, g->rotation->gamma);
	if (g->iso)
		convert_to_iso(&pos.x, &pos.y, pos.z);
	pos.x += (WIDTH - MENU_SIZE) / 2 + g->rotation->offset_x + MENU_SIZE;
	pos.y += (HEIGHT + g->size->length_y * g->rotation->zoom) / 2
			+ g->rotation->offset_y;
	return (pos);
}

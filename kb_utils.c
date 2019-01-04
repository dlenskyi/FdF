/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:28:35 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 19:28:36 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_map(int keycode, t_fdf_gen *g)
{
	if (keycode == KB_PLUS || keycode == NUM_PLUS ||
		keycode == SCROLL_UP)
		g->rotation->zoom++;
	else if (keycode == KB_MINUS ||
		keycode == NUM_MINUS || keycode == SCROLL_DOWN)
		g->rotation->zoom--;
	if (g->rotation->zoom < 1)
		g->rotation->zoom = 1;
	magic(g->size, g);
}

void	rotate_map(int keycode, t_fdf_gen *g)
{
	if (keycode == KB_1 || keycode == NUM_1)
		g->rotation->alpha += 0.05;
	else if (keycode == KB_2 || keycode == NUM_2)
		g->rotation->alpha -= 0.05;
	else if (keycode == KB_3 || keycode == NUM_3)
		g->rotation->beta += 0.05;
	else if (keycode == KB_4 || keycode == NUM_4)
		g->rotation->beta -= 0.05;
	else if (keycode == KB_5 || keycode == NUM_5)
		g->rotation->gamma += 0.05;
	else if (keycode == KB_6 || keycode == NUM_6)
		g->rotation->gamma -= 0.05;
	magic(g->size, g);
}

void	change_projection(int keycode, t_fdf_gen *g)
{
	g->rotation->alpha = 0;
	g->rotation->beta = 0;
	g->rotation->gamma = 0;
	if (keycode == KB_I)
	{
		g->iso = 1;
		g->parallel = 0;
	}
	else if (keycode == KB_P)
	{
		g->parallel = 1;
		g->iso = 0;
	}
	magic(g->size, g);
}

void	smooth_map(int keycode, t_fdf_gen *g)
{
	if (keycode == KB_Z)
		g->rotation->division -= 0.1;
	else if (keycode == KB_X)
		g->rotation->division += 0.1;
	if (g->rotation->division < 0.1)
		g->rotation->division = 0.1;
	else if (g->rotation->division > 20)
		g->rotation->division = 20;
	magic(g->size, g);
}

void	move_map(int keycode, t_fdf_gen *g)
{
	if (keycode == KB_W || keycode == ARR_UP)
		g->rotation->offset_y -= 10;
	else if (keycode == KB_S || keycode == ARR_DOWN)
		g->rotation->offset_y += 10;
	else if (keycode == KB_A || keycode == ARR_LEFT)
		g->rotation->offset_x -= 10;
	else
		g->rotation->offset_x += 10;
	magic(g->size, g);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_board_control.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 19:01:56 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 19:01:57 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int keycode, void *param)
{
	t_fdf_gen	*g;

	g = (t_fdf_gen *)param;
	if (keycode == ESC)
		exit(0);
	if (keycode == NUM_1 || keycode == KB_1
	|| keycode == NUM_2 || keycode == KB_2
	|| keycode == NUM_3 || keycode == KB_3
	|| keycode == NUM_4 || keycode == KB_4
	|| keycode == NUM_5 || keycode == KB_5
	|| keycode == NUM_6 || keycode == KB_6)
		rotate_map(keycode, g);
	else if (keycode == KB_PLUS || keycode == NUM_PLUS
		|| keycode == KB_MINUS || keycode == NUM_MINUS)
		zoom_map(keycode, g);
	else if (keycode == KB_A || keycode == KB_D ||
			keycode == KB_W || keycode == KB_S ||
			keycode == ARR_DOWN || keycode == ARR_UP ||
			keycode == ARR_LEFT || keycode == ARR_RIGHT)
		move_map(keycode, g);
	else if (keycode == KB_Z || keycode == KB_X)
		smooth_map(keycode, g);
	else if (keycode == KB_I || keycode == KB_P)
		change_projection(keycode, g);
	return (0);
}

int		press_mouse(int button, int x, int y, void *param)
{
	t_fdf_gen	*g;

	(void)x;
	(void)y;
	g = (t_fdf_gen *)param;
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		zoom_map(button, g);
	else if (button == LEFT_BUTTON)
		g->click->latm = 1;
	return (0);
}

int		release_mouse(int button, int x, int y, void *param)
{
	t_fdf_gen	*g;

	(void)x;
	(void)y;
	(void)button;
	g = (t_fdf_gen *)param;
	g->click->latm = 0;
	return (0);
}

int		move_mouse(int x, int y, void *param)
{
	t_fdf_gen	*g;

	g = (t_fdf_gen *)param;
	g->click->prev_x = g->click->x;
	g->click->prev_y = g->click->y;
	g->click->x = x;
	g->click->y = y;
	if (g->click->latm)
	{
		g->rotation->beta += (x - g->click->prev_x) * 0.002;
		g->rotation->alpha += (y - g->click->prev_y) * 0.002;
		magic(g->size, g);
	}
	return (0);
}

void	init_buttons(t_fdf_gen *g)
{
	mlx_hook(g->win_ptr, 2, 0, key_press, g);
	mlx_hook(g->win_ptr, 17, 0, finish, g);
	mlx_hook(g->win_ptr, 4, 0, press_mouse, g);
	mlx_hook(g->win_ptr, 5, 0, release_mouse, g);
	mlx_hook(g->win_ptr, 6, 0, move_mouse, g);
}

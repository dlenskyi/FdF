/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 16:06:41 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 16:06:42 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		magic_menu(t_fdf_gen *g)
{
	int y;

	y = 0;
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 30, COLOR_STR, "Exit: ESC");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "ISO: I Key");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "PARALLEL: P Key");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Move: W, A, S, D, arrows");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Rotate: Left Click->Rotate");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Zoom: +, -, scroll");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Make it smooth: Z, X");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Rotate by X: 1, 2");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Rotate by Y: 3, 4");
	mlx_string_put(g->mlx_ptr, g->win_ptr, WIDTH - 280,
				y += 40, COLOR_STR, "Rotate by Z: 5, 6");
}

static void		magic_bg(t_fdf_gen *g)
{
	int i;
	int *image;

	i = 0;
	ft_bzero(g->data_addr, (size_t)WIDTH * HEIGHT * (g->bpp / 8));
	image = (int *)g->data_addr;
	while (i < WIDTH * HEIGHT)
	{
		if (i % WIDTH > (WIDTH - MENU_SIZE))
			image[i] = COLOR_MENU_BG;
		else
			image[i] = COLOR_BACKGR;
		i++;
	}
}

static void		magic_pixel(int x, int y, int color, t_fdf_gen *g)
{
	int i;

	if (y > 0 && y < HEIGHT && x > 0 && x < (WIDTH - MENU_SIZE) && x < WIDTH)
	{
		i = (x * g->bpp / 8) + (y * g->line_size);
		g->data_addr[i] = color;
		g->data_addr[++i] = color >> 8;
		g->data_addr[++i] = color >> 16;
	}
}

static void		magic_line(t_fdf_pos f, t_fdf_pos s, t_fdf_gen *g)
{
	int			deviation[2];
	t_fdf_pos	delta;
	t_fdf_pos	miss_half;
	t_fdf_pos	current;

	delta.x = FT_ABS(s.x - f.x);
	delta.y = FT_ABS(s.y - f.y);
	miss_half.x = s.x > f.x ? 1 : -1;
	miss_half.y = s.y > f.y ? 1 : -1;
	current = f;
	deviation[0] = delta.x - delta.y;
	while (current.x != s.x || current.y != s.y)
	{
		magic_pixel(current.x, current.y, set_color(current, f, s, delta), g);
		if ((deviation[1] = deviation[0] * 2) > -delta.y)
		{
			deviation[0] -= delta.y;
			current.x += miss_half.x;
		}
		if (deviation[1] < delta.x)
		{
			deviation[0] += delta.x;
			current.y += miss_half.y;
		}
	}
}

void			magic(t_fdf_size *size, t_fdf_gen *g)
{
	int x;
	int y;

	y = 0;
	magic_bg(g);
	while (y < size->length_y)
	{
		x = 0;
		while (x < size->length_x)
		{
			if (x != g->size->length_x - 1)
				magic_line(projection(curr_pos(x, y, size), g),
						projection(curr_pos(x + 1, y, size), g), g);
			if (y != size->length_y - 1)
				magic_line(projection(curr_pos(x, y, size), g),
						projection(curr_pos(x, y + 1, size), g), g);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(g->mlx_ptr, g->win_ptr, g->img_ptr, 0, 0);
	magic_menu(g);
}

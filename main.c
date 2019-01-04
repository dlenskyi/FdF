/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:33:10 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/12 16:39:24 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf_size		*init_size(void)
{
	t_fdf_size	*size;

	ft_bzero(&size, sizeof(size));
	if (!(size = (t_fdf_size *)ft_memalloc(sizeof(t_fdf_size))))
		quit("Initialization error\n");
	size->min_z = 0;
	size->max_z = 0;
	size->length_x = 0;
	size->length_y = 0;
	size->arrof_color = NULL;
	size->arrof_struct = NULL;
	return (size);
}

t_fdf_gen		*init_gen(t_fdf_size *size)
{
	t_fdf_gen	*g;

	ft_bzero(&g, sizeof(g));
	if (!(g = (t_fdf_gen *)ft_memalloc(sizeof(t_fdf_gen))))
		quit("Initialization error\n");
	if (!(g->mlx_ptr = mlx_init()))
		quit("Initialization error\n");
	if (!(g->win_ptr = mlx_new_window(g->mlx_ptr, WIDTH, HEIGHT, "FdF")))
		quit("Initialization error\n");
	if (!(g->img_ptr = mlx_new_image(g->mlx_ptr, WIDTH, HEIGHT)))
		quit("Initialization error\n");
	g->data_addr = mlx_get_data_addr(g->img_ptr,
				&(g->bpp), &(g->line_size), &(g->end));
	g->size = size;
	g->iso = 0;
	g->parallel = 1;
	if (!(g->click = (t_fdf_click *)ft_memalloc(sizeof(t_fdf_click))))
		quit("Initialization error\n");
	return (g);
}

t_fdf_rotation	*init_rotation(t_fdf_gen *g)
{
	t_fdf_rotation *rotation;

	ft_bzero(&rotation, sizeof(rotation));
	if (!(rotation = (t_fdf_rotation *)ft_memalloc(sizeof(t_fdf_rotation))))
		quit("Initialization error\n");
	rotation->zoom = FT_MIN((WIDTH - MENU_SIZE) / g->size->length_x / 2,
							HEIGHT / g->size->length_y / 2);
	if (!rotation->zoom)
		rotation->zoom = 1;
	rotation->alpha = 0;
	rotation->beta = 0;
	rotation->gamma = 0;
	rotation->offset_x = 0;
	rotation->offset_y = 0;
	rotation->division = 10.0;
	return (rotation);
}

void			quit(char *s)
{
	if (!ft_strcmp(s, "Invalid map\n"))
		ft_printf("{RED}{SET:BO}Invalid map{OFF}\n");
	else if (!ft_strcmp(s, "usage: ./fdf [map]\n"))
		ft_printf("{RED}{SET:BO}usage: ./fdf [map]{OFF}\n");
	else if (!ft_strcmp(s, "Invalid file\n"))
		ft_printf("{RED}{SET:BO}Invalid file{OFF}\n");
	else if (!ft_strcmp(s, "Initialization error\n"))
		ft_printf("{RED}{SET:BO}Initialization error{OFF}\n");
	exit(1);
}

int				main(int ac, char **av)
{
	t_fdf_gen		*g;
	t_fdf_size		*size;
	t_fdf_val_pos	*val_pos;
	int				fd;

	val_pos = NULL;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			quit("Invalid file\n");
		size = init_size();
		if (parse_map(fd, size, &val_pos) == -1)
			quit("Invalid map\n");
		g = init_gen(size);
		g->rotation = init_rotation(g);
		init_arr_of_struct(&val_pos, size);
		magic(g->size, g);
		init_buttons(g);
		mlx_loop(g->mlx_ptr);
	}
	else
		quit("usage: ./fdf [map]\n");
	return (0);
}

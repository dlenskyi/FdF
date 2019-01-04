/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arr_of_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:44:56 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 15:44:57 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_arr_of_struct(t_fdf_val_pos **val_pos, t_fdf_size *size)
{
	ssize_t			i;
	t_fdf_val_pos	*pos;
	size_t			size_arr;

	size_arr = size->length_y * size->length_x * sizeof(int);
	if (!(size->arrof_color = (int *)ft_memalloc(size_arr)))
		quit("Initialization error\n");
	if (!(size->arrof_struct = (int *)ft_memalloc(size_arr)))
		quit("Initialization error\n");
	i = size->length_x * size->length_y - 1;
	while (i >= 0 && (pos = remove_elem(val_pos)))
	{
		size->arrof_color[i] = pos->color;
		size->arrof_struct[i] = pos->z;
		if (pos->z < size->min_z)
			size->min_z = pos->z;
		if (pos->z > size->max_z)
			size->max_z = pos->z;
		i--;
		free(pos);
	}
}

int		finish(void *param)
{
	(void)param;
	exit(0);
}

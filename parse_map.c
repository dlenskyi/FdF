/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:41:48 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/12 17:41:50 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void					add_elem(t_fdf_val_pos **val_pos, t_fdf_val_pos *elem)
{
	if (val_pos)
	{
		if (elem)
			elem->next = *val_pos;
		*val_pos = elem;
	}
}

t_fdf_val_pos			*remove_elem(t_fdf_val_pos **val_pos)
{
	t_fdf_val_pos	*top;

	top = NULL;
	if (val_pos && *val_pos)
	{
		top = *val_pos;
		*val_pos = (*val_pos)->next;
	}
	return (top);
}

static	t_fdf_val_pos	*new_elem(char *str)
{
	t_fdf_val_pos	*elem;
	char			**value;

	if (!(elem = (t_fdf_val_pos *)ft_memalloc(sizeof(t_fdf_val_pos))))
		quit("Invalid map\n");
	if (!(value = ft_strsplit(str, ',')))
		quit("Invalid map\n");
	if (!ft_isdigit_valid(value[0], 10))
		quit("Invalid map\n");
	if (value[1] && !ft_isdigit_valid(value[1], 16))
		quit("Invalid map\n");
	elem->z = ft_atoi(value[0]);
	if (value[1])
		elem->color = ft_atoi_base(value[1], 16);
	else
		elem->color = -1;
	elem->next = NULL;
	ft_del_strsplit(value);
	return (elem);
}

static void				validate_line(char **str, t_fdf_size *size,
						t_fdf_val_pos **val_pos)
{
	int line_length;

	line_length = 0;
	while (*str)
	{
		add_elem(val_pos, new_elem(*(str++)));
		line_length++;
	}
	if (!size->length_y)
		size->length_x = line_length;
	else if (size->length_x != line_length)
		quit("Invalid map\n");
}

int						parse_map(int fd, t_fdf_size *size,
						t_fdf_val_pos **val_pos)
{
	char	*line;
	char	**str;
	int		ret;

	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (!(str = ft_strsplit(line, ' ')))
			quit("Invalid map\n");
		validate_line(str, size, val_pos);
		ft_del_strsplit(str);
		ft_strdel(&line);
		size->length_y++;
	}
	if (!(*val_pos))
		quit("Invalid map\n");
	return (ret);
}

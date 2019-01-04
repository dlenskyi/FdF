/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:51:27 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/20 13:06:29 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	**ft_fillmatrix(size_t x, size_t y, unsigned char c)
{
	unsigned char	**arr;
	size_t			i;
	size_t			j;

	j = -1;
	i = -1;
	arr = (unsigned char **)ft_memalloc(sizeof(unsigned char *) * (y + 1));
	while (++i < y)
		arr[i] = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (x + 1));
	i = -1;
	while (++i < y)
	{
		j = -1;
		while (++j < x)
			arr[i][j] = c;
	}
	arr[i] = NULL;
	return ((void **)arr);
}

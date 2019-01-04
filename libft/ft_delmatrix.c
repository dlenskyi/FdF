/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delmatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdovhopo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:34:24 by mdovhopo          #+#    #+#             */
/*   Updated: 2018/11/20 15:34:26 by mdovhopo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

/*
** simply delete the matrix of size
*/

void	ft_delmatrix(char **tab, int size)
{
	int		i;

	i = 0;
	while (i < size)
		free(tab[i++]);
	free(tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 12:33:25 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/19 12:33:35 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_sqrt(int n)
{
	int i;
	int buf;

	i = 1;
	buf = 1;
	if (n < 0)
		return (0);
	if (n == 1)
		return (1);
	while (buf < n)
	{
		buf = i * i;
		i++;
	}
	i--;
	if (buf != n)
		return (0);
	return (i);
}

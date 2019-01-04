/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_valid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:07:07 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 13:07:09 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isdigit_valid(char *s, int base)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (s[i] == ' ')
		i++;
	if (base != 10 && !ft_isprefix(&s[i], base))
		return (0);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 10 && (s[i] == '-' || s[i] == '+'))
		i++;
	else if (base == 8)
		i++;
	while (ft_isdigit_base(s[i], base) >= 0)
	{
		i++;
		size++;
	}
	if (!s[i] && size)
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprefix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:07:16 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 13:07:17 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isprefix(const char *s, int base)
{
	int	i;

	i = 0;
	while (s[i] == ' ')
		i++;
	if (base == 16 || base == 2 || base == 8)
	{
		if (s[i] != '0')
			return (0);
		i++;
		if (base == 16 && (s[i] == 'x' || s[i] == 'X'))
			return (1);
		else if (base == 2 && (s[i] == 'b' || s[i] == 'B'))
			return (1);
		else if (base == 8)
			return (1);
	}
	return (0);
}

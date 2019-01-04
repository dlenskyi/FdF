/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 23:00:09 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 23:00:10 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_checker(char *s1, int i, int sign, size_t n)
{
	while (s1[i] == 32 || (s1[i] > 8 && s1[i] < 14))
		i++;
	if (s1[i] == 43)
		i++;
	if (s1[i] == 45)
	{
		if (s1[i - 1] == 43)
			return (0);
		sign = 1;
		i++;
	}
	while (s1[i] >= '0' && s1[i] <= '9')
	{
		n = n * 10 + s1[i] - '0';
		if (n >= 9223372036854775807 && sign == 0)
			return (-1);
		else if (n > 9223372036854775807 && sign == 1)
			return (0);
		i++;
	}
	if (sign)
		return (-n);
	return (n);
}

int				ft_atoi(const char *str)
{
	char		*s;
	size_t		i;
	int			sign;
	int			n;

	n = 0;
	sign = 0;
	i = 0;
	s = (char *)str;
	return (ft_checker(s, i, sign, n));
}

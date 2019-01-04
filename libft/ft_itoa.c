/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 17:17:43 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/29 17:17:44 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_discharge(int n)
{
	int i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char		*ret_str(int n, int sign)
{
	char	*str;
	int		b;

	b = ft_discharge(n);
	if (sign)
		str = (char *)malloc(sizeof(char) * (b + 2));
	else
		str = (char *)malloc(sizeof(char) * (b + 1));
	if (!str)
		return (NULL);
	if (sign)
		str[b + 1] = '\0';
	else
		str[b] = '\0';
	if (sign)
		str[0] = '-';
	else
		b = b - 1;
	while (n > 0)
	{
		str[b] = n % 10 + 48;
		n = n / 10;
		b--;
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int		sign;
	char	*str;

	str = NULL;
	sign = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	str = ret_str(n, sign);
	return (str);
}

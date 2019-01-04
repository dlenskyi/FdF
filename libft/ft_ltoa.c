/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:47:03 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/06 15:47:04 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		llength(long n)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = n;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	if (n < 0)
		len++;
	return (len);
}

char			*ft_ltoa(long n)
{
	long	tmp;
	int		len;
	char	*str;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	len = llength(tmp);
	if (tmp < 0)
		tmp = -tmp;
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (tmp)
	{
		str[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

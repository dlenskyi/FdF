/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 20:03:53 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/06 20:03:54 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		llength(unsigned long n)
{
	int				len;
	unsigned long	tmp;

	len = 0;
	tmp = n;
	while (tmp)
	{
		len++;
		tmp /= 10;
	}
	return (len);
}

char			*ft_ltoa_u(unsigned long n)
{
	unsigned long	tmp;
	int				len;
	char			*str;

	tmp = n;
	if (n == 0)
		return (ft_strdup("0"));
	len = llength(tmp);
	if (!(str = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	str[len] = '\0';
	while (tmp)
	{
		str[--len] = tmp % 10 + '0';
		tmp /= 10;
	}
	return (str);
}

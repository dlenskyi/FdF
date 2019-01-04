/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:24:49 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/15 16:24:51 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_discharge(long nb, int base)
{
	int		len;
	long	tmp;

	len = 0;
	tmp = nb;
	while (tmp)
	{
		tmp /= base;
		len++;
	}
	tmp = nb;
	if (nb < 0 && base == 10)
		len++;
	return (len);
}

char			*ft_itoa_base(int value, int base)
{
	long	nb;
	char	*str;
	char	*base_str;
	int		len;

	nb = value;
	base_str = "0123456789ABCDEF";
	if (nb == 0)
		return ("0");
	if (nb == -2147483648)
		return (ft_strdup("-2147483648"));
	len = ft_discharge(nb, base);
	if (nb < 0)
		nb = -nb;
	str = (char *)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	while (nb)
	{
		str[--len] = base_str[nb % base];
		nb /= base;
	}
	nb = value;
	if (nb < 0 && base == 10)
		str[0] = '-';
	return (str);
}

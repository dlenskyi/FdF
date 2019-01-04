/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 11:13:22 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/11 11:13:41 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

char	*if_zero_minus(double n)
{
	uint64_t	*data;

	data = (uint64_t *)&n;
	if (*data >> 63 & 1)
		return (ft_strdup("-0"));
	if (!n)
		return (ft_strdup("0"));
	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
	return (NULL);
}

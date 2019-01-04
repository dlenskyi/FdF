/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 13:06:59 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/12/29 13:07:00 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isdigit_base(char c, int base)
{
	char	*base_str;
	int		i;

	i = -1;
	base_str = "0123456789ABCDEF";
	while (++i < base)
	{
		if (base_str[i] == ft_toupper(c))
			return (i);
	}
	return (-1);
}

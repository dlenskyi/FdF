/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 22:53:26 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 22:53:28 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	size_t	i;
	char	*str;

	if (!s)
		return ;
	i = 0;
	str = (char *)s;
	while (str[i])
		ft_putchar(str[i++]);
}

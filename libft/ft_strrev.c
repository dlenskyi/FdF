/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:50:41 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/18 15:16:39 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_strrev(const char *str)
{
	int		i;
	int		j;
	char	c;
	char	*s;

	s = (char *)str;
	j = 0;
	i = ft_strlen(s) - 1;
	while (j < i)
	{
		c = s[j];
		s[j] = s[i];
		s[i] = c;
		i--;
		j++;
	}
}

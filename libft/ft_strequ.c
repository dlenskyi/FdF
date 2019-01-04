/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:43:30 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 20:43:31 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	size_t	t;

	if (!s1 || !s2)
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (ft_strcmp(str1, str2) != 0)
	{
		t = 0;
		return (t);
	}
	else
	{
		t = 1;
		return (t);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 20:57:16 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 20:57:17 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	t;
	char	*str1;
	char	*str2;

	if (!s1 || !s2)
		return (0);
	if (s1[0] == '\0' && s2[0] == '\0')
		return (1);
	str1 = (char *)s1;
	str2 = (char *)s2;
	t = 0;
	if (ft_strncmp(str1, str2, n) != 0)
		return (t);
	else
	{
		t = 1;
		return (t);
	}
	return (t);
}

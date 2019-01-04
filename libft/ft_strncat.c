/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:17:18 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 19:17:20 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;
	char			*str2;

	i = 0;
	j = 0;
	str2 = (char *)s2;
	while (s1[i] != '\0')
		i++;
	while (str2[j] != '\0' && j < n)
	{
		s1[i] = str2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

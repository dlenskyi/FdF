/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:17:07 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 19:17:09 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int				i;
	int				j;
	const char		*str2;

	i = 0;
	j = 0;
	str2 = s2;
	while (s1[i] != '\0')
		i++;
	while (str2[j] != '\0')
	{
		s1[i] = str2[j];
		i++;
		j++;
	}
	s1[i] = '\0';
	return (s1);
}

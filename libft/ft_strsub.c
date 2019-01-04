/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 21:06:11 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 21:06:12 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sstr;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)s;
	sstr = (char*)malloc(sizeof(char) * (len + 1));
	if (!sstr)
		return (NULL);
	while (str[i] && i < len)
	{
		sstr[i] = str[start];
		start++;
		i++;
	}
	sstr[i] = '\0';
	return (sstr);
}

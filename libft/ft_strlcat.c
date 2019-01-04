/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 19:17:27 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 19:17:29 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	char		*s;
	size_t		size;
	size_t		j;

	s = (char *)src;
	i = ft_strlen(dst);
	j = i + ft_strlen(s);
	size = dstsize - i - 1;
	if (i >= dstsize)
		return (ft_strlen(s) + dstsize);
	else
	{
		ft_strncat(dst, s, size);
		return (j);
	}
	return (j);
}

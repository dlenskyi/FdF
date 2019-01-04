/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 22:08:10 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 22:08:11 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	const char			*h;
	const char			*n;
	unsigned int		i;
	size_t				j;

	i = -1;
	h = hay;
	n = need;
	if (!ft_strlen(need))
		return ((char *)hay);
	if (ft_strlen(hay) < ft_strlen(need) || !hay)
		return (NULL);
	while (hay && ++i < len)
	{
		n = need;
		h = hay;
		j = i;
		while (*h++ == *n++ && j++ < len)
		{
			if (!*n)
				return ((char*)hay);
		}
		hay++;
	}
	return (NULL);
}

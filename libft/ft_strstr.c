/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 21:28:56 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 21:28:58 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	const char	*h;
	const char	*n;

	h = haystack;
	n = needle;
	if (!(ft_strlen(n)))
		return ((char *)h);
	if ((!(ft_strlen(h)) && !(ft_strlen(n))) || !ft_strlen(h))
		return (0);
	while (*haystack)
	{
		h = haystack;
		n = needle;
		while (*h == *n && *h != '\0')
		{
			h++;
			n++;
		}
		if (*n == '\0')
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}

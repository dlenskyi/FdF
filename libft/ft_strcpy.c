/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:50:26 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 18:50:28 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	char	*s;
	int		i;

	if (!src)
		return (NULL);
	i = -1;
	s = (char *)src;
	while (s[++i] != '\0')
		dst[i] = s[i];
	dst[i] = '\0';
	return (dst);
}

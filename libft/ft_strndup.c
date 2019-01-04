/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:05:01 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/01 16:05:02 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strndup(const char *s1, size_t len)
{
	size_t	i;
	char	*b1;
	char	*str;

	b1 = (char *)s1;
	i = 0;
	while (i < len)
		i++;
	str = ((char*)malloc(sizeof(char) * (i + 1)));
	if (!str)
		return (0);
	return (ft_strncpy(str, b1, len));
}

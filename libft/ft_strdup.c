/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 18:50:12 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/26 18:50:18 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*b1;
	char	*str;

	i = 0;
	b1 = (char *)s1;
	while (b1[i] != '\0')
		i++;
	str = ((char*)malloc(sizeof(*str) * (i + 1)));
	if (str == 0)
		return (0);
	return (ft_strcpy(str, b1));
}

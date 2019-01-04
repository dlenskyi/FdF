/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 19:10:02 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 19:10:03 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmap(char const *s, char (*f) (char))
{
	size_t	i;
	char	*str;
	size_t	j;

	j = 0;
	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!str)
		return (NULL);
	while (s[j] != '\0')
	{
		str[i] = f(*(char *)&s[j]);
		j++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

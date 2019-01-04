/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:30:26 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 23:30:27 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	char	*str;
	char	*res;
	size_t	len;
	size_t	size;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s) - 1;
	if (len == 0)
		return (NULL);
	str = (char *)s;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while ((str[len] == ' ' || str[len] == '\n' || str[len] == '\t') && len > i)
		len--;
	size = len - i + 1;
	res = ft_strsub(str, i, size);
	return (res);
}

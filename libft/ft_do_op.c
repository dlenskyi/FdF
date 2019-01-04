/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:52:56 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/30 19:52:58 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int			ft_do_op(const char *s1, const char *s2, char c)
{
	char	*str1;
	char	*str2;

	if (!s1 || !s2)
		return (0);
	str1 = (char *)s1;
	str2 = (char *)s2;
	if (c == 37 || c == 42 || c == 43 || c == 45 || c == 47)
	{
		if (c == 37)
			return (ft_atoi(str1) % ft_atoi(str2));
		if (c == 42)
			return (ft_atoi(str1) * ft_atoi(str2));
		if (c == 43)
			return (ft_atoi(str1) + ft_atoi(str2));
		if (c == 45)
			return (ft_atoi(str1) - ft_atoi(str2));
		if (c == 47)
			return (ft_atoi(str1) / ft_atoi(str2));
	}
	return (0);
}

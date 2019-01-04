/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:07:01 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 23:07:01 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl(char const *s)
{
	size_t	i;
	char	*s1;

	if (!s)
		return ;
	i = 0;
	s1 = (char *)s;
	while (s1[i])
		ft_putchar(s1[i++]);
	ft_putchar('\n');
}

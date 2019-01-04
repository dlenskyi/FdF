/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:10:39 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 23:10:40 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	size_t	i;
	char	*s1;

	if (!s)
		return ;
	i = 0;
	s1 = (char *)s;
	while (s1[i])
		ft_putchar_fd(s1[i++], fd);
	ft_putchar_fd('\n', fd);
}

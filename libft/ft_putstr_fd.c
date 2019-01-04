/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 23:10:23 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/28 23:10:24 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	size_t	i;
	char	*str;

	if (!s)
		return ;
	i = 0;
	str = (char *)s;
	while (str[i])
		ft_putchar_fd(str[i++], fd);
}

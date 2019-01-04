/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 19:50:55 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/30 19:50:56 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*p;

	if (!size)
	{
		free(ptr);
		return (NULL);
	}
	if (!ptr)
		return (malloc(size));
	p = malloc(size);
	if (!p)
		return (NULL);
	if (p)
	{
		ft_memcpy(p, ptr, size);
		free(ptr);
	}
	return (p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:20:20 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/10/30 16:20:21 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*p;

	if (!(p = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		p->content_size = content_size;
		p->content = NULL;
	}
	else
	{
		p->content = malloc(content_size);
		if (!p->content)
			return (NULL);
		ft_memcpy((p->content), content, content_size);
		p->content_size = content_size;
	}
	p->next = NULL;
	return (p);
}

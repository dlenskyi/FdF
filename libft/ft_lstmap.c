/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:46:06 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/30 15:46:10 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*buffer;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	buffer = tmp;
	lst = lst->next;
	while (lst)
	{
		buffer->next = f(lst);
		buffer = buffer->next;
		lst = lst->next;
	}
	return (tmp);
}

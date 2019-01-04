/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlenskyi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:48:32 by dlenskyi          #+#    #+#             */
/*   Updated: 2018/11/03 16:48:34 by dlenskyi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static int		ft_fill_line(char *info, char **line, t_list **list)
{
	if (!*info)
		return (0);
	if (!(ft_strchr(info, '\n')))
	{
		*line = ft_strdup(info);
		(*list)->content = NULL;
		return (1);
	}
	*line = ft_strsub(info, 0, (size_t)(ft_strchr(info, '\n') - info));
	(*list)->content = ft_strdup(ft_strchr(info, '\n') + 1);
	ft_strdel(&info);
	return (1);
}

static t_list	*get_fd(t_list **list, const int fd)
{
	t_list	*temp;

	temp = *list;
	while (temp)
	{
		if ((int)temp->content_size == fd)
			return (temp);
		temp = temp->next;
	}
	temp = ft_lstnew(NULL, fd);
	ft_lstadd(list, temp);
	return (temp);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*ptr;
	t_list			*my_fd;
	ssize_t			ret;
	char			buff[BUFF_SIZE + 1];
	char			*tmp;

	if (!line || BUFF_SIZE < 1 || fd < 0 || (read(fd, buff, 0) < 0))
		return (-1);
	my_fd = get_fd(&ptr, fd);
	*line = NULL;
	if (!my_fd->content)
		my_fd->content = ft_strnew(0);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		tmp = ft_strjoin(my_fd->content, buff);
		free(my_fd->content);
		my_fd->content = tmp;
		if (ft_strchr(my_fd->content, '\n'))
			break ;
	}
	if (!ret)
		if (my_fd->content)
			return (ft_fill_line(my_fd->content, line, &my_fd));
	return (ft_fill_line(my_fd->content, line, &my_fd));
}

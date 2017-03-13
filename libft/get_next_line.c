/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:58:07 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/02 17:49:37 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*file_manage(t_list **head, const int fd)
{
	t_list			*current;
	size_t			file_des;

	file_des = (size_t)fd;
	current = *head;
	while (current)
	{
		if (current->content_size == file_des)
			return (current);
		current = current->next;
	}
	current = ft_lstnew("\0", file_des);
	ft_lstadd(head, current);
	*((char*)current->content) = '\0';
	current = *head;
	return (current);
}

static int		gnl_magic(char **dst, char *src, const char delim)
{
	int				i;
	char			*tmp;

	i = 0;
	while (src[i])
	{
		if (src[i] == delim)
			break ;
		i++;
	}
	if ((tmp = ft_strnew(i)) == NULL)
		return (0);
	tmp = ft_strncpy(tmp, src, i);
	*dst = ft_strdup(tmp);
	free(tmp);
	return (i);
}

static void		gnl_i_ll_be_back(char **s, char delim)
{
	char			*tmp;
	int				i;
	int				len;

	tmp = *s;
	i = 0;
	len = ft_strlen(tmp);
	while (tmp[i])
	{
		if (tmp[i] == delim)
			break ;
		i++;
	}
	i++;
	*s = ft_strsub(tmp, i, len);
	free(tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				read_size;
	char			buf[BUFF_SIZE + 1];
	static t_list	*head;
	t_list			*current;
	char			*tmp;

	PROTECT_N2(line, fd, (read(fd, buf, 0)));
	current = file_manage(&head, fd);
	while ((read_size = read(fd, buf, BUFF_SIZE)))
	{
		tmp = ft_strdup(current->content);
		free(current->content);
		buf[read_size] = '\0';
		PROTECT_N1((current->content = ft_strjoin(tmp, buf)));
		free(tmp);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (read_size < BUFF_SIZE && !ft_strlen(current->content))
		return (0);
	read_size = gnl_magic(line, current->content, '\n');
	(read_size < (int)ft_strlen(current->content))
	? (gnl_i_ll_be_back((char**)&current->content, '\n'))
	: (ft_strdel((char**)&current->content));
	return (1);
}

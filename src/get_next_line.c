/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 15:58:07 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:53:32 by mvlad            ###   ########.fr       */
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
	current->content = 0;
	current = *head;
	return (current);
}

static size_t	gnl_magic(char **dst, char *src, const char delim)
{
	size_t			i;
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
	unsigned int	i;
	size_t			len;

	tmp = *s;
	i = 0;
	while (tmp[i])
	{
		if (tmp[i] == delim)
			break ;
		i++;
	}
	i++;
	len = ft_strlen(tmp) - i;
	*s = ft_strsub(tmp, i, len);
	free(tmp);
}

static int		gnl_loop(t_list *current, char *buf, ssize_t *read_size, int fd)
{
	char			*tmp;

	while ((*read_size = read(fd, buf, BUFF_SIZE)))
	{
		if (current->content != 0)
		{
			tmp = ft_strdup(current->content);
			free(current->content);
			buf[*read_size] = '\0';
			PROTECT_N1((current->content = ft_strjoin(tmp, buf)));
			free(tmp);
		}
		else
		{
			buf[*read_size] = '\0';
			tmp = ft_strnew(BUFF_SIZE);
			PROTECT_N1((current->content = ft_strjoin(tmp, buf)));
			free(tmp);
		}
		if (ft_strchr(buf, '\n'))
			return (0);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int					k;
	char				*buf;
	static t_list		*head;
	t_list				*current;
	ssize_t				read_size;

	if (BUFF_SIZE > 10000 || BUFF_SIZE < 1)
		return (-1);
	buf = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	PROTECT_N2(line, fd, (read(fd, buf, 0)));
	current = file_manage(&head, fd);
	k = gnl_loop(current, buf, &read_size, fd);
	if (k == -1)
		return (-1);
	if (read_size < BUFF_SIZE && !ft_strlen(current->content))
	{
		free(buf);
		return (0);
	}
	read_size = gnl_magic(line, current->content, '\n');
	(read_size < (int)ft_strlen(current->content))
	? (gnl_i_ll_be_back((char**)&current->content, '\n'))
	: (ft_strdel((char**)&current->content));
	free(buf);
	return (1);
}

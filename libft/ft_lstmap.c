/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:43:10 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:18:25 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_list(t_list *head)
{
	t_list			*crawler;

	while (head != NULL)
	{
		crawler = head->next;
		ft_memdel((void **)&head);
		head = crawler;
	}
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*head;
	t_list			*node;

	if (!lst || !f)
		return (NULL);
	node = ft_lstnew(lst->content, lst->content_size);
	if (node == NULL)
		return (NULL);
	node = (*f)(node);
	head = node;
	while (lst->next)
	{
		lst = lst->next;
		node->next = ft_lstnew(lst->content, lst->content_size);
		if (node->next == NULL)
		{
			del_list(head);
			return (NULL);
		}
		node->next = (*f)(node->next);
		node = node->next;
	}
	return (head);
}

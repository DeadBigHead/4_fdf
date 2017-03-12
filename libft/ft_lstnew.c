/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:53:53 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 13:02:26 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_node;

	new_node = (t_list*)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_node->content = NULL;
		new_node->content_size = 0;
		new_node->next = NULL;
		return (new_node);
	}
	new_node->content = malloc(content_size);
	if (new_node->content == NULL)
	{
		ft_memdel((void**)&new_node);
		return (NULL);
	}
	ft_memcpy(new_node->content, content, content_size);
	new_node->content_size = content_size;
	new_node->next = NULL;
	return (new_node);
}

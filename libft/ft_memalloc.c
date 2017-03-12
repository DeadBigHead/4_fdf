/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:20:52 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:21:40 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*new_mem;

	if (size == 0)
		return (NULL);
	new_mem = (void*)malloc(size);
	if (new_mem == NULL)
		return (NULL);
	ft_bzero(new_mem, size);
	return (new_mem);
}

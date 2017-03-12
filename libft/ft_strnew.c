/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:58:56 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:59:18 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	r_size;
	char	*new_str;

	r_size = size + 1;
	new_str = (char*)malloc(sizeof(char) * (r_size));
	if (new_str == NULL)
		return (NULL);
	ft_bzero(new_str, r_size);
	return (new_str);
}

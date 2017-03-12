/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:27:41 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:28:07 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dest_p;
	const char	*src_p;

	i = 0;
	dest_p = dest;
	src_p = src;
	while (n > 0)
	{
		dest_p[i] = src_p[i];
		i++;
		n--;
	}
	return (dest);
}

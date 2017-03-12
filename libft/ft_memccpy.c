/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:21:55 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:23:14 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		i;
	char		*dest_p;
	const char	*src_p;
	char		*ret_str;
	char		src_c;

	i = 0;
	dest_p = dest;
	src_p = src;
	while (i < n)
	{
		src_c = src_p[i];
		dest_p[i] = src_p[i];
		i++;
		if (src_c == c)
		{
			ret_str = (char*)&dest_p[i];
			return (ret_str);
		}
	}
	return (NULL);
}

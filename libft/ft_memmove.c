/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:29:02 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:00:55 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*dest1;
	const char		*src1;
	int				overlap;

	overlap = ft_overlapn(dest, src, n);
	dest1 = (char*)dest;
	src1 = (const char*)src;
	if (overlap == 1)
	{
		while (n)
		{
			n--;
			dest1[n] = src1[n];
		}
	}
	i = 0;
	while (i < n)
	{
		dest1[i] = src1[i];
		i++;
	}
	return (dest1);
}

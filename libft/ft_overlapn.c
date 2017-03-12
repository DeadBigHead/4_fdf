/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_overlapn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 15:03:04 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:04:00 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_overlapn(const void *dest, const void *src, size_t n)
{
	unsigned int	overlap;
	const char		*dst_s;
	const char		*dst_e;
	const char		*src_s;
	const char		*src_e;

	overlap = 0;
	dst_s = (const char*)dest;
	dst_e = (const char*)dest + n;
	src_s = (const char*)src;
	src_e = (const char*)src + n;
	if (dst_s >= src_s && dst_s <= src_e)
	{
		overlap = 1;
	}
	else if (dst_e <= src_e && dst_e >= src_e)
	{
		overlap = 1;
	}
	return (overlap);
}

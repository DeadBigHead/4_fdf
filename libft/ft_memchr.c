/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:23:31 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:25:43 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	*ret_str;
	unsigned char	chr;

	i = 0;
	chr = (unsigned char)c;
	ret_str = (unsigned char*)str;
	while (i < n)
	{
		if (ret_str[i] == chr)
		{
			ret_str = (unsigned char*)&ret_str[i];
			return (ret_str);
		}
		i++;
	}
	return (NULL);
}

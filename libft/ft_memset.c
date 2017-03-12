/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:29:42 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:30:15 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;
	unsigned char	*ret_str;

	i = 0;
	chr = (unsigned char)c;
	ret_str = (unsigned char*)str;
	while (n > 0)
	{
		ret_str[i] = chr;
		i++;
		n--;
	}
	return (ret_str);
}

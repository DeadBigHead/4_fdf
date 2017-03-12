/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:02:16 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 12:02:49 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*ret_str;

	len = ft_strlen(str);
	while (len != 0)
	{
		if (str[len] == c)
		{
			ret_str = (char*)&str[len];
			return (ret_str);
		}
		len--;
	}
	if (str[len] == c)
	{
		ret_str = (char*)&str[len];
		return (ret_str);
	}
	return (NULL);
}

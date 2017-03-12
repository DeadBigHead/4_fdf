/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:37:02 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:40:12 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	*ret_str;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
		{
			ret_str = (char*)&str[i];
			return (ret_str);
		}
		i++;
	}
	if (c == '\0' && str[i] == '\0')
	{
		ret_str = (char*)&str[i];
		return (ret_str);
	}
	return (NULL);
}

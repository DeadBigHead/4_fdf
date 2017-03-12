/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:44:19 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 11:44:55 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	len;
	char	*dest;

	len = ft_strlen(str);
	dest = (char*)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, str);
	return (dest);
}

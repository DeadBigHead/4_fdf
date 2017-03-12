/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:11:18 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 14:56:40 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *find)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (big[i] != '\0')
	{
		k = i;
		while (find[j] != '\0' && big[k] == find[j])
		{
			k++;
			j++;
		}
		if (find[j] != '\0' && big[k] != find[j])
			j = 0;
		if (j == ft_strlen(find))
			return ((char*)&big[k - j]);
		i++;
	}
	if (big[i] == '\0' && find[j] == '\0')
		return ((char*)&big[i]);
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:59:25 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:20:18 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *find, size_t n)
{
	size_t		i;
	size_t		j;
	size_t		k;

	i = 0;
	j = 0;
	k = 0;
	while (big[i] != '\0' && i < n)
	{
		k = i;
		while (k < n && find[j] != '\0' && big[k] == find[j])
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words_size.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 14:58:20 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:00:02 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	*ft_count_words_size(char const *s, char c, size_t words)
{
	size_t		i;
	size_t		k;
	size_t		n;
	size_t		*words_n_size;

	words_n_size = (size_t*)malloc(sizeof(size_t) * words);
	i = 0;
	n = 0;
	k = 1;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
		{
			k++;
			i++;
		}
		if (k > 1)
		{
			words_n_size[n++] = k;
			k = 1;
			i--;
		}
		i++;
	}
	return (words_n_size);
}

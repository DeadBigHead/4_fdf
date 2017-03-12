/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 12:04:45 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:53:24 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**alloc_words(size_t *words_n_size, size_t words, char **splited)
{
	size_t		i;

	i = 0;
	while (i < words)
	{
		splited[i] = (char*)ft_memalloc((words_n_size[i]) * sizeof(char));
		if (splited[i] == NULL)
		{
			while (i > 0)
			{
				ft_strdel(&splited[i]);
				i--;
			}
			ft_strdel(&splited[i]);
			ft_strdel(splited);
			return (NULL);
		}
		i++;
	}
	return (splited);
}

static char	**put_words(char const *s, char c, size_t words, char **splited)
{
	size_t		i;
	size_t		k;
	size_t		n;

	i = 0;
	k = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c && i > 0)
		{
			n++;
			k = 0;
		}
		if (s[i] != c && n < words && s[i] != '\0')
		{
			splited[n][k] = s[i];
			k++;
		}
		i++;
	}
	return (splited);
}

char		**ft_strsplit(char const *s, char c)
{
	size_t		*words_n_size;
	size_t		words;
	char		**splited;

	if (!s)
		return (NULL);
	words = ft_count_words(s, c);
	splited = (char**)ft_memalloc((words + 1) * sizeof(char*));
	if (splited == NULL)
		return (NULL);
	words_n_size = ft_count_words_size(s, c, words);
	splited = alloc_words(words_n_size, words, splited);
	if (splited == NULL)
		return (NULL);
	splited = put_words(s, c, words, splited);
	return (splited);
}

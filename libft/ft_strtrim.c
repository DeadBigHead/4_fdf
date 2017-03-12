/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 13:30:48 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:08:53 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char			*return_zero(void)
{
	char				*copy_s;

	copy_s = (char*)malloc(1);
	copy_s[0] = '\0';
	return (copy_s);
}

static size_t		first_space(char const *s)
{
	size_t				r;

	r = 0;
	while (s[r] == ' ' || s[r] == '\t' || s[r] == '\n')
		r++;
	return (r);
}

char				*ft_strtrim(char const *s)
{
	size_t				i;
	size_t				j;
	size_t				k;
	char				*copy_s;

	if (!s)
		return (NULL);
	i = first_space(s);
	if (s[i] == '\0')
		return (return_zero());
	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\t' || s[j] == '\n')
		j--;
	copy_s = ft_strnew((j - i) + 1);
	if (copy_s == NULL)
		return (NULL);
	k = 0;
	while (i < j + 1)
	{
		copy_s[k] = s[i];
		i++;
		k++;
	}
	copy_s[k] = '\0';
	return (copy_s);
}

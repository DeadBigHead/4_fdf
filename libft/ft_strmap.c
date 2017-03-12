/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:49:38 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/08 19:32:20 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	size_t	s_len;
	char	*new_str;

	if (!s || !f)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	new_str = ft_strnew(s_len);
	if (new_str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = (*f)(s[i]);
		i++;
	}
	return (new_str);
}

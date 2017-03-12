/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:46:54 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:09:51 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*con_str;
	size_t		s_len;

	if (!s1 || !s2)
		return (NULL);
	s_len = ft_strlen(s1) + ft_strlen(s2);
	con_str = ft_strnew(s_len);
	if (con_str == NULL)
		return (NULL);
	ft_strcpy(con_str, s1);
	ft_strcat(con_str, s2);
	return (con_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:40:57 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:10:40 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *str1, const char *str2)
{
	size_t			i;
	int				reslt;
	unsigned char	*s1;
	unsigned char	*s2;

	i = 0;
	s1 = (unsigned char*)str1;
	s2 = (unsigned char*)str2;
	while (s1[i] != '\0' && s1[i] == s2[i])
		i++;
	reslt = s1[i] - s2[i];
	return (reslt);
}

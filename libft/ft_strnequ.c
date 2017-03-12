/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:58:07 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:06:11 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int	reslt;

	if (!s1 || !s2)
		return (0);
	reslt = ft_strncmp(s1, s2, n);
	if (reslt == 0)
		return (1);
	else
		return (0);
}

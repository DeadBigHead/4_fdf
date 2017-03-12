/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:45:15 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:02:25 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		reslt;

	if (!s1 || !s2)
		return (0);
	reslt = ft_strcmp(s1, s2);
	if (reslt == 0)
		return (1);
	else
		return (0);
}

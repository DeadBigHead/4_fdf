/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:29:52 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:55:52 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_atoi_hex(char *s)
{
	int		i;
	int		nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 1)
		{
			nbr = nbr * 16 + (s[i] - '0');
		}
		else
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			nbr = nbr * 16 + (s[i] - 'A' + 10);
		}
		i++;
	}
	return (nbr);
}

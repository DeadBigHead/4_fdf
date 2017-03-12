/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 11:06:54 by mvlad             #+#    #+#             */
/*   Updated: 2016/12/15 15:16:35 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		digits_count(long n)
{
	size_t				i;

	i = 1;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i - 1);
}

static char			*put_positive(char *s1, size_t dgts, long nbr)
{
	char				*str;

	str = s1;
	while (nbr > 0)
	{
		dgts--;
		str[dgts] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (s1);
}

static char			*put_negative(char *s1, size_t dgts, long nbr)
{
	char				*str;

	str = s1;
	while (nbr > 0)
	{
		str[dgts] = nbr % 10 + '0';
		dgts--;
		nbr = nbr / 10;
	}
	str[0] = '-';
	return (s1);
}

char				*ft_itoa(int n)
{
	char				*str;
	long				nbr;
	unsigned int		minus;

	minus = 0;
	nbr = n;
	if (nbr < 0)
	{
		nbr = -nbr;
		minus = 1;
	}
	if (nbr == 0)
	{
		str = ft_strnew(1);
		str[0] = '0';
		return (str);
	}
	if (!(str = ft_strnew(digits_count(nbr) + minus)))
		return (NULL);
	if (minus == 1)
		str = put_negative(str, digits_count(nbr), nbr);
	if (minus == 0)
		str = put_positive(str, digits_count(nbr), nbr);
	return (str);
}

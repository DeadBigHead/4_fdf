/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel_color.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:27:31 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:38:19 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		color_support(t_map *map, int n, int k)
{
	while (n <= k)
	{
		map->tmp_color[map->j] = 0;
		map->j++;
		n++;
	}
}

static void		zero_color(t_map *map, int i)
{
	if (i / 2 == 0)
		color_support(map, 0, 3);
	else if (i / 2 == 1)
		color_support(map, 0, 2);
	else if (i / 2 == 2)
		color_support(map, 0, 1);
	else if (i / 2 == 3)
	{
		map->tmp_color[map->j] = 0;
		map->j++;
		return ;
	}
}

static void		present_color(t_map *map, int i)
{
	char			*tmp;
	int				v;
	int				d;

	v = map->end;
	while (map->line[v] != 'x' && map->line[v] != '\0')
		v++;
	d = FALSE;
	while (ft_ishex(map->line[v]) == 1 ||
			(map->line[v] == 'x' && (ft_ishex(map->line[v + 1]) == 1 &&
					d == FALSE)))
	{
		if (i % 2 == 0 && i <= 8 && i >= 2)
		{
			tmp = ft_strsub(map->line, (v - 1), 2);
			map->tmp_color[map->j] = ft_atoi_hex(tmp);
			free(tmp);
			map->j++;
		}
		i++;
		v++;
		d = TRUE;
	}
	i--;
	zero_color(map, i);
}

int				fdf_pixel_color(t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (map->line[map->end] == ',')
	{
		present_color(map, i);
		k = 1;
	}
	else
	{
		zero_color(map, k);
		k = 1;
	}
	if (k > 0)
		return (1);
	else
		return (0);
}

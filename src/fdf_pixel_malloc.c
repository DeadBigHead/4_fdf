/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel_malloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:27:48 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:54:06 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fdf_mal_pix
** Allocates memory for struct array @s_mlx->m_pixels.
*/

void	fdf_pixel_malloc(t_map *map, t_mlx *pixel)
{
	size_t	i;
	size_t	j;

	i = 0;
	pixel->m_pixels = (t_pixel***)malloc(sizeof(t_pixel**) * map->map_y);
	if (pixel->m_pixels == NULL)
		fdf_error(MALLCHECK);
	while (i < map->map_y)
	{
		pixel->m_pixels[i] = (t_pixel**)malloc(sizeof(t_pixel*) * map->map_x);
		if (pixel->m_pixels[i] == NULL)
			fdf_error(MALLCHECK);
		j = 0;
		while (j < map->map_x)
		{
			pixel->m_pixels[i][j] = (t_pixel*)malloc(sizeof(t_pixel));
			if (pixel->m_pixels[i][j] == NULL)
				fdf_error(MALLCHECK);
			j++;
		}
		i++;
	}
}

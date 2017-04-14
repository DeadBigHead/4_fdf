/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_my_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:27:17 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:42:40 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*find_min_max(t_map *map, t_mlx *mlx)
{
	int				*min_max;
	size_t			tr[2];
	int				tmp[2];

	tr[0] = 0;
	tr[1] = 0;
	min_max = (int*)malloc(sizeof(int) * 2);
	tmp[0] = mlx->m_pixels[tr[0]][tr[1]]->z;
	tmp[1] = mlx->m_pixels[tr[0]][tr[1]]->z;
	while (tr[0] < map->map_y)
	{
		tr[1] = 0;
		while (tr[1] < map->map_x)
		{
			if (mlx->m_pixels[tr[0]][tr[1]]->z < tmp[0])
				tmp[0] = mlx->m_pixels[tr[0]][tr[1]]->z;
			if (mlx->m_pixels[tr[0]][tr[1]]->z > tmp[1])
				tmp[1] = mlx->m_pixels[tr[0]][tr[1]]->z;
			tr[1]++;
		}
		tr[0]++;
	}
	min_max[0] = tmp[0];
	min_max[1] = tmp[1];
	return (min_max);
}

static int		*fdf_assign_color(void)
{
	int				*rgb;

	rgb = (int*)malloc(sizeof(int) * 12);
	rgb[3] = RED0;
	rgb[4] = GREEN0;
	rgb[5] = BLUE0;
	rgb[6] = RED1;
	rgb[7] = GREEN1;
	rgb[8] = BLUE1;
	rgb[9] = RED2;
	rgb[10] = GREEN2;
	rgb[11] = BLUE2;
	return (rgb);
}

static void		fdf_get_color_minus(t_map *map, t_mlx *mlx, int *rgb)
{
	int		*min_max;
	int		j;
	float	p;

	min_max = find_min_max(map, mlx);
	j = min_max[0];
	p = ((-j) - (-mlx->m_pixels[map->c][map->r]->z)) / (-j);
	rgb[0] = (rgb[3] - rgb[9]) * p + rgb[9];
	rgb[1] = (rgb[4] - rgb[10]) * p + rgb[10];
	rgb[2] = (rgb[5] - rgb[11]) * p + rgb[11];
	mlx->m_pixels[map->c][map->r]->red = rgb[0];
	mlx->m_pixels[map->c][map->r]->green = rgb[1];
	mlx->m_pixels[map->c][map->r]->blue = rgb[2];
}

static void		fdf_get_color_plus(t_map *map, t_mlx *mlx, int *rgb)
{
	int		k;
	int		*min_max;
	float	p;

	min_max = find_min_max(map, mlx);
	k = min_max[1];
	p = (k - mlx->m_pixels[map->c][map->r]->z) / k;
	if (k == 0)
	{
		mlx->m_pixels[map->c][map->r]->red = rgb[3];
		mlx->m_pixels[map->c][map->r]->green = rgb[4];
		mlx->m_pixels[map->c][map->r]->blue = rgb[5];
		return ;
	}
	rgb[0] = (rgb[3] - rgb[6]) * p + rgb[6];
	rgb[1] = (rgb[4] - rgb[7]) * p + rgb[7];
	rgb[2] = (rgb[5] - rgb[8]) * p + rgb[8];
	mlx->m_pixels[map->c][map->r]->red = rgb[0];
	mlx->m_pixels[map->c][map->r]->green = rgb[1];
	mlx->m_pixels[map->c][map->r]->blue = rgb[2];
}

void			fdf_my_color(t_map *map, t_mlx *mlx)
{
	int				*rgb;

	map->c = 0;
	rgb = fdf_assign_color();
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			if (mlx->m_pixels[map->c][map->r]->red == 0
					&& mlx->m_pixels[map->c][map->r]->green == 0
					&& mlx->m_pixels[map->c][map->r]->blue == 0)
			{
				if (mlx->m_pixels[map->c][map->r]->z < 0)
					fdf_get_color_minus(map, mlx, rgb);
				else
					fdf_get_color_plus(map, mlx, rgb);
			}
			map->r++;
		}
		map->c++;
	}
	free(rgb);
}

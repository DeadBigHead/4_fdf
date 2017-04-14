/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_pixel_read.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:27:56 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:03:55 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			set_color(t_map *map, t_mlx *mlx, int i)
{
	mlx->m_pixels[map->c][map->r]->red = map->tmp_color[i];
	mlx->m_pixels[map->c][map->r]->green = map->tmp_color[i + 1];
	mlx->m_pixels[map->c][map->r]->blue = map->tmp_color[i + 2];
	mlx->m_pixels[map->c][map->r]->alpha = map->tmp_color[i + 3];
}

static void			pixel_write_support(t_map *map)
{
	get_next_line(map->fd, &map->line);
	map->end = 0;
	map->i = 0;
	map->j = 0;
	map->tmp_color = (int*)malloc(sizeof(int) * (map->map_x * 4));
	map->tmp_z = (int*)malloc(sizeof(int) * map->map_x);
	if (map->tmp_z == NULL)
		fdf_error(MALLCHECK);
	map->ctrl = 0;
}

static void			fdf_pixel_write(t_map *map, t_mlx *mlx)
{
	int	i;

	map->c = 0;
	while (map->c < map->map_y)
	{
		i = 0;
		map->r = 0;
		pixel_write_support(map);
		while (map->r < map->map_x)
		{
			mlx->m_pixels[map->c][map->r]->x = map->r;
			mlx->m_pixels[map->c][map->r]->y = map->c;
			fdf_pixel_color_z(map);
			mlx->m_pixels[map->c][map->r]->z = map->tmp_z[map->r];
			set_color(map, mlx, i);
			i += 4;
			map->r++;
		}
		free(map->tmp_color);
		free(map->tmp_z);
		free(map->line);
		map->c++;
	}
}

void				fdf_pixel_read(t_map *map, t_mlx *mlx)
{
	map->tmp = 0;
	fdf_pixel_malloc(map, mlx);
	map->fd = open(map->name[1], O_RDONLY);
	fdf_pixel_write(map, mlx);
	if ((close(map->fd)) == -1)
		fdf_error(LINE);
}

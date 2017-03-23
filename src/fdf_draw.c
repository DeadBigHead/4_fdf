#include "fdf.h"

void	draw_pixel(t_map *map, )
{

}

void	draw_line(t_map *map, t_mlx *pixel)
{
	int dx;
	int dy;
	int err;
	int e2;
	int sx;
	int sy;

	dx = fabs(map->tmp_x2 - map->tmp_x1);
	dy = -fabs(map->tmp_y2 - map->tmp_y1);
	err = dx+dy;
	sx = map->tmp_x1 < map->tmp_x2 ? 1 : -1;
	sy = map->tmp_y1 < map->tmp_y2 ? 1 : -1;
	while(1)
	{
		draw_pixel(map);
		if (map->tmp_x1 == map->tmp_x2 && map->tmp_y1 == map->tmp_y2)
			break;
		e2 = 2*err;
		if (e2 > dy)
			err += dy; map->tmp_x1 += sx;
		if (e2 < dx)
			err += dx; map->tmp_y1 += sy;
	}
}

void	dup_coords(t_map *map, t_mlx *pixel, int flag)
{
	map->tmp_x1 = pixel->m_pixels[map->c][map->r]->x;
	map->tmp_y1 = pixel->m_pixels[map->c][map->r]->y;
	if (flag == 1)
	{
		map->tmp_x2 = pixel->m_pixels[map->c][map->r + 1]->x;
		map->tmp_y2 = pixel->m_pixels[map->c][map->r + 1]->y;
	}
	else if (flag == 2)
	{
		map->tmp_x2 = pixel->m_pixels[map->c + 1][map->r]->x;
		map->tmp_y2 = pixel->m_pixels[map->c + 1][map->r]->y;
	}
}

void	fdf_draw(t_map *map, t_mlx *pixel)
{
	int flag;

	map->c = 0;
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			if (map->r + 1 < map->map_x)
			{
				flag = 1;
				dup_coords(map, pixel, flag);
				draw_line(map, pixel);
			}
			else if (map->c + 1 < map->map_y)
			{
				flag = 2;
				dup_coords(map, pixel, flag);
				draw_line(map, pixel);
			}
			map->r++;
		}
		map->c++;
	}
}
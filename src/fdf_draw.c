#include "fdf.h"

void	draw_pixel(t_map *map, t_mlx *data, int flag)
{
	size_t i;

	if (flag == 1)
	{
		i = (map->tmp_y1 * data->size_line +
			 (map->tmp_x1 * (data->bits / 8)));
		if (data->endian == 0)
		{
			data->mlx_str[i] = data->m_pixels[map->c][map->r]->red;
			data->mlx_str[i + 1] = 150;
			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->blue;
			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->alpha;
		}
		else if (data->endian == 1)
		{
			data->mlx_str[i] = data->m_pixels[map->c][map->r]->alpha;
			data->mlx_str[i + 1] = 150;
			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->green;
			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->red;
		}
	}
	else if (flag == 0)
	{
		i = (map->tmp_y1 * data->size_line +
			 (map->tmp_x1 * (data->bits / 8)));
		if (data->endian == 0)
		{
			data->mlx_str[i] = data->m_pixels[map->c][map->r]->red;
			data->mlx_str[i + 1] = 150;
			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->blue;
			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->alpha;
		}
		else if (data->endian == 1)
		{
			data->mlx_str[i] = data->m_pixels[map->c][map->r]->alpha;
			data->mlx_str[i + 1] = 150;
			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->green;
			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->red;
		}
	}
}

void	draw_line(t_map *map, t_mlx *pixel)
{
	int        delta_x;
	int        delta_y;
	int        sign_x;
	int        sign_y;
	int        error;
	int 		error2;

	delta_x = fabs(map->tmp_x2 - map->tmp_x1);
	delta_y = fabs(map->tmp_y2 - map->tmp_y1);
	sign_x = map->tmp_x1 < map->tmp_x2 ? 1 : -1;
	sign_y = map->tmp_y1 < map->tmp_y2 ? 1 : -1;
	error = delta_x - delta_y;
	draw_pixel(map, pixel, 0);
	while (map->tmp_x1 != map->tmp_x2 || map->tmp_y1 != map->tmp_y2)
	{
		draw_pixel(map, pixel, 1);
		error2 = error * 2;
		(error2 > -delta_y) ? (error -= delta_y) : 0;
		(error2 > -delta_y) ? (map->tmp_x1 += sign_x) : 0;
		if (error2 < delta_x)
		{
			error += delta_x;
			map->tmp_y1 += sign_y;
		}
	}
//	int dx;
//	int dy;
//	int err;
//	int e2;
//	int sx;
//	int sy;
//
//	dx = fabs(map->tmp_x2 - map->tmp_x1);
//	dy = fabs(map->tmp_y2 - map->tmp_y1);
//	sx = map->tmp_x1 < map->tmp_x2 ? 1 : -1;
//	sy = map->tmp_y1 < map->tmp_y2 ? 1 : -1;
//	err = dx - dy;
//	draw_pixel(map, pixel, 0);
//	while(1)
//	{
//		draw_pixel(map, pixel, 1);
//		if (map->tmp_x1 == map->tmp_x2 && map->tmp_y1 == map->tmp_y2)
//			break;
//		e2 = 2*err;
//		if (e2 > -dy)
//		{
//			err -= dy;
//			map->tmp_x1 += sx;
//		}
//		if (e2 < dx)
//		{
//			err += dx;
//			map->tmp_y1 += sy;
//		}
//	}
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
//			if (map->r + 1 < map->map_x)
//			{
//				flag = 1;
//				dup_coords(map, pixel, flag);
//				draw_line(map, pixel);
//			}
			if (map->c + 1 < map->map_y)
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
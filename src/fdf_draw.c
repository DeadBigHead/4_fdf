#include "fdf.h"

void	draw_pixel(t_map *map, t_mlx *data, int flag, float p)
{
	size_t i;

	if (flag == 1)
	{
		i = (map->tmp_y1 * data->size_line +
			 (map->tmp_x1 * (data->bits / 8)));
		int r = (map->r1 - map->r0) * p + map->r0;
		int g = (map->g1 - map->g0) * p + map->g0;
		int b = (map->b1 - map->b0) * p + map->b0;
		if (data->endian == 1)
		{
			data->mlx_str[i] = data->m_pixels[map->c][map->r]->red;
			data->mlx_str[i + 1] = data->m_pixels[map->c][map->r]->green;
			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->blue;
			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->alpha;
		}
		else if (data->endian == 0)
		{

//			data->mlx_str[i] = data->m_pixels[map->c][map->r]->alpha;
			data->mlx_str[i + 0] = b;
			data->mlx_str[i + 1] = g;
			data->mlx_str[i + 2] = r;
		}
//	}
//	else if (flag == 0)
//	{
//		i = (map->tmp_y1 * data->size_line +
//			 (map->tmp_x1 * (data->bits / 8)));
//		if (data->endian == 0)
//		{
//			data->mlx_str[i] = data->m_pixels[map->c][map->r]->red;
//			data->mlx_str[i + 1] = data->m_pixels[map->c][map->r]->green;
//			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->blue;
//			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->alpha;
//		}
//		else if (data->endian == 1)
//		{
//			data->mlx_str[i] = data->m_pixels[map->c][map->r]->alpha;
//			data->mlx_str[i + 1] = data->m_pixels[map->c][map->r]->blue;
//			data->mlx_str[i + 2] = data->m_pixels[map->c][map->r]->green;
//			data->mlx_str[i + 3] = data->m_pixels[map->c][map->r]->red;
//		}
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
	float i;
	float i2;
	float i3;

	delta_x = abs(map->tmp_x2 - map->tmp_x1);
	delta_y = abs(map->tmp_y2 - map->tmp_y1);
	sign_x = map->tmp_x1 < map->tmp_x2 ? 1 : -1;
	sign_y = map->tmp_y1 < map->tmp_y2 ? 1 : -1;
	error = delta_x - delta_y;
	i = sqrtf((map->tmp_x2 - map->tmp_x1) * (map->tmp_x2 - map->tmp_x1)
			  + (map->tmp_y2 - map->tmp_y1) * (map->tmp_y2 - map->tmp_y1));
//	draw_pixel(map, pixel, 0);
	while (map->tmp_x1 != map->tmp_x2 || map->tmp_y1 != map->tmp_y2)
	{
		i2 = sqrtf((map->tmp_x2 - map->tmp_x1) * (map->tmp_x2 - map->tmp_x1)
				   + (map->tmp_y2 - map->tmp_y1) * (map->tmp_y2 - map->tmp_y1));
		i3 = (i - i2) / i;
		draw_pixel(map, pixel, 1, i3);
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

	map->r0 = pixel->m_pixels[map->c][map->r]->red;
	map->g0 = pixel->m_pixels[map->c][map->r]->green;
	map->b0 = pixel->m_pixels[map->c][map->r]->blue;
	if (flag == 1)
	{
		map->tmp_x2 = pixel->m_pixels[map->c][map->r + 1]->x;
		map->tmp_y2 = pixel->m_pixels[map->c][map->r + 1]->y;

		map->r1 = pixel->m_pixels[map->c][map->r + 1]->red;
		map->g1 = pixel->m_pixels[map->c][map->r + 1]->green;
		map->b1 = pixel->m_pixels[map->c][map->r + 1]->blue;
	}
	else if (flag == 2)
	{
		map->tmp_x2 = pixel->m_pixels[map->c + 1][map->r]->x;
		map->tmp_y2 = pixel->m_pixels[map->c + 1][map->r]->y;

		map->r1 = pixel->m_pixels[map->c + 1][map->r]->red;
		map->g1 = pixel->m_pixels[map->c + 1][map->r]->green;
		map->b1 = pixel->m_pixels[map->c + 1][map->r]->blue;
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
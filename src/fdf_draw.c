#include "fdf.h"

void	draw_pixel(t_mlx *data, int flag, float p)
{
	size_t i;

	i = (data->tmp_y1 * data->size_line +
		 (data->tmp_x1 * (data->bits / 8)));
	if (flag == 1 && i < data->total_size)
	{
		int r = (data->r1 - data->r0) * p + data->r0;
		int g = (data->g1 - data->g0) * p + data->g0;
		int b = (data->b1 - data->b0) * p + data->b0;
		if (data->endian == 1)
		{
			data->mlx_str[i] = data->m_pixels[data->c][data->r]->red;
			data->mlx_str[i + 1] = data->m_pixels[data->c][data->r]->green;
			data->mlx_str[i + 2] = data->m_pixels[data->c][data->r]->blue;
			data->mlx_str[i + 3] = data->m_pixels[data->c][data->r]->alpha;
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
	return;
}

void	draw_line(t_mlx *pixel)
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

	delta_x = abs(pixel->tmp_x2 - pixel->tmp_x1);
	delta_y = abs(pixel->tmp_y2 - pixel->tmp_y1);
	sign_x = pixel->tmp_x1 < pixel->tmp_x2 ? 1 : -1;
	sign_y = pixel->tmp_y1 < pixel->tmp_y2 ? 1 : -1;
	error = delta_x - delta_y;
	i = sqrtf((pixel->tmp_x2 - pixel->tmp_x1) * (pixel->tmp_x2 - pixel->tmp_x1)
			  + (pixel->tmp_y2 - pixel->tmp_y1) * (pixel->tmp_y2 - pixel->tmp_y1));
//	draw_pixel(map, pixel, 0);
	while (pixel->tmp_x1 != pixel->tmp_x2 || pixel->tmp_y1 != pixel->tmp_y2)
	{
		i2 = sqrtf((pixel->tmp_x2 - pixel->tmp_x1) * (pixel->tmp_x2 - pixel->tmp_x1)
				   + (pixel->tmp_y2 - pixel->tmp_y1) * (pixel->tmp_y2 - pixel->tmp_y1));
		i3 = (i - i2) / i;
		draw_pixel(pixel, 1, i3);
		error2 = error * 2;
		(error2 > -delta_y) ? (error -= delta_y) : 0;
		(error2 > -delta_y) ? (pixel->tmp_x1 += sign_x) : 0;
		if (error2 < delta_x)
		{
			error += delta_x;
			pixel->tmp_y1 += sign_y;
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

void	dup_coords(t_mlx *pixel, int flag)
{
	pixel->tmp_x1 = pixel->m_pixels[pixel->c][pixel->r]->x;
	pixel->tmp_y1 = pixel->m_pixels[pixel->c][pixel->r]->y;

	pixel->r0 = pixel->m_pixels[pixel->c][pixel->r]->red;
	pixel->g0 = pixel->m_pixels[pixel->c][pixel->r]->green;
	pixel->b0 = pixel->m_pixels[pixel->c][pixel->r]->blue;
	if (flag == 1)
	{
		pixel->tmp_x2 = pixel->m_pixels[pixel->c][pixel->r + 1]->x;
		pixel->tmp_y2 = pixel->m_pixels[pixel->c][pixel->r + 1]->y;

		pixel->r1 = pixel->m_pixels[pixel->c][pixel->r + 1]->red;
		pixel->g1 = pixel->m_pixels[pixel->c][pixel->r + 1]->green;
		pixel->b1 = pixel->m_pixels[pixel->c][pixel->r + 1]->blue;
	}
	else if (flag == 2)
	{
		pixel->tmp_x2 = pixel->m_pixels[pixel->c + 1][pixel->r]->x;
		pixel->tmp_y2 = pixel->m_pixels[pixel->c + 1][pixel->r]->y;

		pixel->r1 = pixel->m_pixels[pixel->c + 1][pixel->r]->red;
		pixel->g1 = pixel->m_pixels[pixel->c + 1][pixel->r]->green;
		pixel->b1 = pixel->m_pixels[pixel->c + 1][pixel->r]->blue;
	}
}

void	fdf_draw(t_mlx *pixel)
{
	int flag;

	pixel->c = 0;
	while (pixel->c < pixel->map_y)
	{
		pixel->r = 0;
		while (pixel->r < pixel->map_x)
		{
			if (pixel->r + 1 < pixel->map_x)
			{
				flag = 1;
				dup_coords(pixel, flag);
				draw_line(pixel);
			}
			if (pixel->c + 1 < pixel->map_y)
			{
				flag = 2;
				dup_coords(pixel, flag);
				draw_line(pixel);
			}
			pixel->r++;
		}
		pixel->c++;
	}
}
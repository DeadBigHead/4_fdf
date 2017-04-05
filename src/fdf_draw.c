#include "fdf.h"

void	draw_pixel(t_mlx *mlx, int flag, float p)
{
	size_t i;

//	if (data->tmp_x1 < 0 || data->tmp_x1 > WIDTH ||
//		data->tmp_y1 < 0 || data->tmp_y1 > HEIGHT)
//		data->step++;
	i = (mlx->y1 * mlx->line_sz + (mlx->x1 * (mlx->bit / 8)));
	if (flag == 1 && i < mlx->total_size &&
			mlx->x1 > 0 && mlx->x1 < WIDTH)
	{
		int r = (mlx->r1 - mlx->r0) * p + mlx->r0;
		int g = (mlx->g1 - mlx->g0) * p + mlx->g0;
		int b = (mlx->b1 - mlx->b0) * p + mlx->b0;
		if (mlx->end == 1)
		{
			mlx->str[i] = mlx->m_pixels[mlx->c][mlx->r]->red;
			mlx->str[i + 1] = mlx->m_pixels[mlx->c][mlx->r]->green;
			mlx->str[i + 2] = mlx->m_pixels[mlx->c][mlx->r]->blue;
			mlx->str[i + 3] = mlx->m_pixels[mlx->c][mlx->r]->alpha;
		}
		else if (mlx->end == 0)
		{
//			data->mlx_str[i] = data->m_pixels[map->c][map->r]->alpha;
			mlx->str[i + 0] = b;
			mlx->str[i + 1] = g;
			mlx->str[i + 2] = r;
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

void	draw_line(t_mlx *mlx)
{
//	int        delta_x;
//	int        delta_y;
//	int        sign_x;
//	int        sign_y;
//	int			error;
//	int 		error2;
//	float 		i;
//	float 		i2;
//	float 		i3;

	mlx->b->dlx = abs(mlx->x2 - mlx->x1);
	mlx->b->dly = abs(mlx->y2 - mlx->y1);
	mlx->b->snx = mlx->x1 < mlx->x2 ? 1 : -1;
	mlx->b->sny = mlx->y1 < mlx->y2 ? 1 : -1;
	mlx->b->er = mlx->b->dlx - mlx->b->dly;
//	draw_pixel(map, pixel, 0);
	while (mlx->x1 != mlx->x2 || mlx->y1 != mlx->y2)
	{
		mlx->b->i2 = sqrtf((mlx->x2 - mlx->x1) * (mlx->x2 - mlx->x1)
				   + (mlx->y2 - mlx->y1) * (mlx->y2 - mlx->y1));
		mlx->b->i3 = (mlx->b->i - mlx->b->i2) / mlx->b->i;
		draw_pixel(mlx, 1, mlx->b->i3);
		mlx->b->e2 = mlx->b->er * 2;
		(mlx->b->e2 > -mlx->b->dly) ? (mlx->b->er -= mlx->b->dly) : 0;
		(mlx->b->e2 > -mlx->b->dly) ? (mlx->x1 += mlx->b->snx) : 0;
		if ((mlx->x1 < -300 || mlx->x1 > WIDTH + 300 ||
				mlx->y1 < -300 || mlx->y1 > HEIGHT + 300))
			return;
		if (mlx->b->e2 < mlx->b->dlx)
		{
			mlx->b->er += mlx->b->dlx;
			mlx->y1 += mlx->b->sny;
		}
	}
}

void	dup_coords(t_mlx *mlx, int flag)
{
	mlx->x1 = mlx->m_pixels[mlx->c][mlx->r]->x;
	mlx->y1 = mlx->m_pixels[mlx->c][mlx->r]->y;
	mlx->r0 = mlx->m_pixels[mlx->c][mlx->r]->red;
	mlx->g0 = mlx->m_pixels[mlx->c][mlx->r]->green;
	mlx->b0 = mlx->m_pixels[mlx->c][mlx->r]->blue;
	if (flag == 1)
	{
		mlx->x2 = mlx->m_pixels[mlx->c][mlx->r + 1]->x;
		mlx->y2 = mlx->m_pixels[mlx->c][mlx->r + 1]->y;
		mlx->r1 = mlx->m_pixels[mlx->c][mlx->r + 1]->red;
		mlx->g1 = mlx->m_pixels[mlx->c][mlx->r + 1]->green;
		mlx->b1 = mlx->m_pixels[mlx->c][mlx->r + 1]->blue;
	}
	else if (flag == 2)
	{
		mlx->x2 = mlx->m_pixels[mlx->c + 1][mlx->r]->x;
		mlx->y2 = mlx->m_pixels[mlx->c + 1][mlx->r]->y;
		mlx->r1 = mlx->m_pixels[mlx->c + 1][mlx->r]->red;
		mlx->g1 = mlx->m_pixels[mlx->c + 1][mlx->r]->green;
		mlx->b1 = mlx->m_pixels[mlx->c + 1][mlx->r]->blue;
	}
	mlx->b->i = sqrtf((mlx->x2 - mlx->x1) * (mlx->x2 - mlx->x1)
					  + (mlx->y2 - mlx->y1) * (mlx->y2 - mlx->y1));
}

void	fdf_draw(t_mlx *mlx)
{
	int flag;

	mlx->b = (t_b*)malloc(sizeof(t_b));
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			if (mlx->r + 1 < mlx->map_x)
			{
				flag = 1;
				dup_coords(mlx, flag);
				draw_line(mlx);
			}
			if (mlx->c + 1 < mlx->map_y)
			{
				flag = 2;
				dup_coords(mlx, flag);
				draw_line(mlx);
			}
			mlx->r++;
		}
		mlx->c++;
	}
}
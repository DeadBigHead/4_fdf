#include "fdf.h"

static void		zoom_minus_y(t_mlx *mlx)
{
	int c;
	int r;

	while (mlx->m_pixels[mlx->map_y - 1][mlx->map_x - 1]->y > 400)
	{
		c = 0;
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				mlx->m_pixels[c][r]->x *= 0.9;
				mlx->m_pixels[c][r]->y *= 0.9;
				mlx->m_pixels[c][r]->z *= 0.9;
				r++;
			}
			c++;
		}
	}
}

static void		zoom_minus_x(t_mlx *mlx)
{
	int c;
	int r;

	while (mlx->m_pixels[mlx->map_y - 1][mlx->map_x - 1]->x > 400)
	{
		c = 0;
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				mlx->m_pixels[c][r]->x *= 0.9;
				mlx->m_pixels[c][r]->y *= 0.9;
				mlx->m_pixels[c][r]->z *= 0.9;
				r++;
			}
			c++;
		}
	}
}

void			fdf_zoom_auto_minus(t_mlx *mlx)
{
	if (mlx->map_x > mlx->map_y)
		zoom_minus_y(mlx);
	else
		zoom_minus_x(mlx);
}
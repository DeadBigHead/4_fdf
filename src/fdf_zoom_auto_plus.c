#include "fdf.h"

static void		zoom_plus_y(t_mlx *mlx)
{
	int c;
	int r;

	while (mlx->m_pixels[mlx->map_y - 1][mlx->map_x - 1]->y < 250)
	{
		c = 0;
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				mlx->m_pixels[c][r]->x *= 1.1;
				mlx->m_pixels[c][r]->y *= 1.1;
				mlx->m_pixels[c][r]->z *= 1.1;
				r++;
			}
			c++;
		}
	}
}

static void		zoom_plus_x(t_mlx *mlx)
{
	int c;
	int r;

	while (mlx->m_pixels[mlx->map_y - 1][mlx->map_x - 1]->x < 250)
	{
		c = 0;
		while (c < mlx->map_y)
		{
			r = 0;
			while (r < mlx->map_x)
			{
				mlx->m_pixels[c][r]->x *= 1.1;
				mlx->m_pixels[c][r]->y *= 1.1;
				mlx->m_pixels[c][r]->z *= 1.1;
				r++;
			}
			c++;
		}
	}
}

void			fdf_zoom_auto_plus(t_mlx *mlx)
{
	if (mlx->map_x > mlx->map_y)
		zoom_plus_y(mlx);
	else
		zoom_plus_x(mlx);
}
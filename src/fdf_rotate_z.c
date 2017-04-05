#include "fdf.h"

static void fdf_z_positive(t_mlx *mlx)
{
	float	tmpy;
	float	tmpx;
	double	r_plus;

	r_plus = DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpx = mlx->m_pixels[mlx->c][mlx->r]->x;
			tmpy = mlx->m_pixels[mlx->c][mlx->r]->y;
			mlx->m_pixels[mlx->c][mlx->r]->x =
					tmpx * cos(r_plus) + tmpy * sin(r_plus);
			mlx->m_pixels[mlx->c][mlx->r]->y =
					tmpy * cos(r_plus) - tmpx * sin(r_plus);
			mlx->r++;
		}
		mlx->c++;
	}
}

static void fdf_z_negative(t_mlx *mlx)
{
	float	tmpy;
	float	tmpx;
	double	r_minus;

	r_minus = -DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpx = mlx->m_pixels[mlx->c][mlx->r]->x;
			tmpy = mlx->m_pixels[mlx->c][mlx->r]->y;
			mlx->m_pixels[mlx->c][mlx->r]->x =
					tmpx * cos(r_minus) + tmpy * sin(r_minus);
			mlx->m_pixels[mlx->c][mlx->r]->y =
					tmpy * cos(r_minus) - tmpx * sin(r_minus);
			mlx->r++;
		}
		mlx->c++;
	}
}

void	fdf_rotate_z(int kcode, t_mlx *mlx)
{
	if (kcode == ZKEY)
	{
		fdf_z_positive(mlx);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == XKEY)
	{
		fdf_z_negative(mlx);
		fdf_redraw_zoom(mlx);
	}
}
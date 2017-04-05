#include "fdf.h"

static void fdf_x_positive(t_mlx *mlx)
{
	float	tmpy;
	float	tmpz;
	double	r_plus;


	r_plus = DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpy = mlx->m_pixels[mlx->c][mlx->r]->y;
			tmpz = mlx->m_pixels[mlx->c][mlx->r]->z;
			mlx->m_pixels[mlx->c][mlx->r]->y =
					tmpy * cos(r_plus) + tmpz * sin(r_plus);
			mlx->m_pixels[mlx->c][mlx->r]->z =
					tmpz * cos(r_plus) - tmpy * sin(r_plus);
			mlx->r++;
		}
		mlx->c++;
	}
}

static void fdf_x_negative(t_mlx *mlx)
{
	float	tmpy;
	float	tmpz;
	double	r_minus;

	r_minus = -DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpy = mlx->m_pixels[mlx->c][mlx->r]->y;
			tmpz = mlx->m_pixels[mlx->c][mlx->r]->z;
			mlx->m_pixels[mlx->c][mlx->r]->y =
					tmpy * cos(r_minus) + tmpz * sin(r_minus);
			mlx->m_pixels[mlx->c][mlx->r]->z =
					tmpz * cos(r_minus) - tmpy * sin(r_minus);
			mlx->r++;
		}
		mlx->c++;
	}
}

void	fdf_rotate_x(int kcode, t_mlx *mlx)
{
	if (kcode == QKEY)
	{
		fdf_x_positive(mlx);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == WKEY)
	{
		fdf_x_negative(mlx);
		fdf_redraw_zoom(mlx);
	}
}
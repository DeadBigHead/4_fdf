#include "fdf.h"

static void	fdf_scale(t_mlx *mlx, float n, int c, int r)
{
	mlx->m_pixels[c][r]->x *= n;
	mlx->m_pixels[c][r]->y *= n;
	mlx->m_pixels[c][r]->z *= n;
}

static void fdf_scale_plus(t_mlx *mlx, float by)
{
	int c;
	int r;
	int tmpx;
	int tmpy;

	c = 0;
	tmpx = mlx->wxcur;
	tmpy = mlx->wycur;
	fdf_center_zero(mlx);
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			fdf_scale(mlx, by, c, r);
			r++;
		}
		c++;
	}
//	if (mlx->zoom > 0)
//		mlx->bound += 65;
//	else if (mlx->zoom > 0 && mlx->map_y > 400 || mlx->map_x > 400)
//		mlx->bound += 5;
	mlx->zoom++;
	mlx->wxcur = tmpx;
	mlx->wycur = tmpy;
}

static void fdf_scale_minus(t_mlx *mlx, float by)
{
	int c;
	int r;
	int tmpx;
	int tmpy;

	c = 0;
	tmpx = mlx->wxcur;
	tmpy = mlx->wycur;
	fdf_center_zero(mlx);
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			fdf_scale(mlx, by, c, r);
			r++;
		}
		c++;
	}
//	if (mlx->zoom > 0)
//		mlx->bound -= 50;
	mlx->zoom--;
	mlx->wxcur = tmpx;
	mlx->wycur = tmpy;
}

void	fdf_zoom(int kcode, t_mlx *mlx)
{
	float by;
	int x;
	int nbr;
	int i;

	mlx->bound = mlx->b->i;
	i = 0;
	if(mlx->map_x > 50 || mlx->map_y > 50)
	{
		x = 50;
		while (x != mlx->map_x || x != mlx->map_y)
		{
			x += 50;
			i++;
		}
	}
	nbr = 22+i*3;
	fdf_center_find(mlx);
	if (kcode == PLUS && mlx->zoom <= nbr)
	{
		by = 1.1;
		fdf_scale_plus(mlx, by);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == MINUS && mlx->zoom >= -15)
	{
		by = 0.909090;
		fdf_scale_minus(mlx, by);
		fdf_redraw_zoom(mlx);
	}
}
#include "fdf.h"

static void fdf_move_up(t_mlx *mlx)
{
	int c;
	int r;

	c = 0;
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			mlx->m_pixels[c][r]->y -= 10;
			r++;
		}
		c++;
	}
	mlx->wycur -= 10;
}

static void fdf_move_down(t_mlx *mlx)
{
	int c;
	int r;

	c = 0;
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			mlx->m_pixels[c][r]->y += 10;
			r++;
		}
		c++;
	}
	mlx->wycur += 10;
}

static void fdf_move_right(t_mlx *mlx)
{
	int c;
	int r;

	c = 0;
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			mlx->m_pixels[c][r]->x += 10;
			r++;
		}
		c++;
	}
	mlx->wxcur += 10;
}

static void fdf_move_left(t_mlx *mlx)
{
	int c;
	int r;

	c = 0;
	while (c < mlx->map_y)
	{
		r = 0;
		while (r < mlx->map_x)
		{
			mlx->m_pixels[c][r]->x -= 10;
			r++;
		}
		c++;
	}
	mlx->wxcur -= 10;
}

void	fdf_move(int kcode, t_mlx *mlx)
{
	if (kcode == UP)
	{
		fdf_move_up(mlx);
		fdf_redraw(mlx);
	}
	if (kcode == DOWN)
	{
		fdf_move_down(mlx);
		fdf_redraw(mlx);
	}
	if (kcode == RIGHT)
	{
		fdf_move_right(mlx);
		fdf_redraw(mlx);
	}
	if (kcode == LEFT)
	{
		fdf_move_left(mlx);
		fdf_redraw(mlx);
	}
}
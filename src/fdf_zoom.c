/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_zoom.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:29:21 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:09:27 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		fdf_scale(t_mlx *mlx, float n, int c, int r)
{
	mlx->m_pixels[c][r]->x *= n;
	mlx->m_pixels[c][r]->y *= n;
	mlx->m_pixels[c][r]->z *= n;
}

static void		fdf_scale_plus(t_mlx *mlx, float by)
{
	size_t			c;
	size_t			r;
	int				tmpx;
	int				tmpy;

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
	mlx->zoom++;
	mlx->wxcur = tmpx;
	mlx->wycur = tmpy;
}

static void		fdf_scale_minus(t_mlx *mlx, float by)
{
	size_t			c;
	size_t			r;
	int				tmpx;
	int				tmpy;

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
	mlx->zoom--;
	mlx->wxcur = tmpx;
	mlx->wycur = tmpy;
}

void			fdf_zoom(int kcode, t_mlx *mlx)
{
	size_t	x;
	int		i;

	if (mlx->map_x > 300 || mlx->map_y > 300)
		mlx->bound = mlx->b->i;
	i = 0;
	x = 50;
	if (mlx->map_x > 50 || mlx->map_y > 50)
		while (x != mlx->map_x || x != mlx->map_y)
		{
			x += 50;
			i++;
		}
	fdf_center_find(mlx);
	if (kcode == PLUS && mlx->zoom <= (22 + i * 3))
	{
		fdf_scale_plus(mlx, 1.1);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == MINUS && mlx->zoom >= -15)
	{
		fdf_scale_minus(mlx, 0.909090);
		fdf_redraw_zoom(mlx);
	}
}

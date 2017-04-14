/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:28:26 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:59:00 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			fdf_y_positive(t_mlx *mlx)
{
	float				tmpz;
	float				tmpx;
	double				r_plus;

	r_plus = DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpx = mlx->m_pixels[mlx->c][mlx->r]->x;
			tmpz = mlx->m_pixels[mlx->c][mlx->r]->z;
			mlx->m_pixels[mlx->c][mlx->r]->x =
					tmpx * cos(r_plus) + tmpz * sin(r_plus);
			mlx->m_pixels[mlx->c][mlx->r]->z =
					tmpz * cos(r_plus) - tmpx * sin(r_plus);
			mlx->r++;
		}
		mlx->c++;
	}
}

static void			fdf_y_negative(t_mlx *mlx)
{
	float				tmpz;
	float				tmpx;
	double				r_minus;

	r_minus = -DTR(DEGREE);
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			tmpx = mlx->m_pixels[mlx->c][mlx->r]->x;
			tmpz = mlx->m_pixels[mlx->c][mlx->r]->z;
			mlx->m_pixels[mlx->c][mlx->r]->x =
					tmpx * cos(r_minus) + tmpz * sin(r_minus);
			mlx->m_pixels[mlx->c][mlx->r]->z =
					tmpz * cos(r_minus) - tmpx * sin(r_minus);
			mlx->r++;
		}
		mlx->c++;
	}
}

void				fdf_rotate_y(int kcode, t_mlx *mlx)
{
	if (kcode == AKEY)
	{
		fdf_y_positive(mlx);
		fdf_redraw_zoom(mlx);
	}
	if (kcode == SKEY)
	{
		fdf_y_negative(mlx);
		fdf_redraw_zoom(mlx);
	}
}

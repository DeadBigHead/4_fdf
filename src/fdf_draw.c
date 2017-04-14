/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:25:06 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:37:29 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_corner(t_mlx *mlx)
{
	size_t i;

	mlx->x1 = mlx->m_pixels[mlx->c - 1][mlx->r - 1]->x;
	mlx->y1 = mlx->m_pixels[mlx->c - 1][mlx->r - 1]->y;
	i = (mlx->y1 * mlx->line_sz + (mlx->x1 * (mlx->bit / 8)));
	if (i < mlx->total_size && mlx->x1 > 0 && mlx->x1 < WIDTH)
	{
		mlx->str[i] = mlx->m_pixels[mlx->c - 1][mlx->r - 1]->blue;
		mlx->str[i + 1] = mlx->m_pixels[mlx->c - 1][mlx->r - 1]->green;
		mlx->str[i + 2] = mlx->m_pixels[mlx->c - 1][mlx->r - 1]->red;
	}
}

static void		draw_pixel(t_mlx *mlx, int flag, float p)
{
	size_t			i;
	int				rgb[3];

	i = (mlx->y1 * mlx->line_sz + (mlx->x1 * (mlx->bit / 8)));
	if (flag == 1 && i < mlx->total_size && mlx->x1 > 0 && mlx->x1 < WIDTH)
	{
		rgb[0] = (mlx->r1 - mlx->r0) * p + mlx->r0;
		rgb[1] = (mlx->g1 - mlx->g0) * p + mlx->g0;
		rgb[2] = (mlx->b1 - mlx->b0) * p + mlx->b0;
		if (mlx->end == 1)
		{
			mlx->str[i + 0] = rgb[0];
			mlx->str[i + 1] = rgb[1];
			mlx->str[i + 2] = rgb[2];
		}
		else if (mlx->end == 0)
		{
			mlx->str[i + 0] = rgb[2];
			mlx->str[i + 1] = rgb[1];
			mlx->str[i + 2] = rgb[0];
		}
	}
	else if (flag == 2)
		draw_corner(mlx);
}

static void		draw_line(t_mlx *mlx)
{
	mlx->b->dlx = abs(mlx->x2 - mlx->x1);
	mlx->b->dly = abs(mlx->y2 - mlx->y1);
	mlx->b->snx = mlx->x1 < mlx->x2 ? 1 : -1;
	mlx->b->sny = mlx->y1 < mlx->y2 ? 1 : -1;
	mlx->b->er = mlx->b->dlx - mlx->b->dly;
	while (mlx->x1 != mlx->x2 || mlx->y1 != mlx->y2)
	{
		mlx->b->i2 = sqrtf((mlx->x2 - mlx->x1) * (mlx->x2 - mlx->x1) +
				(mlx->y2 - mlx->y1) * (mlx->y2 - mlx->y1));
		mlx->b->i3 = (mlx->b->i - mlx->b->i2) / mlx->b->i;
		draw_pixel(mlx, 1, mlx->b->i3);
		mlx->b->e2 = mlx->b->er * 2;
		(mlx->b->e2 > -mlx->b->dly) ? (mlx->b->er -= mlx->b->dly) : 0;
		(mlx->b->e2 > -mlx->b->dly) ? (mlx->x1 += mlx->b->snx) : 0;
		if ((mlx->x1 < -(mlx->bound) || mlx->x1 > WIDTH + mlx->bound ||
					mlx->y1 < -(mlx->bound) || mlx->y1 > HEIGHT + mlx->bound))
			return ;
		if (mlx->b->e2 < mlx->b->dlx)
		{
			mlx->b->er += mlx->b->dlx;
			mlx->y1 += mlx->b->sny;
		}
	}
}

static void		dup_coords(t_mlx *mlx, int flag)
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
	mlx->b->i = sqrtf((mlx->x2 - mlx->x1) * (mlx->x2 - mlx->x1) +
			(mlx->y2 - mlx->y1) * (mlx->y2 - mlx->y1));
}

void			fdf_draw(t_mlx *mlx)
{
	mlx->b = (t_b*)malloc(sizeof(t_b));
	mlx->c = 0;
	while (mlx->c < mlx->map_y)
	{
		mlx->r = 0;
		while (mlx->r < mlx->map_x)
		{
			if (mlx->r + 1 < mlx->map_x)
			{
				dup_coords(mlx, 1);
				draw_line(mlx);
			}
			if (mlx->c + 1 < mlx->map_y)
			{
				dup_coords(mlx, 2);
				draw_line(mlx);
			}
			mlx->r++;
		}
		mlx->c++;
	}
	draw_pixel(mlx, 2, 0);
}

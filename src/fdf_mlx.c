/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:27:01 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:06:51 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_redraw_zoom(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_bzero(mlx->str, mlx->total_size);
	fdf_center_find(mlx);
	fdf_center_current(mlx);
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
	fdf_ui(mlx);
}

void	fdf_redraw(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_bzero(mlx->str, mlx->total_size);
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
	fdf_ui(mlx);
}

/*
** Initial draw of the image.
*/

void	fdf_first_draw(t_mlx *mlx, t_map *map)
{
	mlx->map_x = map->map_x;
	mlx->map_y = map->map_y;
	mlx->total_size = WIDTH * HEIGHT * 4;
	fdf_center_find(mlx);
	fdf_center_place(mlx);
	fdf_draw(mlx);
	mlx->win = mlx_new_window(mlx->ptr, mlx->width, mlx->height, "FdF");
	if (mlx->win == NULL)
		exit(0);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
}

/*
** Initial setup for the minilibx
*/

void	fdf_mlx_init(t_mlx *mlx, t_map *map)
{
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit(0);
	mlx->img = mlx_new_image(mlx->ptr, mlx->width, mlx->height);
	if (mlx->img == NULL)
		exit(0);
	mlx->str = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->line_sz, &mlx->end);
	if (mlx->str == NULL)
		exit(0);
	mlx->map_x = map->map_x;
	mlx->map_y = map->map_y;
	if (mlx->map_x && mlx->map_y < 400)
		fdf_zoom_auto_plus(mlx);
	else if (mlx->map_x && mlx->map_y > 400)
		fdf_zoom_auto_minus(mlx);
	fdf_first_draw(mlx, map);
	mlx->zoom = 0;
	mlx->bound = 15000;
	mlx->name = map->name;
}

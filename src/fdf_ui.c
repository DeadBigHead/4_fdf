/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_ui.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:28:40 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:44:08 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_ui(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 20, 740, 0x00FFFFFF, "Controls:");
	mlx_string_put(mlx->ptr, mlx->win, 20, 760, 0x00FFFFFF, "Exit: ESC");
	mlx_string_put(mlx->ptr, mlx->win, 20, 780, 0x00FFFFFF,
			"Move: arrow keys");
	mlx_string_put(mlx->ptr, mlx->win, 20, 800, 0x00FFFFFF,
			"Zoom in/out: +/-");
	mlx_string_put(mlx->ptr, mlx->win, 20, 820, 0x00FFFFFF,
			"Rotate along X axis: Q/W");
	mlx_string_put(mlx->ptr, mlx->win, 20, 840, 0x00FFFFFF,
			"Rotate along Y axis: A/S");
	mlx_string_put(mlx->ptr, mlx->win, 20, 860, 0x00FFFFFF,
			"Rotate along Z axis: Z/X");
}

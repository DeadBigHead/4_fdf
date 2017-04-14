/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:23:58 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:13:15 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;

	if (ac == 2)
	{
		map.name = av;
		fdf_validate(&map);
		fdf_pixel_read(&map, &mlx);
		fdf_my_color(&map, &mlx);
		fdf_win_setup(&mlx);
		fdf_mlx_init(&mlx, &map);
		fdf_ui(&mlx);
		mlx_hook(mlx.win, 2, 5, &fdf_key_core, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		fdf_error(USAGE);
}

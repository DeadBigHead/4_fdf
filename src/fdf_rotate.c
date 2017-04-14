/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:28:13 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:28:14 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_rotate(int kcode, t_mlx *mlx)
{
	if (kcode == QKEY || kcode == WKEY)
		fdf_rotate_x(kcode, mlx);
	if (kcode == AKEY || kcode == SKEY)
		fdf_rotate_y(kcode, mlx);
	if (kcode == ZKEY || kcode == XKEY)
		fdf_rotate_z(kcode, mlx);
}

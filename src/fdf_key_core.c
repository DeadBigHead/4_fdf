/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_key_core.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:25:47 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:01:08 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_key_core(int kcode, t_mlx *data)
{
	if (kcode == 53)
		exit(0);
	if (kcode == UP || kcode == DOWN || kcode == LEFT || kcode == RIGHT)
		fdf_move(kcode, data);
	if (kcode == PLUS || kcode == MINUS)
		fdf_zoom(kcode, data);
	if (kcode == QKEY || kcode == WKEY ||
			kcode == AKEY || kcode == SKEY ||
			kcode == ZKEY || kcode == XKEY)
		fdf_rotate(kcode, data);
	return (0);
}

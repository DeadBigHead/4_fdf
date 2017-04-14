/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center_current.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:24:18 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:24:20 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_center_current(t_mlx *data)
{
	int		xdif;
	int		ydif;

	xdif = data->wxcur - data->xcen;
	ydif = data->wycur - data->ycen;
	data->c = 0;
	while (data->c < data->map_y)
	{
		data->r = 0;
		while (data->r < data->map_x)
		{
			data->m_pixels[data->c][data->r]->x += xdif;
			data->m_pixels[data->c][data->r]->y += ydif;
			data->r++;
		}
		data->c++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center_place.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:24:48 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:24:50 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_center_place(t_mlx *data)
{
	int		xdif;
	int		ydif;

	xdif = data->wcenx - data->xcen;
	ydif = data->wceny - data->ycen;
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

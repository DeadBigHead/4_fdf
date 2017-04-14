/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_center_zero.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:24:56 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:24:58 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_center_zero(t_mlx *data)
{
	data->c = 0;
	while (data->c < data->map_y)
	{
		data->r = 0;
		while (data->r < data->map_x)
		{
			data->m_pixels[data->c][data->r]->x -= data->xcen;
			data->m_pixels[data->c][data->r]->y -= data->ycen;
			data->r++;
		}
		data->c++;
	}
	data->wxcur = 0;
	data->wycur = 0;
}

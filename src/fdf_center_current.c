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
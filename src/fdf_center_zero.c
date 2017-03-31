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
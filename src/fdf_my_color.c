#include "fdf.h"

int		*find_min_max(t_map	*map, t_mlx *data)
{
	int *min_max;

	int j;
	int k;
	map->r = 0;
	map->c = 0;
	min_max = (int*)malloc(sizeof(int) * 2);
//	min_max[0] = data->m_pixels[map->c][map->r]->z;
//	min_max[1] = data->m_pixels[map->c][map->r]->z;

	j = data->m_pixels[map->c][map->r]->z;
	k = data->m_pixels[map->c][map->r]->z;
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			if (data->m_pixels[map->c][map->r]->z < j)
				j = data->m_pixels[map->c][map->r]->z;
			if (data->m_pixels[map->c][map->r]->z > k)
				k = data->m_pixels[map->c][map->r]->z;
			map->r++;
		}
		map->c++;
	}
	min_max[0] = j;
	min_max[1] = k;
	return (min_max);
}

void	fdf_my_color(t_map	*map, t_mlx *data)
{
	int *min_max;
	int i;

	int r0;
	int g0;
	int b0;
	int r1;
	int g1;
	int b1;
	int r2;
	int g2;
	int b2;

	r0 = RED0;
	g0 = GREEN0;
	b0 = BLUE0;
	r1 = RED1;
	g1 = GREEN1;
	b1 = BLUE1;
	r2 = RED2;
	g2 = GREEN2;
	b2 = BLUE2;
	min_max = find_min_max(map, data);
	int j = min_max[0];
	int k = min_max[1];
	map->c = 0;
	i = sqrtf((min_max[1] - min_max[0]) * (min_max[1] - min_max[0]));
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			if (data->m_pixels[map->c][map->r]->red == 0
					&& data->m_pixels[map->c][map->r]->green == 0
					   && data->m_pixels[map->c][map->r]->blue == 0)
			{
				float p;
				int r;
				int b;
				int g;
				if (data->m_pixels[map->c][map->r]->z < 0)
				{
					p = ((-j) - (-data->m_pixels[map->c][map->r]->z)) / (-j);
					r = (r0 - r2) * p + r2;
					g = (g0 - g2) * p + g2;
					b = (b0 - b2) * p + b2;
				}
				else
				{
					p = (k - data->m_pixels[map->c][map->r]->z) / k;
					r = (r0 - r1) * p + r1;
					g = (g0 - g1) * p + g1;
					b = (b0 - b1) * p + b1;
				}
				data->m_pixels[map->c][map->r]->red = r;
				data->m_pixels[map->c][map->r]->green = g;
				data->m_pixels[map->c][map->r]->blue = b;
			}
			map->r++;
		}
		map->c++;
	}
}
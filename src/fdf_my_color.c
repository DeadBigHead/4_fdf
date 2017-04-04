#include "fdf.h"

static int		*find_min_max(t_map	*map, t_mlx *mlx)
{
	int *min_max;
	int j;
	int k;

	map->r = 0;
	map->c = 0;
	min_max = (int*)malloc(sizeof(int) * 2);
	j = mlx->m_pixels[map->c][map->r]->z;
	k = mlx->m_pixels[map->c][map->r]->z;
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			if (mlx->m_pixels[map->c][map->r]->z < j)
				j = mlx->m_pixels[map->c][map->r]->z;
			if (mlx->m_pixels[map->c][map->r]->z > k)
				k = mlx->m_pixels[map->c][map->r]->z;
			map->r++;
		}
		map->c++;
	}
	min_max[0] = j;
	min_max[1] = k;
	return (min_max);
}

static int	*fdf_assign_color(int *rgb)
{
	rgb = (int*)malloc(sizeof(int) * 12);
	rgb[3] = RED0;
	rgb[4] = GREEN0;
	rgb[5] = BLUE0;
	rgb[6] = RED1;
	rgb[7] = GREEN1;
	rgb[8] = BLUE1;
	rgb[9] = RED2;
	rgb[10] = GREEN2;
	rgb[11] = BLUE2;
	return (rgb);
}

static int	*fdf_get_color_minus(t_map *map, t_mlx *mlx, int *rgb)
{
	int		*min_max;
	int		j;
	float	p;

	min_max = find_min_max(map, mlx);
	j = min_max[0];
	p = ((-j) - (-mlx->m_pixels[map->c][map->r]->z)) / (-j);
	rgb[0] = (rgb[3] - rgb[9]) * p + rgb[9];
	rgb[1] = (rgb[4] - rgb[10]) * p + rgb[10];
	rgb[2] = (rgb[5] - rgb[11]) * p + rgb[11];
	return (rgb);
}

static int	*fdf_get_color_plus(t_map *map, t_mlx *mlx, int *rgb)
{
	int		k;
	int		*min_max;
	float	p;

	min_max = find_min_max(map, mlx);
	k = min_max[1];
	p = (k - mlx->m_pixels[map->c][map->r]->z) / k;
	rgb[0] = (rgb[3] - rgb[6]) * p + rgb[6];
	rgb[1] = (rgb[4] - rgb[7]) * p + rgb[7];
	rgb[2] = (rgb[5] - rgb[8]) * p + rgb[8];
	return (rgb);
}
void	fdf_my_color(t_map	*map, t_mlx *mlx)
{
	int		*rgb;
//	int 	i;

	map->c = 0;
//	i = sqrtf((min_max[1] - min_max[0]) * (min_max[1] - min_max[0]));
	while (map->c < map->map_y)
	{
		map->r = 0;
		while (map->r < map->map_x)
		{
			rgb = fdf_assign_color(rgb);
			if (mlx->m_pixels[map->c][map->r]->red == 0
					&& mlx->m_pixels[map->c][map->r]->green == 0
					   && mlx->m_pixels[map->c][map->r]->blue == 0)
			{
				if (mlx->m_pixels[map->c][map->r]->z < 0)
					fdf_get_color_minus(map, mlx, rgb);
				else
					fdf_get_color_plus(map, mlx, rgb);
				mlx->m_pixels[map->c][map->r]->red = rgb[0];
				mlx->m_pixels[map->c][map->r]->green = rgb[1];
				mlx->m_pixels[map->c][map->r]->blue = rgb[2];
				free (rgb);
			}
			map->r++;
		}
		map->c++;
	}
}
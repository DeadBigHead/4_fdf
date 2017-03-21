#include "fdf.h"

void	my_color(t_map *map, t_mlx *pixel)
{
	int		k;

	k = 0;
	map->tmp_color = (int*)malloc(sizeof(int) * (map->map_x * 4));
	while (k < 3)
	{
		map->tmp_color[k] = 0;
		k++;
	}
}
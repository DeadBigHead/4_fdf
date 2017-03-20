#include "fdf.h"



void	fdf_set_color(t_map *map, t_mlx *pixel)
{
	char *tmp;
	int	i;
	int k;

	while (map->line[map->end] != 'x' && map->line[map->end] != '\0')
		map->end++;
	map->end++;
	i = 0;
	k = 0;
	map->tmp_color = (int*)malloc(sizeof(int) * (map->map_x * 4));
	while (ft_ishex(map->line[map->end]) == 1)
	{
		if (i == 2)
		{
			tmp = ft_strsub(map->line, (map->end - i), 2);
			map->tmp_color[k] = fdf_atoi_hex(tmp);
			free(tmp);
			k++;
		}
		else if (i == 4)
		{
			tmp = ft_strsub(map->line, (map->end - (i + 2)), 2);
			map->tmp_color[k] = fdf_atoi_hex(tmp);
			free(tmp);
			k++;
		}
		else if (i == 6)
		{
			tmp = ft_strsub(map->line, (map->end - (i + 4)), 2);
			map->tmp_color[k] = fdf_atoi_hex(tmp);
			free(tmp);
			k++;
		}
		else if (i == 8)
		{
			tmp = ft_strsub(map->line, (map->end - (i + 6)), 2);
			map->tmp_color[k] = fdf_atoi_hex(tmp);
			free(tmp);
			k++;
		}
		i++;
		map->end++;
	}
}
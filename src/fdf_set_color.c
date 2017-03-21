#include "fdf.h"

void	zero_color(t_map *map, int i)
{
	if (i / 2 == 0)
	{
		i = 0;
		while (i <= 3)
		{
			map->tmp_color[map->j] = 0;
			map->j++;
			i++;
		}
		return;
	}
	else if (i / 2 == 1)
	{
		i = 0;
		while (i <= 2)
		{
			map->tmp_color[map->j] = 0;
			map->j++;
			i++;
		}
		return;
	}
	else if (i / 2 == 2)
	{
		i = 0;
		while (i <= 1)
		{
			map->tmp_color[map->j] = 0;
			map->j++;
			i++;
		}
		return;
	}
	else if (i / 2 == 3)
	{
		map->tmp_color[map->j] = 0;
		map->j++;
		return;
	}
}

void	present_color(t_map *map, int i)
{
	char	*tmp;
	int		v;
	int 	d;

	v = map->end;
	while (map->line[v] != 'x' && map->line[v] != '\0')
		v++;
	d = FALSE;
	while (ft_ishex(map->line[v]) == 1 ||
			(map->line[v] == 'x' && (ft_ishex(map->line[v + 1]) == 1 &&
									d == FALSE)))
	{
		if (i % 2 == 0 && i <= 8 && i >= 2)
		{
			tmp = ft_strsub(map->line, (v - 1), 2);
			map->tmp_color[map->j] = fdf_atoi_hex(tmp);
			free(tmp);
			map->j++;
		}
		i++;
		v++;
		d = TRUE;
	}
	i--;
	zero_color(map, i);
}

int		fdf_save_color(t_map *map)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	if (map->line[map->end] == ',')
	{
		present_color(map, i);
		k = 1;
	}
	else
	{
		zero_color(map, k);
		k = 1;
	}
	if (k > 0)
		return (1);
	else
		return (0);
}
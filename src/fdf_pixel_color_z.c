#include "fdf.h"

static void		set_z_support(t_map *map)
{
	map->tmp_z[map->i] = 0;
	map->i++;
}

static void		set_z(t_map *map)
{
	char	*tmp;
	int		nbr;

	if (ft_isdigit(map->line[map->beg]) == 0 && (map->line[map->beg] != '-' &&
			  ft_isdigit(map->line[map->beg + 1]) != 1))
		set_z_support(map);
	else if (ft_isdigit(map->line[map->beg]) == 1 ||
			(map->line[map->beg] == '-' &&
					ft_isdigit(map->line[map->beg + 1]) == 1))
	{
		map->end = map->beg;
		while (ft_isdigit(map->line[map->end]) == 1 ||
			   (map->line[map->end] == '-' &&
			   ft_isdigit(map->line[map->end + 1]) == 1))
			map->end++;
		tmp = ft_strsub(map->line, map->beg, (map->end - map->beg));
		nbr = ft_atoi(tmp);
		map->tmp_z[map->i] = ft_atoi(tmp);
		(nbr > MAXZ) ? (map->tmp_z[map->i] = MAXZ) : (map->tmp_z[map->i] = nbr);
		(nbr < MINZ) ? (map->tmp_z[map->i] = MINZ) : (map->tmp_z[map->i] = nbr);
		map->i++;
		free(tmp);
	}
}

void			fdf_pixel_color_z(t_map *map)
{
	map->tmp = 0;
	map->beg = map->end;
	if (map->line[map->beg] == '\0' || map->ctrl == map->map_x)
		return;
	while (map->line[map->beg] != '\0' && map->line[map->beg] == ' ')
		map->beg++;
	set_z(map);
	while (map->line[map->end] != ' ' && map->line[map->end] != '\0')
	{
		if (map->line[map->end] == ',' && map->line[map->end + 1] == '0'
			&& map->line[map->end + 2] == 'x' && map->tmp == 0)
			map->tmp = fdf_pixel_color(map);
		map->end++;
	}
	if (map->tmp == 0)
		fdf_pixel_color(map);
	map->ctrl++;
	fdf_pixel_color_z(map);
}
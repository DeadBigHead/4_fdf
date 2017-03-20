#include "fdf.h"

void	set_z(t_map *map)
{
	char	*tmp;

	map->end = map->beg;
	while (ft_isdigit(map->line[map->end]) == 1)
		map->end++;
	tmp = ft_strsub(map->line, map->beg, (map->end - map->beg));
	map->tmp_z[map->i] = ft_atoi(tmp);
	map->i++;
	free(tmp);
}

void	set_color(t_map *map, t_mlx *pixel)
{
	pixel->m_pixels[map->c][map->r]->red = map->tmp_z[j];
}

void	color_and_z(t_map *map, t_mlx *pixel)
{
	map->beg = map->end;
	if (map->line[map->beg] == '\0')
		return;
	while (map->line[map->beg] != '\0' && map->line[map->beg] == ' ')
		map->beg++;
	if (ft_isdigit(map->line[map->beg]) == 0)
	{
		map->tmp_z[map->i] = 0;
		map->i++;
	}
	else if (ft_isdigit(map->line[map->beg]) == 1)
	{
		set_z(map);
	}
	while (map->line[map->end] != ' ' && map->line[map->end] != '\0')
	{
		if (map->line[map->end] == ',' && map->line[map->end + 1] == '0'
			&& map->line[map->end + 2] == 'x')
			fdf_set_color(map, pixel);
		map->end++;
	}
	color_and_z(map, pixel);
}

void	handle_pixel(t_map *map, t_mlx *pixel)
{
	map->c = 0;
	while (map->c < map->map_y)
	{
		map->r = 0;
		pixel->m_pixels[map->c][map->r]->y = map->c;
		get_next_line(map->fd, &map->line);
		map->end = 0;
		map->i = 0;
		map->tmp_z = (int*)malloc(sizeof(int) * map->map_x);
		if(map->tmp_z == NULL)
			fdf_error(MALLCHECK);
		while (map->r < map->map_x)
		{
			pixel->m_pixels[map->c][map->r]->x = map->r;
			color_and_z(map, pixel);
			pixel->m_pixels[map->c][map->r]->z = map->tmp_z[map->r];
			set_color(map, pixel);
			map->r++;
		}
		free(map->tmp_z);
		free(map->line);
		map->c++;
	}
}

void	fdf_coordinates(t_map *map, t_mlx *pixel)
{
	int i, j;
	fdf_mal_pix(map, pixel);
	map->fd = open(map->name[1], O_RDONLY);
	handle_pixel(map, pixel);
	if ((close(map->fd)) == -1)
		fdf_error(LINE);
	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			printf("%.0f, ", pixel->m_pixels[i][j]->z);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("%d\n", map->tmp_color[0]);
	printf("%d\n", map->tmp_color[1]);
	printf("%d\n", map->tmp_color[2]);
	printf("%d\n", map->tmp_color[3]);
}
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

void	set_color(t_map *map, t_mlx *pixel, int i)
{
	pixel->m_pixels[map->c][map->r]->red = map->tmp_color[i];
	pixel->m_pixels[map->c][map->r]->green = map->tmp_color[i + 1];
	pixel->m_pixels[map->c][map->r]->blue = map->tmp_color[i + 2];
	pixel->m_pixels[map->c][map->r]->alpha = map->tmp_color[i + 3];
}

void	color_and_z(t_map *map, t_mlx *pixel)
{
	map->tmp = 0;
	map->beg = map->end;
	if (map->line[map->beg] == '\0' || map->ctrl == map->map_x)
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
			&& map->line[map->end + 2] == 'x' && map->tmp == 0)
			map->tmp = fdf_save_color(map);
		map->end++;
	}
	if (map->tmp == 0)
		fdf_save_color(map);
	map->ctrl++;
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
		map->j = 0;
		map->tmp_color = (int*)malloc(sizeof(int) * (map->map_x * 4));
		map->tmp_z = (int*)malloc(sizeof(int) * map->map_x);
		if(map->tmp_z == NULL)
			fdf_error(MALLCHECK);
		int i = 0;
		map->ctrl = 0;
		while (map->r < map->map_x)
		{
			pixel->m_pixels[map->c][map->r]->x = map->r;
			color_and_z(map, pixel);
			pixel->m_pixels[map->c][map->r]->z = map->tmp_z[map->r];
			set_color(map, pixel, i);
			i += 4;
			map->r++;
		}
		free(map->tmp_color);
		free(map->tmp_z);
		free(map->line);
		map->c++;
	}
}

void	fdf_coordinates(t_map *map, t_mlx *pixel)
{
	map->tmp = 0;
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
			printf("%.0f ", pixel->m_pixels[i][j]->z);
			printf("|%d,", pixel->m_pixels[i][j]->red);
			printf("%d,", pixel->m_pixels[i][j]->green);
			printf("%d,", pixel->m_pixels[i][j]->blue);
			printf("%d| ", pixel->m_pixels[i][j]->alpha);
			j++;
		}
		printf("\n");
		i++;
	}
//	printf("%d\n", map->tmp_color[0]);
//	printf("%d\n", map->tmp_color[1]);
//	printf("%d\n", map->tmp_color[2]);
//	printf("%d\n", map->tmp_color[3]);
	printf("|%d,", pixel->m_pixels[0][0]->red);
	printf("|%d,", pixel->m_pixels[0][0]->green);
	printf("|%d,", pixel->m_pixels[0][0]->blue);
	printf("|%d,", pixel->m_pixels[0][0]->alpha);
}
#include "fdf.h"

/*
** Allocates memory for the array of struct.
*/
void	mal_pixel(t_map *map, t_mlx *pixel)
{
	int		i;
	int 	j;

	i = 0;
	j = 0;
	pixel->m_pixels = (t_pixel***)malloc(sizeof(t_pixel**) * map->map_y);
	if (pixel->m_pixels == NULL)
		fdf_error(MALLCHECK);
	while (i <= map->map_y)
	{
		pixel->m_pixels[i] = (t_pixel**)malloc(sizeof(t_pixel*) * map->map_x);
		if (pixel->m_pixels[i] == NULL)
			fdf_error(MALLCHECK);
		while (j <= map->map_x)
		{
			pixel->m_pixels[i][j] = (t_pixel*)malloc(sizeof(t_pixel));
			if (pixel->m_pixels[i][j] == NULL)
				fdf_error(MALLCHECK);
			j++;
		}
		i++;
	}
}

void	atoi_pixel(t_map *map, t_mlx *pixel)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (map->line[i])
	{
		i = k;
		while (ft_isdigit(map->line[k]) == 1)
		{
			k++;
		}
		if (map->line[i] != ' ' &&
				(map->line[i + 1] == ' ' || map->line[i + 1] == '\0'))
		{
			map->map_x++;
		}
		i++;
	}
}

void	handle_pixel(t_map *map, t_mlx *pixel)
{
	map->map_y = 0;
	map->fd = open(map->name[1], O_RDONLY);
	while (get_next_line(map->fd, &map->line) == 1)
	{
		atoi_pixel(map, pixel);
		free(map->line);
		map->map_y++;
	}
	if ((close(map->fd)) == -1)
		fdf_error(LINE);
}

void	fdf_coordinates(t_map *map, t_mlx *pixel)
{
	mal_pixel(map, pixel);
	handle_pixel(map, pixel);
}
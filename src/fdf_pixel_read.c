#include "fdf.h"


void	set_color(t_map *map, t_mlx *pixel, int i)
{
	pixel->m_pixels[map->c][map->r]->red = map->tmp_color[i];
	pixel->m_pixels[map->c][map->r]->green = map->tmp_color[i + 1];
	pixel->m_pixels[map->c][map->r]->blue = map->tmp_color[i + 2];
	pixel->m_pixels[map->c][map->r]->alpha = map->tmp_color[i + 3];
}

void	pixel_write_support(t_map *map, t_mlx *pixel)
{
	get_next_line(map->fd, &map->line);
	map->end = 0;
	map->i = 0;
	map->j = 0;
	map->tmp_color = (int*)malloc(sizeof(int) * (map->map_x * 4));
	map->tmp_z = (int*)malloc(sizeof(int) * map->map_x);
	if(map->tmp_z == NULL)
		fdf_error(MALLCHECK);
	map->ctrl = 0;
}

void	fdf_pixel_write(t_map *map, t_mlx *pixel)
{
	int i;

	map->c = 0;
	while (map->c < map->map_y)
	{
		i = 0;
		map->r = 0;
//		pixel->m_pixels[map->c][map->r]->y = map->c;
		pixel_write_support(map, pixel);
		while (map->r < map->map_x)
		{
			pixel->m_pixels[map->c][map->r]->x = map->r * 20;
			pixel->m_pixels[map->c][map->r]->y = map->c * 20;
			fdf_pixel_color_z(map, pixel);
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

void	fdf_pixel_read(t_map *map, t_mlx *pixel)
{
	map->tmp = 0;
	fdf_pixel_malloc(map, pixel);
	map->fd = open(map->name[1], O_RDONLY);
	fdf_pixel_write(map, pixel);
	if ((close(map->fd)) == -1)
		fdf_error(LINE);


	int i, j;
	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			printf("%.0f ", pixel->m_pixels[i][j]->x);
			printf("%.0f |", pixel->m_pixels[i][j]->y);
//			printf("|%d,", pixel->m_pixels[i][j]->red);
//			printf("%d,", pixel->m_pixels[i][j]->green);
//			printf("%d,", pixel->m_pixels[i][j]->blue);
//			printf("%d| ", pixel->m_pixels[i][j]->alpha);
			j++;
		}
		printf("\n");
		i++;
	}
//	printf("%d\n", map->tmp_color[0]);
//	printf("%d\n", map->tmp_color[1]);
//	printf("%d\n", map->tmp_color[2]);
//	printf("%d\n", map->tmp_color[3]);
//	printf("|%d,", pixel->m_pixels[0][0]->red);
//	printf("|%d,", pixel->m_pixels[0][0]->green);
//	printf("|%d,", pixel->m_pixels[0][0]->blue);
//	printf("|%d,", pixel->m_pixels[0][0]->alpha);
}
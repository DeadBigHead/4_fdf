#include "fdf.h"

int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	mlx;

	if (ac == 2)
	{
		map.name = av;
		fdf_validate(&map);
		fdf_pixel_read(&map, &mlx);
		fdf_my_color(&map, &mlx);
		fdf_win_setup(&mlx);
		fdf_mlx_init(&mlx);
		fdf_first_draw(&mlx, &map);
		mlx.zoom = 5;
		int c;
		int r;
		printf("%d, %d\n", mlx.xcen, mlx.ycen);
		c = 0;
		while (c < mlx.map_y)
		{
			r = 0;
			while (r < mlx.map_x)
			{
				printf("|%f, ", mlx.m_pixels[c][r]->x);
				printf("%f, ", mlx.m_pixels[c][r]->y);
				printf("%f| ", mlx.m_pixels[c][r]->z);
				r++;
			}
			printf("\n");
			c++;
		}
		printf("\n");
		mlx_hook (mlx.win, 2, 5, &fdf_key_core, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		fdf_error(USAGE);
}

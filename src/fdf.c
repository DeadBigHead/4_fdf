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
		mlx.map_x = map.map_x;
		mlx.map_y = map.map_y;
		if (mlx.map_x && mlx.map_y < 400)
			fdf_zoom_auto_plus(&mlx);
		else if (mlx.map_x && mlx.map_y > 400)
			fdf_zoom_auto_minus(&mlx);
		fdf_first_draw(&mlx, &map);
		mlx.zoom = 0;
		mlx.bound = 15000;
		mlx.name = map.name;
		fdf_ui(&mlx);
		mlx_hook (mlx.win, 2, 5, &fdf_key_core, &mlx);
		mlx_loop(mlx.ptr);
	}
	else
		fdf_error(USAGE);
}

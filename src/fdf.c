#include "fdf.h"

void	mlx_stuff(t_mlx	*data)
{

	data->mlx_img = mlx_new_image(data->mlx_ptr, 640, 480);
	data->mlx_str = mlx_get_data_addr(data->mlx_img, data->bits, int *size_line, int *endian );
}
http://files.achedeuzot.me/42/mlx/man/
int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	pixel;
	t_mlx	data;

	if (ac == 2)
	{
		map.name = av;
		fdf_validate(&map);
		fdf_pixel_read(&map, &pixel);
		mlx_stuff(&data);
		fdf_draw(&map, &pixel);

		if ((data->mlx_ptr = mlx_init()) == NULL)
			exit (0);
		if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 640, 480, "He")) == NULL)
			exit (0);
		mlx_loop(data->mlx_ptr);

//		printf("map_x - %zu\n", map.map_x);
//		printf("map_y - %zu\n", map.map_y);
	}
	else
		fdf_error(USAGE);
//	t_mlx	data;
//	int		x;
//	int		y;
//
//	if ((data.mlx_ptr = mlx_init()) == NULL)
//		return (EXIT_FAILURE);
//	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, 640, 480, "Hello world")) == NULL)
//		return (EXIT_FAILURE);
//	y = 50;
//	while(y<200)
//	{
//		x = 50;
//		while(x<150)
//		{
//			mlx_pixel_put(data.mlx_ptr, data.mlx_win, x, y, 0x00FFFFFF);
//			x++;
//		}
//		y++;
//	}
//	mlx_loop(data.mlx_ptr);
//	return (EXIT_SUCCESS);
}

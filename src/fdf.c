#include "fdf.h"

//void	mlx_stuff(t_mlx	*data)
//{
//	if ((data->mlx_ptr = mlx_init()) == NULL)
//		exit (0);
//	if ((data->mlx_win = mlx_new_window(data->mlx_ptr, 640, 480, "He")) == NULL)
//		exit (0);
//	data->mlx_img = mlx_new_image(data->mlx_ptr, 640, 480);
//	data->mlx_str = mlx_get_data_addr(data->mlx_img, data->bits, data->size_line, data->endian);
//}

int		main(int ac, char **av)
{
	t_map	map;
	t_mlx	pixel;
//	t_mlx	data;

	if (ac == 2)
	{
		map.name = av;
		fdf_validate(&map);
		fdf_pixel_read(&map, &pixel);
		fdf_my_color(&map, &pixel);

		pixel.mlx_ptr = mlx_init();
		pixel.mlx_img = mlx_new_image(pixel.mlx_ptr, 900, 900);
		pixel.mlx_str = mlx_get_data_addr(pixel.mlx_img, &(pixel.bits), &(pixel.size_line), &(pixel.endian));
//
////		mlx_stuff(&data);
//
		pixel.map_x = map.map_x;
		pixel.map_y = map.map_y;
		pixel.total_size = 900 * 900 * 4;
//		pixel.total_size = pixel.size_line * pixel.map_x *
//				pixel.map_y * (pixel.bits);
		fdf_draw(&pixel);

//		int i = 0;
//		while (i < 300 || pixel.mlx_str[i] != '\0')
//		{
//			pixel.mlx_str[i] = 255;
//			pixel.mlx_str[i + 1] = 0;
//			pixel.mlx_str[i + 2] = 0;
//			pixel.mlx_str[i + 3] = 0;
//			i += pixel.bits/8;
//		}
		pixel.x = 50;
		pixel.y = 50;
		pixel.mlx_win = mlx_new_window(pixel.mlx_ptr, 900, 900, "He");
		mlx_put_image_to_window(pixel.mlx_ptr, pixel.mlx_win, pixel.mlx_img, pixel.x, pixel.y);

		mlx_hook (pixel.mlx_win, 2, 5, &fdf_key_core, &pixel);
		mlx_loop(pixel.mlx_ptr);

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

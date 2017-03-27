#include "fdf.h"

void	fdf_move(int kcode, t_mlx *data, t_map *map)
{
	if (kcode == UP)
	{
		mlx_clear_window (data->mlx_ptr, data->mlx_win);
		data->y -= 10;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, data->x, data->y);
	}
	if (kcode == DOWN)
	{
		mlx_clear_window (data->mlx_ptr, data->mlx_win);
		data->y += 10;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, data->x, data->y);
	}
	if (kcode == RIGHT)
	{
		mlx_clear_window (data->mlx_ptr, data->mlx_win);
		data->x += 10;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, data->x, data->y);
	}
	if (kcode == LEFT)
	{
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		data->x -= 10;
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, data->x, data->y);
	}
}

int		fdf_key_core(int kcode, t_mlx *data, t_map *map)
{
	if (kcode == 53)
		exit(0);
	if (kcode == UP || kcode == DOWN || kcode == LEFT || kcode == RIGHT)
		fdf_move(kcode, data, map);
	return (0);
}
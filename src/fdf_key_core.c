#include "fdf.h"

void	fdf_move(int kcode, t_mlx *data)
{
	int c;
	int r;
	if (kcode == UP)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x *= 1.1;
				r++;
			}
			c++;
		}
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
//		mlx_clear_window (data->mlx_ptr, data->mlx_win);
//		data->y -= 10;
//		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->mlx_img, data->x, data->y);
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

void	fdf_zoom(int kcode, t_mlx *data)
{
	int c;
	int r;
	if (kcode == PLUS)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x *= 1.1;
				data->m_pixels[c][r]->y *= 1.1;
				r++;
			}
			c++;
		}
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
	if (kcode == MINUS)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x *= 0.9;
				data->m_pixels[c][r]->y *= 0.9;
				r++;
			}
			c++;
		}
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
}

int		fdf_key_core(int kcode, t_mlx *data)
{
	if (kcode == 53)
		exit(0);
	if (kcode == UP || kcode == DOWN ||kcode == LEFT || kcode == RIGHT)
		fdf_move(kcode, data);
	if (kcode == PLUS || kcode == MINUS)
		fdf_zoom(kcode, data);
	return (0);
}
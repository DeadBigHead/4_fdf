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
				data->m_pixels[c][r]->y -= 10;
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
	if (kcode == DOWN)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->y += 10;
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
	if (kcode == RIGHT)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x += 10;
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
	if (kcode == LEFT)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x -= 10;
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

void	fdf_zoom(int kcode, t_mlx *data)
{
	int c;
	int r;
	fdf_center_find(data);
	if (kcode == PLUS)
	{
		c = 0;
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				int tmp1 = data->m_pixels[c][r]->x;
				int tmp2 = data->m_pixels[c][r]->y;
				if (data->m_pixels[c][r]->x < data->xcen
						&& data->m_pixels[c][r]->y < data->ycen)
				{
					data->m_pixels[c][r]->x -= 10;
					data->m_pixels[c][r]->y -= 10;
				}
				else if (data->m_pixels[c][r]->x > data->xcen
					&& data->m_pixels[c][r]->y > data->ycen)
				{
					data->m_pixels[c][r]->x += 10;
					data->m_pixels[c][r]->y += 10;
				}
				else if (data->m_pixels[c][r]->x > data->xcen
					&& data->m_pixels[c][r]->y < data->ycen)
				{
					data->m_pixels[c][r]->x += 10;
					data->m_pixels[c][r]->y -= 10;
				}
				else if (data->m_pixels[c][r]->x < data->xcen
					&& data->m_pixels[c][r]->y > data->ycen)
				{
					data->m_pixels[c][r]->x -= 10;
					data->m_pixels[c][r]->y += 10;
				}
				else if (data->m_pixels[c][r]->x == data->xcen
						&& data->m_pixels[c][r]->y < data->ycen)
					data->m_pixels[c][r]->y -= 10;
				else if (data->m_pixels[c][r]->x == data->xcen
						 && data->m_pixels[c][r]->y > data->ycen)
					data->m_pixels[c][r]->y += 10;
				else if (data->m_pixels[c][r]->y == data->ycen
						 && data->m_pixels[c][r]->x < data->xcen)
					data->m_pixels[c][r]->x -= 10;
				else if (data->m_pixels[c][r]->y == data->ycen
						 && data->m_pixels[c][r]->x > data->xcen)
					data->m_pixels[c][r]->x += 10;
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
		r = 0;
		if (data->m_pixels[c][r]->x < (data->xcen - 20)
				|| data->m_pixels[c][r]->x < (data->xcen - 20))
		{
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				if (data->m_pixels[c][r]->x < data->xcen
					&& data->m_pixels[c][r]->y < data->ycen)
				{
					data->m_pixels[c][r]->x += 10;
					data->m_pixels[c][r]->y += 10;
				} else if (data->m_pixels[c][r]->x > data->xcen
						   && data->m_pixels[c][r]->y > data->ycen)
				{
					data->m_pixels[c][r]->x -= 10;
					data->m_pixels[c][r]->y -= 10;
				} else if (data->m_pixels[c][r]->x > data->xcen
						   && data->m_pixels[c][r]->y < data->ycen)
				{
					data->m_pixels[c][r]->x -= 10;
					data->m_pixels[c][r]->y += 10;
				} else if (data->m_pixels[c][r]->x < data->xcen
						   && data->m_pixels[c][r]->y > data->ycen)
				{
					data->m_pixels[c][r]->x += 10;
					data->m_pixels[c][r]->y -= 10;
				}
				else if (data->m_pixels[c][r]->x == data->xcen
						   && data->m_pixels[c][r]->y < data->ycen)
					data->m_pixels[c][r]->y += 10;
				else if (data->m_pixels[c][r]->x == data->xcen
						 && data->m_pixels[c][r]->y > data->ycen)
					data->m_pixels[c][r]->y -= 10;
				else if (data->m_pixels[c][r]->y == data->ycen
						 && data->m_pixels[c][r]->x < data->xcen)
					data->m_pixels[c][r]->x += 10;
				else if (data->m_pixels[c][r]->y == data->ycen
						 && data->m_pixels[c][r]->x > data->xcen)
					data->m_pixels[c][r]->x -= 10;
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
}

int		fdf_key_core(int kcode, t_mlx *data)
{
	if (kcode == 53)
		exit(0);
	if (kcode == UP || kcode == DOWN ||kcode == LEFT || kcode == RIGHT)
		fdf_move(kcode, data);
	if (kcode == PLUS || kcode == MINUS)
		fdf_zoom(kcode, data);
	if (kcode == QKEY || kcode == WKEY)
		fdf_rotate(kcode, data);
	return (0);
}
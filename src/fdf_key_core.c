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
		data->wycur -= 10;
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
		data->wycur += 10;
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
		data->wxcur += 10;
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
		data->wxcur -= 10;
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
	int tmpx;
	int tmpy;
	fdf_center_find(data);
	if (kcode == PLUS)
	{
		c = 0;
		r = 0;
		if ((data->xcen - data->m_pixels[c][r]->x) < data->width * 20)
		{
			tmpx = data->wxcur;
			tmpy = data->wycur;
			fdf_center_zero(data);
			while (c < data->map_y)
			{
				r = 0;
				while (r < data->map_x)
				{
					data->m_pixels[c][r]->x *= 1.1;
					data->m_pixels[c][r]->y *= 1.1;
					data->m_pixels[c][r]->z *= 1.1;
					r++;
				}
				c++;
			}
			data->zoom++;
			mlx_clear_window(data->mlx_ptr, data->mlx_win);
			ft_bzero(data->mlx_str, data->total_size);
			data->wxcur = tmpx;
			data->wycur = tmpy;
			fdf_center_find(data);
			fdf_center_current(data);
			fdf_draw(data);
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
									data->mlx_img, data->x, data->y);
		}
	}
	if (kcode == MINUS)
	{
		c = 0;
		r = 0;
		if ((data->xcen - data->m_pixels[c][r]->x) > data->width * 0.01)
//		if (data->m_pixels[c][r]->x < (data->xcen - 10)
//				|| data->m_pixels[c][r]->y < (data->ycen - 10))
		{
			tmpx = data->wxcur;
			tmpy = data->wycur;
			fdf_center_zero(data);
		while (c < data->map_y)
		{
			r = 0;
			while (r < data->map_x)
			{
				data->m_pixels[c][r]->x *= 0.9;
				data->m_pixels[c][r]->y *= 0.9;
				data->m_pixels[c][r]->z *= 0.9;
				r++;
			}
			c++;
		}
			data->zoom--;
			mlx_clear_window(data->mlx_ptr, data->mlx_win);
			ft_bzero(data->mlx_str, data->total_size);
			data->wxcur = tmpx;
			data->wycur = tmpy;
			fdf_center_find(data);
			fdf_center_current(data);
			fdf_draw(data);
			mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
	}
}

void	fdf_rotate(int kcode, t_mlx *data)
{
	float tmpy;
	float tmpz;
	float tmpx;
	double r_plus = DTR(DEGREE);
	double r_minus = -DTR(DEGREE);

	if (kcode == QKEY)
	{
		data->c = 0;
		while (data->c < data->map_y)
		{
			data->r = 0;
			while (data->r < data->map_x)
			{
				tmpy = data->m_pixels[data->c][data->r]->y;
				tmpz = data->m_pixels[data->c][data->r]->z;
				data->m_pixels[data->c][data->r]->y =
						tmpy * cos(r_plus) + tmpz * sin(r_plus);
				data->m_pixels[data->c][data->r]->z =
						tmpz * cos(r_plus) - tmpy * sin(r_plus);
				data->r++;
			}
			data->c++;
		}
		fdf_center_find(data);
		fdf_center_current(data);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
	if (kcode == WKEY)
	{
		data->c = 0;
		while (data->c < data->map_y)
		{
			data->r = 0;
			while (data->r < data->map_x)
			{
				tmpy = data->m_pixels[data->c][data->r]->y;
				tmpz = data->m_pixels[data->c][data->r]->z;
				data->m_pixels[data->c][data->r]->y =
						tmpy * cos(r_minus) + tmpz * sin(r_minus);
				data->m_pixels[data->c][data->r]->z =
						tmpz * cos(r_minus) - tmpy * sin(r_minus);
				data->r++;
			}
			data->c++;
		}
		fdf_center_find(data);
		fdf_center_current(data);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
	if (kcode == AKEY)
	{
		data->c = 0;
		while (data->c < data->map_y)
		{
			data->r = 0;
			while (data->r < data->map_x)
			{
				tmpx = data->m_pixels[data->c][data->r]->x;
				tmpz = data->m_pixels[data->c][data->r]->z;
				data->m_pixels[data->c][data->r]->x =
						tmpx * cos(r_plus) + tmpz * sin(r_plus);
				data->m_pixels[data->c][data->r]->z =
						tmpz * cos(r_plus) - tmpx * sin(r_plus);
				data->r++;
			}
			data->c++;
		}
		fdf_center_find(data);
		fdf_center_current(data);
		mlx_clear_window(data->mlx_ptr, data->mlx_win);
		ft_bzero(data->mlx_str, data->total_size);
		fdf_draw(data);
		mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
								data->mlx_img, data->x, data->y);
	}
	if (kcode == SKEY)
	{
		data->c = 0;
		while (data->c < data->map_y)
		{
			data->r = 0;
			while (data->r < data->map_x)
			{
				tmpx = data->m_pixels[data->c][data->r]->x;
				tmpz = data->m_pixels[data->c][data->r]->z;
				data->m_pixels[data->c][data->r]->x =
						tmpx * cos(r_minus) + tmpz * sin(r_minus);
				data->m_pixels[data->c][data->r]->z =
						tmpz * cos(r_minus) - tmpx * sin(r_minus);
				data->r++;
			}
			data->c++;
		}
		fdf_center_find(data);
		fdf_center_current(data);
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
	if (kcode == QKEY || kcode == WKEY
			|| kcode == AKEY || kcode == SKEY
			|| kcode == ZKEY || kcode == XKEY)
		fdf_rotate(kcode, data);
	return (0);
}
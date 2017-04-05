#include "fdf.h"

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
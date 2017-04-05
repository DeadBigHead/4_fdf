#include "fdf.h"

void	fdf_rotate(int kcode, t_mlx *mlx)
{
	if (kcode == QKEY || kcode == WKEY)
		fdf_rotate_x(kcode, mlx);
	if (kcode == AKEY || kcode == SKEY)
		fdf_rotate_y(kcode, mlx);
	if (kcode == ZKEY || kcode == XKEY)
		fdf_rotate_z(kcode, mlx);
}
#include "fdf.h"

void	fdf_ui(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr , mlx->win, 20, 740, 0x00FFFFFF, "Controls:");
	mlx_string_put(mlx->ptr , mlx->win, 20, 760, 0x00FFFFFF, "Exit: ESC");
	mlx_string_put(mlx->ptr , mlx->win, 20, 780, 0x00FFFFFF,
				   "Move: arrow keys");
	mlx_string_put(mlx->ptr , mlx->win, 20, 800, 0x00FFFFFF,
				   "Zoom in/out: +/-");
	mlx_string_put(mlx->ptr , mlx->win, 20, 820, 0x00FFFFFF,
				   "Rotate along X axis: Q/W");
	mlx_string_put(mlx->ptr , mlx->win, 20, 840, 0x00FFFFFF,
				   "Rotate along Y axis: A/S");
	mlx_string_put(mlx->ptr , mlx->win, 20, 860, 0x00FFFFFF,
				   "Rotate along Z axis: Z/X");
}
#include "fdf.h"

/*
** fdf_win_setup
** Initializes window height and width, center of the window,
** and current center position.
*/
void	fdf_win_setup(t_mlx *mlx)
{
	mlx->width = WIDTH;
	mlx->height = HEIGHT;
	mlx->wcenx = mlx->width / 2;
	mlx->wceny = mlx->height / 2;
	mlx->wxcur = mlx->wcenx;
	mlx->wycur = mlx->wceny;
}
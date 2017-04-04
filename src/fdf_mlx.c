#include "fdf.h"

/*
** Initial draw of the image.
*/
void	fdf_first_draw(t_mlx *mlx, t_map *map)
{
	int	 h;
	int	 w;
	int	 tmp;

	h = mlx->height;
	w = mlx->width;
	mlx->map_x = map->map_x;
	mlx->map_y = map->map_y;
	mlx->total_size = WIDTH * HEIGHT * 4;
	fdf_center_find(mlx);
	fdf_center_place(mlx);
	fdf_draw(mlx);
	mlx->win = mlx_new_window(mlx->ptr, h, w, "FdF");
	if (mlx->win == NULL)
		exit (0);
	mlx->imgx = 0;
	mlx->imgy = 0;
	tmp = mlx_put_image_to_window(mlx->ptr, mlx->win,
								  mlx->img, mlx->imgx, mlx->imgy);
	if (tmp < 0)
		exit (0);
}

/*
** Initial setup for the minilibx
*/
void	fdf_mlx_init(t_mlx	*mlx)
{
	int h;
	int w;

	h = mlx->height;
	w = mlx->width;
	mlx->ptr = mlx_init();
	if (mlx->ptr == NULL)
		exit (0);
	mlx->img = mlx_new_image(mlx->ptr, h, w);
	if (mlx->img  == NULL)
		exit (0);
	mlx->str = mlx_get_data_addr(mlx->img, &mlx->bit, &mlx->line_sz, &mlx->end);
	if (mlx->str  == NULL)
		exit (0);
}
#include "fdf.h"

void	fdf_redraw_zoom(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_bzero(mlx->str, mlx->total_size);
	fdf_center_find(mlx);
	fdf_center_current(mlx);
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);

//	fdf_center_find(data);
//	fdf_center_current(data);
//	mlx_clear_window(data->mlx_ptr, data->mlx_win);
//	ft_bzero(data->mlx_str, data->total_size);
//	fdf_draw(data);
//	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win,
//							data->mlx_img, data->x, data->y);
}

void	fdf_redraw(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	ft_bzero(mlx->str, mlx->total_size);
	fdf_draw(mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
}

/*
** Initial draw of the image.
*/
void	fdf_first_draw(t_mlx *mlx, t_map *map)
{
	int	 h;
	int	 w;

	h = mlx->height;
	w = mlx->width;
	mlx->map_x = map->map_x;
	mlx->map_y = map->map_y;
	mlx->total_size = WIDTH * HEIGHT * 4;
	fdf_center_find(mlx);
	fdf_center_place(mlx);
	fdf_draw(mlx);
	mlx->win = mlx_new_window(mlx->ptr, w, h, "FdF");
	if (mlx->win == NULL)
		exit (0);
	mlx->imgx = 0;
	mlx->imgy = 0;
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, mlx->imgx, mlx->imgy);
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
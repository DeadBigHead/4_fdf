/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/13 17:08:29 by mvlad             #+#    #+#             */
/*   Updated: 2017/03/13 17:08:33 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <mlx.h>
# include "libft.h"
# include "get_next_line.h"

typedef unsigned int	t_ui;
typedef unsigned char	t_ch;

# define USAGE 1
# define LINE 2
# define COLOR 3
# define MALLCHECK 4
# define FCLOSE 5
# define TRUE 1
# define FALSE -1

/*
** Single pixel data.
*/
typedef struct			s_pixel
{
	float				x;
	float				y;
	float				z;
	t_ch				red;
	t_ch				green;
	t_ch				blue;
	t_ch				alpha;
}						t_pixel;

typedef struct			s_mlx
{
	struct s_pixel		***m_pixels;
	void				*mlx_ptr;
	void				*mlx_win;
}						t_mlx;

typedef struct			s_map
{
	int 				fd;
	int 				c;
	int 				r;
	int 				*tmp_z;
	int 				*tmp_color;
	int 				end;
	int 				beg;
	int 				i;
	size_t				map_x;
	size_t				tmp_x;
	size_t				map_y;
	char 				*line;
	char 				**name;
}						t_map;

void					fdf_error(int n);
void					fdf_validate(t_map *map);
void					fdf_coordinates(t_map *map, t_mlx *pixel);
void					fdf_mal_pix(t_map *map, t_mlx *pixel);
void					fdf_set_color(t_map *map, t_mlx *pixel);
int						ft_ishex(char c);
int						fdf_atoi_hex(char *s);
#endif

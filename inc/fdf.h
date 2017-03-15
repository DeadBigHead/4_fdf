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

# define USAGE 1
# define LINE 2
# define COLOR 3
# define TRUE 1
# define FALSE -1

typedef struct			s_pixel
{
	float				x;
	float				y;
	float				z;
	t_ui				red;
	t_ui				green;
	t_ui				blue;
	t_ui				alpha;
}						t_pixel;

typedef struct			s_mlx
{
	struct s_pixel		***m_pixels;
	void				*mlx_ptr;
	void				*mlx_win;
}						t_mlx;

void					fdf_error(int n);
void					fdf_validate(char *s);
#endif

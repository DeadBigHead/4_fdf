/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error_sup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:25:36 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 18:04:51 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** fdf_close_file
** Closes the file, and checks for the errors.
*/

void	fdf_close_file(t_map *map)
{
	if ((close(map->fd)) < 0)
		fdf_error(FCLOSE);
}

/*
** fdf_close_line
** Closes the file on the line error, and checks for the errors.
*/

void	fdf_close_line(t_map *map)
{
	if (map->tmp < map->map_x)
	{
		fdf_close_file(map);
		fdf_error(LINE);
	}
}

/*
** fdf_open_file
** Opens the file, and checks for the errors.
*/

void	fdf_open_file(t_map *map)
{
	map->fd = open(map->name[1], O_RDONLY);
	if (map->fd < 0)
		fdf_error(FOPEN);
}

/*
** fdf_gnl_error
** Checks for the GNL errors.
*/

void	fdf_gnl_error(t_map *map, int i)
{
	if (i < 0)
	{
		fdf_close_file(map);
		fdf_error(GNL);
	}
}

/*
** fdf_gnl_error
** Errors for the number of the sequential symbols.
*/

void	fdf_nbr_error(t_map *map, size_t i)
{
	if (i == 0)
	{
		fdf_close_file(map);
		fdf_error(ZERO);
	}
	else if (map->map_x == 1 && map->map_y < 2)
	{
		fdf_close_file(map);
		fdf_error(OONE);
	}
	else if (map->map_x < 2 || map->map_y < 2)
	{
		fdf_close_file(map);
		fdf_error(OONE);
	}
	else if (map->map_x >= 600 || map->map_y >= 600)
	{
		fdf_close_file(map);
		fdf_error(BIG);
	}
}

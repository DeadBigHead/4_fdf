#include "fdf.h"

/*
** count_symbols
** Counts number of sequential symbols delimited by spaces.
*/
size_t	count_symbols(t_map *map)
{
	char 	*s;
	size_t	i;
	size_t	nbr;

	i = 0;
	nbr = 0;
	s = map->line;
	while (s[i])
	{
		if(s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

/*
** fdf_validate
** Validation:
** Compares the number of sequential symbols from the first line
** of the given file with the sequential number of symbols from the other lines.
** If the first line has a lesser amount of numbers than the other lines,
** the program terminates.
** Errors:
** During the validation checks for the ongoing read errors.
** And checks the number of the given sequential symbols.
** If the number is less than or equal to 1 the program terminates.
*/
void	fdf_validate(t_map *map)
{
	int i;

	map->map_x = 0;
	map->map_y = 0;
	fdf_open_file(map);
	while ((i = get_next_line(map->fd, &map->line)) == 1)
	{
		if (map->map_x == 0)
		{
			map->map_x = count_symbols(map);
//			fdf_nbr_error(map, map->map_x);
			free(map->line);
			map->map_y++;
			continue;
		}
		map->tmp = count_symbols(map);
		free(map->line);
		map->map_y++;
		fdf_close_line(map);
	}
	fdf_gnl_error(map, i);
	fdf_nbr_error(map, map->map_x);
	fdf_close_file(map);
}
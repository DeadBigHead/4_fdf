#include "fdf.h"

/*
** counts number of sequential symbols delimited by spaces
*/
size_t	count_digits(char *s)
{
	size_t	nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if(s[i] != ' ' && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

/*
** counts and validates number of sequential symbols in map
*/
void	fdf_read(t_map *map)
{
	map->fd = open(map->name[1], O_RDONLY);
	while (get_next_line(map->fd, &map->line) == 1)
	{
		if (map->map_x == 0)
		{
			map->map_x = count_digits(map->line);
			free(map->line);
			map->map_y++;
			continue;
		}
		map->tmp_x = count_digits(map->line);
		free(map->line);
		map->map_y++;
		if (map->tmp_x < map->map_x)
		{
			close(map->fd);
			fdf_error(LINE);
		}
	}
	close(map->fd);
}

void	fdf_validate(t_map *map)
{
	map->map_x = 0;
	fdf_read(map);
}
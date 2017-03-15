#include "fdf.h"

size_t	count_lines(char *s)
{
	int		fd;
	char	*line;
	size_t	nbr;

	nbr = 0;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		nbr++;
		free(line);
	}
	close(fd);
	return (nbr);
}

size_t	count_digits(char *s)
{
	size_t	nbr;
	size_t	i;

	i = 0;
	nbr = 0;
	while (s[i])
	{
		if(ft_isdigit(s[i]) && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			nbr++;
		i++;
	}
	return (nbr);
}

size_t	fdf_read(char *s)
{
	int		fd;
	char	*line;
	size_t 	nbr;
	size_t	nbr2;

	nbr = 0;
	fd = open(s, O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (nbr == 0)
		{
			nbr = count_digits(line);
			free(line);
			continue;
		}
		nbr2 = count_digits(line);
		free(line);
		if (nbr2 < nbr)
		{
			close(fd);
			fdf_error(LINE);
		}
	}
	close(fd);
	return (nbr);
}

void	fdf_validate(char *s)
{
	size_t	lines_nbr;
	size_t	len;

	lines_nbr = count_lines(s);
	len = fdf_read(s);
	printf("len - %zu\n", len);
	printf("lines_nbr - %zu\n", lines_nbr);
}
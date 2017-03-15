#include "fdf.h"

void	fdf_error(int n)
{
	char	*use;

	if (n == USAGE)
	{
		use = "Usage: ./fdf <filename>\n";
		write(1, use, ft_strlen(use));
		exit(0);
	}
	else if (n == LINE)
	{
		use = "Error: one or more lines have wrong length. Exiting.\n";
		write(1, use, ft_strlen(use));
		exit(0);
	}
	else if (n == COLOR)
	{
		use = "Error: wrong color format. Exiting.\n";
		write(1, use, ft_strlen(use));
		exit(0);
	}
}
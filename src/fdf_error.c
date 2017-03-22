#include "fdf.h"

/*
** error_exit
** Outputs taken argument string, to the standard output.
** And terminates the program.
*/
void	error_exit(char *s)
{
	char	*use;

	use = s;
	write(1, use, ft_strlen(use));
	exit(0);
}

/*
** fdf_error
** Takes an typedef int and sends the corresponding error line to error_exit.
*/
void	fdf_error(int n)
{
	if (n == USAGE)
		error_exit("Usage: ./fdf <filename>\n");
	if (n == LINE)
		error_exit("Error: One or more lines have wrong length. Exiting.\n");
	if (n == COLOR)
		error_exit("Error: Wrong color format. Exiting.\n");
	if (n == MALLCHECK)
		error_exit("Error: Malloc allocation fail. Exiting.\n");
	if (n == FCLOSE)
		error_exit("Error: File close fail. Exiting.\n");
	if (n == FOPEN)
		error_exit("Error: File open fail. Exiting.\n");
	if (n == GNL)
		error_exit("Error: GNL fail. Exiting.\n");
	if (n == ZERO)
		error_exit("Error: There is ZERO values. Exiting.\n");
	if (n == OONE)
		error_exit("Error: There is only ONE value. Exiting.\n");
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvlad <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 17:25:17 by mvlad             #+#    #+#             */
/*   Updated: 2017/04/10 17:47:26 by mvlad            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** error_exit
** Outputs taken argument string, to the standard output.
** And terminates the program.
*/

static void		error_exit(char *s)
{
	char			*use;

	use = s;
	write(1, use, ft_strlen(use));
	exit(0);
}

/*
** fdf_error
** Takes an typedef int and sends the corresponding error line to error_exit.
*/

void			fdf_error(int n)
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
		error_exit("Error: Bad map. Exiting.\n");
	if (n == BIG)
		error_exit("Error: Map is too big. Exiting.\n");
}

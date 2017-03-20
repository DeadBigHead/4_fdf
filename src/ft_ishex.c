#include "fdf.h"

int	ft_ishex(char c)
{
	if (((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		|| (ft_isdigit(c) == 1))
		return (1);
	return (0);
}
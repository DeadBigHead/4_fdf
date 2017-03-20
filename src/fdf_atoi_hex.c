#include "fdf.h"

int fdf_atoi_hex(char *s)
{
	int        i;
	int        nbr;

	i = 0;
	nbr = 0;
	while (s[i] != '\0')
	{
		if (ft_isdigit(s[i]) == 1)
		{
			nbr = nbr * 16 + (s[i] - '0');
		}
		else
		{
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] -= 32;
			nbr = nbr * 16 + (s[i] - 'A' + 10);
		}
		i++;
	}
	return (nbr);
}
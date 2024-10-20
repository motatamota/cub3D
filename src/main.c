#include "cub3d.h"

int	isargumentserror(int ac, char **av)
{
	if (isargcerror(ac, av) || isfilenameerror(ac, av) || isfileopenerror(ac, av))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (isargumentserror(ac, av))
		return (1);
}

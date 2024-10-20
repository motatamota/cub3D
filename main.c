#include "cub3d.h"

int	isargumentserror(int ac, char **av)
{
	int	fd;

	if (ac != 2)
	{
		printf("Error\nCheck arguments.\n");
		return (1);
	}
	fd = open(*(av + 1), O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCant open this file.\n");
		return (1);
	}
	close(fd);
	return (0);
}

int	main(int ac, char **av)
{
	if (isargumentserror(ac, av))
		return (1);
}

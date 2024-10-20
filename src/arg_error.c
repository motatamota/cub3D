#include "cub3d.h"

int	isargcerror(int ac, char **av)
{
	if (ac != 2)
	{
		printf("Error\nCheck arguments.\n");
		return (1);
	}
}

int	isfilenameerror(int ac, char **av)
{
	if ()
}

int	isfileopenerror(int ac, char **av)
{
	int	fd;

	fd = open(*(av + 1), O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCant open this file.\n");
		return (1);
	}
	close(fd);
}

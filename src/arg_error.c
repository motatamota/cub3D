/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:05 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:05 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	isargcerror(int ac)
{
	if (ac != 2)
	{
		printf("Error\nToo many or no arguments.\n");
		return (1);
	}
	return (0);
}

int	isfilenameerror(char **av)
{
	if (ft_strcmp(*(av + 1) + ft_strlen(*(av + 1)) - 4, ".cub"))
	{
		printf("Error\nFile name is not correct. (***.cub)\n");
		return (1);
	}
	return (0);
}

int	isfileopenerror(char **av)
{
	int	fd;

	fd = open(*(av + 1), O_RDONLY);
	if (fd == -1)
	{
		printf("Error\nCant open this file.\n");
		return (1);
	}
	close(fd);
	return (0);
}
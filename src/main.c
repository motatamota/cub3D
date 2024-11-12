/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:08 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:08 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	isargumentserror(int ac, char **av)
{
	if (isargcerror(ac) || isfilenameerror(av) || isfileopenerror(av))
		return (1);
	return (0);
}

void	format_gnl(char *str)
{
	while (*str)
		str++;
	if (*(str - 1) == '\n')
		*(str - 1) = '\0';
}

void	testerprint(t_cub3d *viw)
{
	printf("%s\n%s\n%s\n%s\n%d\n%d\n%d\n%d\n%d\n%d\n", viw->north.path, viw->south.path, viw->west.path, viw->east.path, viw->floor.red, viw->floor.green, viw->floor.blue, viw->ceiling.red, viw->ceiling.green, viw->ceiling.blue);
}

int	main(int ac, char **av)
{
	t_cub3d		viw;
	t_data		img;

	(void)ac;
	(void)av;
	// if (isargumentserror(ac, av))
	// 	return (1);
	viw.mlx = mlx_init();
	viw.win = mlx_new_window(viw.mlx, Y_SIZE, X_SIZE, "cub3D");
	img.img = mlx_new_image(viw.mlx, Y_SIZE, X_SIZE);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	viw.img = &img;
	cub3d(&viw, *(av + 1));
	testerprint(&viw);
	mlx_put_image_to_window(viw.mlx, viw.win, img.img, 0, 0);
	mlx_loop(viw.mlx);
	return (0);
}

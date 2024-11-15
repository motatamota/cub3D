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

int	main(int ac, char **av)
{
	int map1[]={1, 1, 1, 1, 1, 1};
	int	map2[]={1, 0, 0, 0, 0, 1};
	int map3[]={1, 1, 0, 1, 0, 1};
	int map4[]={1, 0, 0, 0, 0, 1};
	int map5[]={1, 1, 0, 0, 0, 1};
	int map6[]={1, 1, 1, 1, 1, 1};
	int *map[]={map1,map2,map3,map4,map5,map6};
	t_cub3d		viw;

	if (isargumentserror(ac, av))
		return (1);
	viw.mlx = mlx_init();
	viw.win = mlx_new_window(viw.mlx, X_SIZE, Y_SIZE, "cub3D");
	viw.img.img = mlx_new_image(viw.mlx, X_SIZE, Y_SIZE);
	viw.frame_height = Y_SIZE;
	viw.frame_width = X_SIZE;
	viw.man.pos_x = 3.5;
	viw.man.pos_y = 3.5;
	viw.man.pos_z = 0.5;
	viw.man.angle_h = 150;
	viw.frame_height = Y_SIZE;
	viw.frame_width = X_SIZE;
	viw.fov = FOV;
	viw.map = map;
	viw.const_fov = (double)viw.fov / 1920 * 1080;
	viw.img.addr = mlx_get_data_addr(viw.img.img, &viw.img.bits_per_pixel,
			&viw.img.line_length, &viw.img.endian);
	cub3d(&viw, *(av + 1));
	mlx_loop(viw.mlx);
	return (0);
}

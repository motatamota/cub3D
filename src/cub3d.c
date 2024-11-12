/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 23:07:08 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 23:07:08 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	push_ESC(t_cub3d *viw)
{
	mlx_destroy_window(viw->mlx, viw->win);
	exit(0);
}

int	keymove(int keycode, t_cub3d *viw)
{
	if (keycode == KEY_W)
		push_W(viw);
	else if (keycode == KEY_A)
		push_A(viw);
	else if (keycode == KEY_S)
		push_S(viw);
	else if (keycode == KEY_D)
		push_D(viw);
	else if (keycode == KEY_L)
		push_L(viw);
	else if (keycode == KEY_R)
		push_R(viw);
	else if (keycode == KEY_ESC)
		push_ESC(viw);
	return (0);
}

int	breakwin(void)
{
	exit(0);
	return (1);
}

void	initialimg(t_cub3d *viw)
{
	int	width;
	int	height;

	viw->img->img = mlx_xpm_file_to_image(viw->mlx, "image/north.xpm", &width, &height);
	printf("tset%d, %d\n", width, height);
	mlx_put_image_to_window(viw->mlx, viw->win, viw->img->img, 50, 100);
}

void	cub3d(t_cub3d *viw)
{
	initialimg(viw);
	mlx_hook(viw->win, 2, 1L << 0, keymove, viw);
	mlx_hook(viw->win, 17, 0, breakwin, NULL);
}

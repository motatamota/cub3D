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

void	push_esc(t_cub3d *viw)
{
	mlx_destroy_window(viw->mlx, viw->win);
	exit(0);
}

int	breakwin(void)
{
	exit(0);
	return (1);
}

void	cub3d(t_cub3d *viw, char *path)
{
	initialimg(viw, path);
	mlx_hook(viw->win, 2, 1L << 0, keymove, viw);
	mlx_hook(viw->win, 17, 0, breakwin, NULL);
}

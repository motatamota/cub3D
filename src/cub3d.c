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

int get_pixel_color(t_img *img, int x, int y) {
	// ピクセルが画像範囲内にあるかチェック
	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return 0; // 画像範囲外の場合は0を返す（黒など）

	// 画像のピクセル位置のアドレスを計算
	char *pixel_addr = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));

	// 色を取得
	int color = *(unsigned int *)pixel_addr;
	return color;
}

void	first_img(t_cub3d *viw)
{
	int color;
	color = get_pixel_color(&viw->north, 50, 50);
	mlx_put_image_to_window(viw->mlx, viw->win, viw->north.img, 0, 0);
}

void	cub3d(t_cub3d *viw, char *path)
{
	initialimg(viw, path);
	mlx_hook(viw->win, 2, 1L << 0, keymove, viw);
	mlx_hook(viw->win, 17, 0, breakwin, NULL);
	first_img(viw);
}

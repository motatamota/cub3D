/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 23:12:02 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/12 23:12:02 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	calcangle_v(t_cub3d *viw, int y)
{
	return (((double)viw->frame_height / 2 - y) * viw->const_fov);
}

double	calcangle_h(t_cub3d *viw, int x)
{
	return (viw->angle_h + (x - (double)viw->frame_width / 2) * viw->const_fov);
}

long	get_monitor_pixel_color(t_cub3d *viw, double angle_h, double angle_v)
{

}

long	monitor_pixelcolor(t_cub3d *viw, int x, int y)
{
	double		len;

	len = 0;
	viw->man.pos_x = 0.5;
	viw->man.pos_y = 0.5;
	viw->man.angle_h = 0;
	viw->frame_height = Y_SIZE;
	viw->frame_width = X_SIZE;
	viw->fov = FOV;
	viw->const_fov = (double)viw->fov / 1920 * 1080;
	calcangle_v(viw, x, y);
	return (get_monitor_pixel_color(viw, calcangle_v(viw, y), calcangle_h(viw, x)));
}

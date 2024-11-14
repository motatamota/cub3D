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
	return (viw->man.angle_h + (x - (double)viw->frame_width / 2) * viw->const_fov);
}

// int	mod_direction(int angle)
// {
// 	if (angle < 45 || angle >= 315)
// 		return (MOD_NORTH);
// 	if (angle >=45 && angle < 135)
// 		return (MOD_EAST);
// 	if (angle >= 135 && angle < 225)
// 		return (MOD_SOUTH);
// 	if (angle >= 225 && angle < 315)
// 		return (MOD_WEST);
// }

long	get_monitor_pixel_color(t_cub3d *viw, double angle_h, double angle_v)
{
	t_man	ray_point;

	ray_point.pos_x = viw->man.pos_x;
	ray_point.pos_y = viw->man.pos_y;
	ray_point.pos_z = viw->man.pos_z;
	if (angle_h >= 360)
		angle_h -= 360;
	ray_point.angle_h = angle_h;
	ray_point.angle_v = angle_v;
	return (g_color(viw, ray_point));
}

long	monitor_pixelcolor(t_cub3d *viw, int x, int y)
{
	viw->man.pos_x = 0.5;
	viw->man.pos_y = 0.5;
	viw->man.pos_z = 0.5;
	viw->man.angle_h = 0;
	viw->frame_height = Y_SIZE;
	viw->frame_width = X_SIZE;
	viw->fov = FOV;
	viw->const_fov = (double)viw->fov / 1920 * 1080;
	return (get_monitor_pixel_color(viw, calcangle_h(viw, x), calcangle_v(viw, y)));
}

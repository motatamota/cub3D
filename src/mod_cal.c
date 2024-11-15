/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cal.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:13:36 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/14 21:13:36 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	g_color_n_e(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	int k = 0;
	while (flag)
	{
		k++;
		if (k > 500)
			return (0);
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y) * ray.htan - (int)ray.pos_x >= 1)
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x + 1) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x + 1) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x + 1);
			flag = y_img(viw, ray, 0, &color);
		}
		else
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y;
			flag = x_img(viw, ray, 1, &color);
		}
	}
	return (color);
}

int	g_color_e_n(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x + 1 - ray.pos_x) / ray.htan <= (int)ray.pos_y)
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y;
			flag = x_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x + 1) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x + 1) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x + 1);
			flag = y_img(viw, ray, 0, &color);
		}
	}
	return (color);
}

int	g_color_e_s(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x + 1 - ray.pos_x) / ray.htan >= (int)ray.pos_y + 1)
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y + 1;
			// printf("%f, %f\n", ray.pos_x, ray.pos_y);
			flag = x_img(viw, ray, 0, &color);
		}
		else
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x + 1) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x + 1) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x + 1);
			flag = y_img(viw, ray, 0, &color);
		}
	}
	return (color);
}

int	g_color_s_e(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan - (int)ray.pos_x >= 1)
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x + 1) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x + 1) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x + 1);
			flag = y_img(viw, ray, 0, &color);
		}
		else
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y + 1;
			flag = x_img(viw, ray, 0, &color);
		}
		// printf("%f, %f\n", ray.pos_x, ray.pos_y);
	}
	return (color);
}

int	g_color(t_cub3d *viw, t_man ray)
{
	if (ray.angle_h >= 0 && ray.angle_h < M_PI / 4)
		return (g_color_n_e(viw, ray));
	if (ray.angle_h >= M_PI / 4 && ray.angle_h < M_PI / 2)
		return (g_color_e_n(viw, ray));
	if (ray.angle_h >= M_PI / 2 && ray.angle_h < M_PI * 3 / 4)
		return (g_color_e_s(viw, ray));
	if (ray.angle_h >= M_PI * 3 / 4 && ray.angle_h < M_PI)
		return (g_color_s_e(viw, ray));
	if (ray.angle_h >= M_PI && ray.angle_h < M_PI * 5 / 4)
		return (g_color_s_w(viw, ray));
	if (ray.angle_h >= M_PI * 5 / 4 && ray.angle_h < M_PI * 3 / 2)
		return (g_color_w_s(viw, ray));
	if (ray.angle_h >= M_PI * 3 / 2 && ray.angle_h < M_PI * 7 / 4)
		return (g_color_w_n(viw, ray));
	else
		return (g_color_n_w(viw, ray));
}

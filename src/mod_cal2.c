/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_cal2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 22:28:44 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/14 22:28:44 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	d_tuning(t_man *ray, int flag)
{
	if (flag == 2 || flag == 3)
	{
		ray->pos_x += 0.05 * sin(ray->angle_h);
		ray->pos_y += 0.05 * cos(ray->angle_h);
		ray->pos_z += 0.05 * sin(ray->angle_v);
	}
}

int	g_color_s_w(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan <= (int)ray.pos_x)
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y + 1;
			flag = x_img(viw, ray, 0, &color);
		}
	}
	return (color);
}

int	g_color_w_s(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x - ray.pos_x) / ray.htan >= (int)ray.pos_y + 1)
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y - 1) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y - 1) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y + 1;
			flag = x_img(viw, ray, 0, &color);
		}
		else
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
	}
	return (color);
}

int	g_color_w_n(t_cub3d *viw, t_man ray)
{
	int		flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_y - ((int)ray.pos_x - ray.pos_x) / ray.htan <= (int)ray.pos_y)
		{
			ray.pos_x = ray.pos_x + (ray.pos_y - (int)ray.pos_y) * ray.htan;
			ray.pos_z = ray.pos_z - (ray.pos_y - (int)ray.pos_y) * ray.vtan / ray.hcos;
			ray.pos_y = (int)ray.pos_y;
			flag = x_img(viw, ray, 1, &color);
		}
		else
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
		}
	}
	return (color);
}

int	g_color_n_w(t_cub3d *viw, t_man ray)
{
	int	flag;
	int	color;

	flag = 1;
	while (flag)
	{
		d_tuning(&ray, flag);
		if (ray.pos_x + (ray.pos_y - (int)ray.pos_y) * ray.htan <= (int)ray.pos_x)
		{
			ray.pos_y = ray.pos_y - ((int)(ray.pos_x) - ray.pos_x) / ray.htan;
			ray.pos_z = ray.pos_z - ((int)(ray.pos_x) - ray.pos_x) * ray.vtan / ray.hsin;
			ray.pos_x = (int)(ray.pos_x);
			flag = y_img(viw, ray, 1, &color);
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

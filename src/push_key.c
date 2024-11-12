/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 22:01:30 by tashiget          #+#    #+#             */
/*   Updated: 2024/11/12 22:01:30 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	keymove(int keycode, t_cub3d *viw)
{
	if (keycode == KEY_W)
		push_w(viw);
	else if (keycode == KEY_A)
		push_a(viw);
	else if (keycode == KEY_S)
		push_s(viw);
	else if (keycode == KEY_D)
		push_d(viw);
	else if (keycode == KEY_L)
		push_l(viw);
	else if (keycode == KEY_R)
		push_r(viw);
	else if (keycode == KEY_ESC)
		push_esc(viw);
	return (0);
}

void	push_w(t_cub3d *viw)
{
	(void)viw;
}

void	push_a(t_cub3d *viw)
{
	(void)viw;
}

void	push_s(t_cub3d *viw)
{
	(void)viw;
}

void	push_d(t_cub3d *viw)
{
	(void)viw;
}

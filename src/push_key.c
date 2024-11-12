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

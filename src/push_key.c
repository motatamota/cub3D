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
	// refresh_view(viw);
	return (0);
}

void	push_W(t_cub3d *viw)
{
	(void)viw;
}

void	push_A(t_cub3d *viw)
{
	(void)viw;

}

void	push_S(t_cub3d *viw)
{
	(void)viw;

}

void	push_D(t_cub3d *viw)
{
	(void)viw;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:03 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:03 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <unistd.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
# include <mlx.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "libft.h"

# define PLAYER_ANGLE_SPEED 1
# define PLAYER_MOVE_SPEED 1
# define FOV 90 //視野角
# define X_SIZE 900
# define Y_SIZE 1600
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_R 65363
# define KEY_L 65361
# define KEY_ESC 65307

typedef struct s_img
{
	void	*img;
	char	*path;
	int		width;
	int		height;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_rgb
{
	int	red;
	int	green;
	int	blue;
}	t_rgb;

typedef struct s_man
{
	double		pos_x;
	double		pos_y;
	double		angle_v;
	double		angle_h;
	t_vector	vect;
}	t_man;

typedef struct s_vector
{
	double	direction_x;
	double	direction_y;
	double	direction_z;
}	t_vector;
typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	int		frame_height;
	int		frame_width;
	double	fov;
	double	const_fov;
	t_man	man;
	t_img	north;
	t_img	south;
	t_img	east;
	t_img	west;
	t_rgb	floor;
	t_rgb	ceiling;
}	t_cub3d;

int		isargcerror(int ac);
int		isfilenameerror(char **av);
int		isfileopenerror(char **av);
int		keymove(int keycode, t_cub3d *viw);
void	cub3d(t_cub3d *viw, char *path);
void	push_w(t_cub3d *viw);
void	push_a(t_cub3d *viw);
void	push_s(t_cub3d *viw);
void	push_d(t_cub3d *viw);
void	push_r(t_cub3d *viw);
void	push_l(t_cub3d *viw);
void	push_esc(t_cub3d *viw);
void	init_fromfile(t_cub3d *viw, char *path);
void	initialimg(t_cub3d *viw, char *path);
void	check_rgb(char *str);
void	format_gnl(char *str);
#endif

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
# include "libft.h"

# define PLAYER_ANGLE_SPEED 1
# define PlAYER_MOVE_SPEED 0.1
# define FOV 90 //視野角
# define X_SIZE 900
# define Y_SIZE 1600
# define KEY_W 1
# define KEY_A 1
# define KEY_S 1
# define KEY_D 1
# define KEY_R 1
# define KEY_L 1
# define KEY_ESC 1

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_cub3d
{
	void	*mlx;
	void	*win;
	t_data	*img;
}	t_cub3d;

int	isargcerror(int ac);
int	isfilenameerror(char **av);
int	isfileopenerror(char **av);
void	cub3d(t_cub3d *viw);
void	push_W(t_cub3d *viw);
void	push_A(t_cub3d *viw);
void	push_S(t_cub3d *viw);
void	push_D(t_cub3d *viw);
void	push_R(t_cub3d *viw);
void	push_L(t_cub3d *viw);

#endif
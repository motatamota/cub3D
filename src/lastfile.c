/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lastfile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 12:29:48 by tashiget          #+#    #+#             */
/*   Updated: 2025/01/27 12:29:48 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "cub3d.h"

void	lastft(int *n, int *len, char **str, int *fd)
{
	*str = skip(*fd);
	*len = 0;
	*n = 0;
}

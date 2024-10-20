/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashiget <tashiget@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:01:08 by tashiget          #+#    #+#             */
/*   Updated: 2024/10/20 19:01:08 by tashiget         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	isargumentserror(int ac, char **av)
{
	if (isargcerror(ac) || isfilenameerror(av) || isfileopenerror(av))
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	if (isargumentserror(ac, av))
		return (1);
}

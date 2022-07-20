/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:07:33 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:34 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_esc(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
}

int	commands(int keycode, t_vars *vars)
{
	check_esc(keycode, vars);
	check_movements_up_down(keycode, vars);
	check_movements_left_right(keycode, vars);
	check_rotation_left(keycode, vars);
	check_rotation_right(keycode, vars);
	return (0);
}

int	closed_win(void)
{
	exit (0);
}

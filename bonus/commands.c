/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:04:43 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:04:44 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_esc(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	commands(int keycode, t_vars *vars)
{
	if (keycode == ESC_KEY)
		check_esc(vars);
	else if (keycode == W_UP_KEY)
		movements_up(vars);
	else if (keycode == S_DOWN_KEY)
		movements_down(vars);
	else if (keycode == D_RIGHT_KEY)
		movements_right(vars);
	else if (keycode == A_LEFT_KEY)
		movements_left(vars);
	else if (keycode == E_OPEN_KEY)
		open_door(vars);
	return (0);
}

int	mouse_move(int x, int y, t_vars *vars)
{
	static int	move;

	if (x >= 0 && x <= vars->ray.w && y >= 0 && y <= vars->ray.h)
	{
		if (x > move)
			rotation_right(vars);
		if (x < move)
			rotation_left(vars);
		move = x;
	}
	return (0);
}

int	shoot(int keycode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (keycode == 1)
		vars->ray.trigger = 1;
	return (0);
}

int	closed_win(void)
{
	exit (0);
}

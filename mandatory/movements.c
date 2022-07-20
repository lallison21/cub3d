/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:08:40 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:08:42 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_space(t_vars *vars, double x, double y)
{
	double	rad_x;
	double	rad_y;
	double	rad;

	rad = 0.2;
	rad_x = -rad;
	rad_y = -rad;
	while (rad_x <= 0.2)
	{
		rad_y = -rad;
		while (rad_y <= 0.2)
		{
			if (vars->map[(int)(x + rad_x)][(int)(y + rad_y)] != '0')
				return (1);
			rad_y += rad;
		}
		rad_x += rad;
	}
	return (0);
}

void	check_rotation_right(int keycode, t_vars *vars)
{
	if (keycode == RIGHT_KEY)
	{
		vars->ray.olddir_x = vars->ray.dir_x;
		vars->ray.dir_x = vars->ray.dir_x * cos(vars->ray.rotspeed)
			- vars->ray.dir_y * sin(vars->ray.rotspeed);
		vars->ray.dir_y = vars->ray.olddir_x * sin(vars->ray.rotspeed)
			+ vars->ray.dir_y * cos(vars->ray.rotspeed);
		vars->ray.oldplane_x = vars->ray.plane_x;
		vars->ray.plane_x = vars->ray.plane_x * cos(vars->ray.rotspeed)
			- vars->ray.plane_y * sin(vars->ray.rotspeed);
		vars->ray.plane_y = vars->ray.oldplane_x * sin(vars->ray.rotspeed)
			+ vars->ray.plane_y * cos(-vars->ray.rotspeed);
		render_window(vars);
	}
}

void	check_rotation_left(int keycode, t_vars *vars)
{
	if (keycode == LEFT_KEY)
	{
		vars->ray.olddir_x = vars->ray.dir_x;
		vars->ray.dir_x = vars->ray.dir_x * cos(-vars->ray.rotspeed)
			- vars->ray.dir_y * sin(-vars->ray.rotspeed);
		vars->ray.dir_y = vars->ray.olddir_x * sin(-vars->ray.rotspeed)
			+ vars->ray.dir_y * cos(-vars->ray.rotspeed);
		vars->ray.oldplane_x = vars->ray.plane_x;
		vars->ray.plane_x = vars->ray.plane_x * cos(-vars->ray.rotspeed)
			- vars->ray.plane_y * sin(-vars->ray.rotspeed);
		vars->ray.plane_y = vars->ray.oldplane_x * sin(-vars->ray.rotspeed)
			+ vars->ray.plane_y * cos(-vars->ray.rotspeed);
		render_window(vars);
	}
}

void	check_movements_up_down(int keycode, t_vars *vars)
{
	if (keycode == W_UP_KEY)
	{
		if (!check_space(vars, vars->ray.pos_x + vars->ray.dir_x
				* vars->ray.movespeed, vars->ray.pos_y))
			vars->ray.pos_x += vars->ray.dir_x * vars->ray.movespeed;
		if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
				+ vars->ray.dir_y * vars->ray.movespeed))
			vars->ray.pos_y += vars->ray.dir_y * vars->ray.movespeed;
		render_window(vars);
	}
	if (keycode == S_DOWN_KEY)
	{
		if (!check_space(vars, vars->ray.pos_x - vars->ray.dir_x
				* vars->ray.movespeed, vars->ray.pos_y))
			vars->ray.pos_x -= vars->ray.dir_x * vars->ray.movespeed;
		if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
				- vars->ray.dir_y * vars->ray.movespeed))
			vars->ray.pos_y -= vars->ray.dir_y * vars->ray.movespeed;
		render_window(vars);
	}
}

void	check_movements_left_right(int keycode, t_vars *vars)
{
	if (keycode == D_RIGHT_KEY)
	{
		if (!check_space(vars, vars->ray.pos_x + vars->ray.plane_x
				* vars->ray.movespeed, vars->ray.pos_y))
			vars->ray.pos_x += vars->ray.plane_x * vars->ray.movespeed;
		if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
				+ vars->ray.plane_y * vars->ray.movespeed))
			vars->ray.pos_y += vars->ray.plane_y * vars->ray.movespeed;
		render_window(vars);
	}
	if (keycode == A_LEFT_KEY)
	{
		if (!check_space(vars, vars->ray.pos_x - vars->ray.plane_x
				* vars->ray.movespeed, vars->ray.pos_y))
			vars->ray.pos_x -= vars->ray.plane_x * vars->ray.movespeed;
		if (!check_space(vars, vars->ray.pos_x, vars->ray.pos_y
				- vars->ray.plane_y * vars->ray.movespeed))
			vars->ray.pos_y -= vars->ray.plane_y * vars->ray.movespeed;
		render_window(vars);
	}
}

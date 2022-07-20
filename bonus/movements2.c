/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:06:27 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:06:28 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotation_right(t_vars *vars)
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
		+ vars->ray.plane_y * cos(vars->ray.rotspeed);
}

void	rotation_left(t_vars *vars)
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
}

void	open_door(t_vars *vars)
{
	int	x;
	int	y;

	x = (int)(vars->ray.pos_x + vars->ray.dir_x * 1.2);
	y = (int)(vars->ray.pos_y);
	if ((vars->door_map[x][y] == 'D') && vars->ray.side == 0
		&& vars->map[x][y] == 'D')
		vars->map[x][y] = '0';
	else if ((vars->door_map[x][y] == 'D') && vars->map[x][y] == '0'
		&& vars->door_map[(int)vars->ray.pos_x][(int)vars->ray.pos_y] == '0')
		vars->map[x][y] = 'D';
	x = (int)(vars->ray.pos_x);
	y = (int)(vars->ray.pos_y + vars->ray.dir_y * 1.2);
	if ((vars->door_map[x][y] == 'D') && vars->ray.side == 1
		&& vars->map[x][y] == 'D')
		vars->map[x][y] = '0';
	else if ((vars->door_map[x][y] == 'D') && vars->map[x][y] == '0'
		&& vars->door_map[(int)vars->ray.pos_x][(int)vars->ray.pos_y] == '0')
		vars->map[x][y] = 'D';
}

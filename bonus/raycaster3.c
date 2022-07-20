/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:06:52 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:06:53 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	texturing_calculations(t_vars *vars)
{
	if (vars->ray.side == 0)
		vars->ray.wall_x = vars->ray.pos_y
			+ vars->ray.perpwalldist * vars->ray.raydir_y;
	else
		vars->ray.wall_x = vars->ray.pos_x
			+ vars->ray.perpwalldist * vars->ray.raydir_x;
	vars->ray.wall_x -= floor(vars->ray.wall_x);
	vars->ray.tex_x = (int)(vars->ray.wall_x * (double)(vars->ray.texwidht));
	if (vars->ray.side == 0 && vars->ray.raydir_x > 0)
		vars->ray.tex_x = vars->ray.texwidht - vars->ray.tex_x - 1;
	if (vars->ray.side == 1 && vars->ray.raydir_y < 0)
		vars->ray.tex_x = vars->ray.texwidht - vars->ray.tex_x - 1;
	vars->ray.step = 1.0 * vars->ray.texheight / vars->ray.lineheigt;
	vars->ray.texpos = (vars->ray.drawstart - vars->ray.h / 2
			+ vars->ray.lineheigt / 2) * vars->ray.step;
	vars->ray.y = vars->ray.drawstart;
}

void	choose_wall_texture_pt2(t_vars *vars)
{
	if (vars->ray.side == 1)
	{
		if (vars->ray.raydir_y > 0)
			vars->ray.color = vars->img.north_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
		else
			vars->ray.color = vars->img.south_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
	}
	else
	{
		if (vars->ray.raydir_x > 0)
			vars->ray.color = vars->img.west_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
		else
			vars->ray.color = vars->img.east_data[vars->ray.texheight
				* vars->ray.tex_y + vars->ray.tex_x];
	}
}

void	choose_wall_texture(t_vars *vars)
{
	int	pos;

	while (vars->ray.y < vars->ray.drawend)
	{
		vars->ray.tex_y = (int)vars->ray.texpos & (vars->ray.texheight - 1);
		vars->ray.texpos += vars->ray.step;
		vars->ray.color = vars->img.north_data[vars->ray.texheight
			* vars->ray.tex_y + vars->ray.tex_x];
		if (vars->ray.hit != 2)
		{
			choose_wall_texture_pt2(vars);
		}
		else
		{
			pos = vars->ray.texheight * vars->ray.tex_y + vars->ray.tex_x;
			vars->ray.color = vars->img.door_data[pos];
		}
		vars->ray.buffer[vars->ray.y][vars->ray.x] = vars->ray.color;
		vars->ray.y++;
	}
}

void	render_walls(t_vars *vars)
{
	vars->ray.y = 0;
	while (vars->ray.y < vars->ray.h)
	{
		vars->ray.x = 0;
		while (vars->ray.x < vars->ray.w)
		{
			my_mlx_pixel_put(&vars->img, vars->ray.x, vars->ray.y,
				vars->ray.buffer[vars->ray.y][vars->ray.x]);
			vars->ray.x++;
		}
		vars->ray.y++;
	}
}

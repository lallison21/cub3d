/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:08:48 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:08:49 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	render_window(t_vars *vars)
{
	vars->img.img = mlx_new_image(vars->mlx, S_WIDTH, S_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel,
			&vars->img.line_length, &vars->img.endian);
	render_floor_ceilinig(vars);
	while (vars->ray.x < vars->ray.w)
	{
		get_initial_values(vars);
		dda_algorithm(vars);
		if (vars->ray.side == 0)
			vars->ray.perpwalldist = (vars->ray.sidedist_x
					- vars->ray.deltadist_x);
		else
			vars->ray.perpwalldist = (vars->ray.sidedist_y
					- vars->ray.deltadist_y);
		draw_line_calculations(vars);
		texturing_calculations(vars);
		choose_wall_texture(vars);
		vars->ray.x++;
	}
	render_walls(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	mlx_destroy_image(vars->mlx, vars->img.img);
}

void	raycaster(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "cub3d");
	render_window(vars);
	vars->ray.frametime = 0.03;
	vars->ray.movespeed = vars->ray.frametime * 5;
	vars->ray.rotspeed = vars->ray.frametime * 3;
}

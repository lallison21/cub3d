/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:06:34 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:06:36 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	shooting_animation(t_vars *vars)
{
	static int	i;

	if (vars->ray.trigger == 1)
	{
		if (i < 5)
			vars->img.pistol = vars->img.pistol0;
		if (i >= 5 && i < 10)
			vars->img.pistol = vars->img.pistol1;
		if (i >= 10 && i < 15)
			vars->img.pistol = vars->img.pistol2;
		if (i >= 15 && i < 25)
			vars->img.pistol = vars->img.pistol3;
		if (i >= 25 && i < 30)
			vars->img.pistol = vars->img.pistol0;
		if (i > 30)
		{
			i = 0;
			vars->ray.trigger = 0;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.pistol, 250, 110);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	render_window(t_vars *vars)
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
	place_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	shooting_animation(vars);
	mlx_destroy_image(vars->mlx, vars->img.img);
	return (0);
}

void	raycaster(t_vars *vars)
{
	vars->win = mlx_new_window(vars->mlx, S_WIDTH, S_HEIGHT, "cub3d");
	vars->ray.frametime = 0.04;
	vars->ray.movespeed = vars->ray.frametime * 5;
	vars->ray.rotspeed = vars->ray.frametime * 3;
}

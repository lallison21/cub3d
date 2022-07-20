/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:06:11 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:06:13 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_minimap(t_vars *vars)
{
	vars->mmap.bor_x = vars->mmap.x + vars->mmap.size;
	vars->mmap.bor_y = vars->mmap.y + vars->mmap.size;
	while (vars->mmap.y < vars->mmap.bor_y)
	{
		while (vars->mmap.x < vars->mmap.bor_x)
		{
			if (vars->map[vars->mmap.i][vars->mmap.j] == '1')
				my_mlx_pixel_put(&vars->img, vars->mmap.j + vars->mmap.x,
					vars->mmap.i + vars->mmap.y, 0);
			else
				my_mlx_pixel_put(&vars->img, vars->mmap.j + vars->mmap.x,
					vars->mmap.i + vars->mmap.y, 0xFFFFFF);
			vars->mmap.x++;
		}
		vars->mmap.x -= vars->mmap.size;
		vars->mmap.y++;
	}
	vars->mmap.y -= vars->mmap.size;
}

void	place_minimap(t_vars *vars)
{
	vars->mmap.size = 5;
	vars->mmap.i = 0;
	vars->mmap.j = 0;
	vars->mmap.x = vars->ray.w / 16;
	vars->mmap.y = vars->ray.h / 16;
	while (vars->map[vars->mmap.i])
	{
		while (vars->map[vars->mmap.i][vars->mmap.j])
		{
			if (vars->map[vars->mmap.i][vars->mmap.j] == '1'
				|| (vars->mmap.j == (int)(vars->ray.pos_y)
				&& vars->mmap.i == (int)(vars->ray.pos_x)))
				draw_minimap(vars);
			vars->mmap.j++;
			vars->mmap.x += vars->mmap.size;
		}
		vars->mmap.x = vars->ray.w / 16;
		vars->mmap.y += vars->mmap.size;
		vars->mmap.j = 0;
		vars->mmap.i++;
	}
}

void	copy_map(t_vars *vars, int height)
{
	int	i;

	i = -1;
	vars->door_map = malloc(sizeof(char *) * height + 1);
	while (++i < height)
		vars->door_map[i] = ft_strdup(vars->map[i]);
	vars->door_map[i] = NULL;
}

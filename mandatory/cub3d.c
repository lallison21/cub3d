/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:07:54 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:56 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_assets(t_data *img, t_vars *vars, t_assets *assets)
{
	int		img_width;
	int		img_height;

	assets->north_wall = find_asset(assets->north_wall);
	assets->east_wall = find_asset(assets->east_wall);
	assets->west_wall = find_asset(assets->west_wall);
	assets->south_wall = find_asset(assets->south_wall);
	img->north_wall = mlx_xpm_file_to_image(vars->mlx, assets->north_wall,
			&img_width, &img_height);
	img->east_wall = mlx_xpm_file_to_image(vars->mlx, assets->east_wall,
			&img_width, &img_height);
	img->west_wall = mlx_xpm_file_to_image(vars->mlx, assets->west_wall,
			&img_width, &img_height);
	img->south_wall = mlx_xpm_file_to_image(vars->mlx, assets->south_wall,
			&img_width, &img_height);
	if (!img->north_wall || !img->south_wall
		|| !img->east_wall || !img->west_wall)
		ft_perror("Error: wrong asset\n");
	get_img_data(img, assets);
}

void	init_ray(t_vars *vars)
{
	int	i;

	vars->ray.pos_x = -1;
	vars->ray.pos_y = -1;
	vars->ray.dir_x = 1;
	vars->ray.dir_y = 0;
	vars->ray.plane_x = 0;
	vars->ray.plane_y = 0.66;
	vars->ray.x = 0;
	vars->ray.w = S_WIDTH;
	vars->ray.h = S_HEIGHT;
	vars->ray.texwidht = 64;
	vars->ray.texheight = 64;
	vars->ray.buffer = malloc(sizeof (int *) * vars->ray.h);
	if (!vars->ray.buffer)
		exit (1);
	i = 0;
	while (i < vars->ray.h)
	{
		vars->ray.buffer[i] = malloc(sizeof(int) * vars->ray.w);
		if (!vars->ray.buffer[i])
			exit (1);
		i++;
	}
}

void	init_struct(t_vars *vars)
{
	vars->assets.north_wall = NULL;
	vars->assets.south_wall = NULL;
	vars->assets.east_wall = NULL;
	vars->assets.west_wall = NULL;
	vars->assets.floor = NULL;
	vars->assets.ceiling = NULL;
	vars->map = NULL;
	init_ray(vars);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc != 2)
		ft_perror("Invalid number of arguments\n");
	vars.mlx = mlx_init();
	if (vars.mlx == NULL)
		ft_perror("Error: mlx initialization\n");
	init_struct(&vars);
	check_file(argc, argv, &vars);
	load_assets(&vars.img, &vars, &vars.assets);
	raycaster(&vars);
	mlx_hook(vars.win, 17, 0, closed_win, 0);
	mlx_hook(vars.win, 2, 1L << 0, commands, &vars);
	mlx_loop(vars.mlx);
	exit (0);
}

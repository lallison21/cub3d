/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:05:10 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:11 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_assets_v2(t_data *img, t_vars *vars, t_assets *assets)
{
	int	img_width;
	int	img_height;

	img->north_wall = mlx_xpm_file_to_image(vars->mlx, assets->north_wall,
			&img_width, &img_height);
	img->east_wall = mlx_xpm_file_to_image(vars->mlx, assets->east_wall,
			&img_width, &img_height);
	img->west_wall = mlx_xpm_file_to_image(vars->mlx, assets->west_wall,
			&img_width, &img_height);
	img->south_wall = mlx_xpm_file_to_image(vars->mlx, assets->south_wall,
			&img_width, &img_height);
	img->door = mlx_xpm_file_to_image(vars->mlx, assets->door,
			&img_width, &img_height);
	img->pistol0 = mlx_xpm_file_to_image(vars->mlx, assets->pistol0,
			&img_width, &img_height);
	img->pistol1 = mlx_xpm_file_to_image(vars->mlx, assets->pistol1,
			&img_width, &img_height);
	img->pistol2 = mlx_xpm_file_to_image(vars->mlx, assets->pistol2,
			&img_width, &img_height);
	img->pistol3 = mlx_xpm_file_to_image(vars->mlx, assets->pistol3,
			&img_width, &img_height);
}

void	load_assets(t_data *img, t_vars *vars, t_assets *assets)
{
	assets->north_wall = find_asset(assets->north_wall);
	assets->east_wall = find_asset(assets->east_wall);
	assets->west_wall = find_asset(assets->west_wall);
	assets->south_wall = find_asset(assets->south_wall);
	assets->door = find_asset(assets->door);
	assets->pistol0 = "./bonus/assets/pistol0.xpm";
	assets->pistol1 = "./bonus/assets/pistol1.xpm";
	assets->pistol2 = "./bonus/assets/pistol2.xpm";
	assets->pistol3 = "./bonus/assets/pistol3.xpm";
	load_assets_v2(img, vars, assets);
	if (!img->north_wall || !img->south_wall
		|| !img->east_wall || !img->west_wall
		|| !img->door || !img->pistol0
		|| !img->pistol1 || !img->pistol2
		|| !img->pistol3)
		ft_perror("Error: wrong asset\n");
	img->pistol = img->pistol0;
	get_img_data(img, assets);
}

void	init_ray(t_vars *vars)
{
	int	i;

	vars->ray.pos_x = -1;
	vars->ray.pos_y = -1;
	vars->ray.dir_x = -1;
	vars->ray.dir_y = 0;
	vars->ray.plane_x = 0;
	vars->ray.plane_y = -0.66;
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
	vars->assets.door = NULL;
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
	check_file(argv, &vars);
	load_assets(&vars.img, &vars, &vars.assets);
	raycaster(&vars);
	mlx_hook(vars.win, 6, 1L << 6, mouse_move, &vars);
	mlx_hook(vars.win, 17, 0, closed_win, 0);
	mlx_hook(vars.win, 2, 1L << 0, commands, &vars);
	mlx_mouse_hook(vars.win, shoot, &vars);
	mlx_loop_hook(vars.mlx, render_window, &vars);
	mlx_loop(vars.mlx);
	exit (0);
}

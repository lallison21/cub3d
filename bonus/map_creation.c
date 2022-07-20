/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:06:01 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:06:02 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	create_map(t_vars *vars, char *str, int fd)
{
	int	i;

	i = 1;
	vars->map = malloc(sizeof(char *) * 101);
	if (!vars->map)
		exit(1);
	vars->map[0] = str;
	str = NULL;
	while (get_next_line(fd, &str))
	{
		vars->map[i] = NULL;
		if (check_line(str))
			ft_perror("Error: map is invalid\n");
		vars->map[i] = str;
		if (i > 100)
			ft_perror("Error: map too big\n");
		i++;
	}
	vars->map[i] = NULL;
	copy_map(vars, i);
	close (fd);
	map_check(vars);
}

void	get_player_direction(char dir, t_vars *vars)
{
	if (dir == 'N')
	{
		vars->ray.dir_x = 1;
		vars->ray.dir_y = 0;
		vars->ray.plane_x = 0;
		vars->ray.plane_y = 0.66;
	}
	if (dir == 'W')
	{
		vars->ray.dir_x = 0;
		vars->ray.dir_y = -1;
		vars->ray.plane_x = 0.66;
		vars->ray.plane_y = 0;
	}
	if (dir == 'E')
	{
		vars->ray.dir_x = 0;
		vars->ray.dir_y = 1;
		vars->ray.plane_x = -0.66;
		vars->ray.plane_y = 0;
	}
}

void	player_pos_check(t_vars *vars, int x, int y)
{
	if (vars->map[y][x] == 'N' || vars->map[y][x] == 'S'
				|| vars->map[y][x] == 'E' || vars->map[y][x] == 'W')
	{
		if (vars->ray.pos_x > 0 || vars->ray.pos_y > 0)
			ft_perror("Error: too many player positions\n");
		get_player_direction(vars->map[y][x], vars);
		vars->ray.pos_x = y + 0.5;
		vars->ray.pos_y = x + 0.5;
		vars->map[y][x] = '0';
	}
}

void	find_player_pos(t_vars *vars)
{
	int	x;
	int	y;

	y = 0;
	while (vars->map[y])
	{
		x = 0;
		while (vars->map[y][x])
		{
			player_pos_check(vars, x, y);
			x++;
		}
		y++;
	}
	if (vars->ray.pos_x < 0 || vars->ray.pos_y < 0)
		ft_perror("Error: no designated player position\n");
}

void	check_file(char **argv, t_vars *vars)
{
	int		fd;

	if (ft_strncmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub", 5) != 0
		|| ft_strlen(argv[1]) < 5)
	{
		printf("Error: %s is not a map\n", argv[1]);
		exit(1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_perror("Error: can't read map\n");
	check_contents(fd, vars);
	small_map_check(vars);
	find_player_pos(vars);
}

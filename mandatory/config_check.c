/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:07:40 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:41 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_no_so_walls(t_vars *vars, char *str)
{
	if (!ft_strncmp(str, "NO ", 3))
	{
		if (vars->assets.north_wall)
			ft_perror("Error: double parameters\n");
		vars->assets.north_wall = str;
		return (0);
	}
	if (!ft_strncmp(str, "SO ", 3))
	{
		if (vars->assets.south_wall)
			ft_perror("Error: double parameters\n");
		vars->assets.south_wall = str;
		return (0);
	}
	return (1);
}

int	check_we_ea_walls(t_vars *vars, char *str)
{
	if (!ft_strncmp(str, "WE ", 3))
	{
		if (vars->assets.west_wall)
			ft_perror("Error: double parameters\n");
		vars->assets.west_wall = str;
		return (0);
	}
	if (!ft_strncmp(str, "EA ", 3))
	{
		if (vars->assets.east_wall)
			ft_perror("Error: double parameters\n");
		vars->assets.east_wall = str;
		return (0);
	}
	return (1);
}

int	check_up_down(t_vars *vars, char *str)
{
	if (!ft_strncmp(str, "F ", 2))
	{
		if (vars->assets.floor)
			ft_perror("Error: double parameters\n");
		vars->assets.floor = str;
		return (0);
	}
	if (!ft_strncmp(str, "C ", 2))
	{
		if (vars->assets.ceiling)
			ft_perror("Error: double parameters\n");
		vars->assets.ceiling = str;
		return (0);
	}
	return (1);
}

void	check_assets(t_vars *vars)
{
	if (!vars->assets.north_wall || !vars->assets.south_wall
		|| !vars->assets.east_wall || !vars->assets.west_wall
		|| !vars->assets.ceiling || !vars->assets.floor)
		ft_perror("Error: no parameters\n");
}

void	check_contents(int fd, t_vars *vars)
{
	char	*str;

	str = NULL;
	while (get_next_line(fd, &str))
	{
		if (!check_no_so_walls(vars, str))
			continue ;
		if (!check_we_ea_walls(vars, str))
			continue ;
		if (!check_up_down(vars, str))
			continue ;
		if (check_line(str) == 1)
			ft_perror("Error: invalid parameters\n");
		if (!check_line(str))
		{
			check_assets(vars);
			return (create_map(vars, str, fd));
		}
		free(str);
	}
}

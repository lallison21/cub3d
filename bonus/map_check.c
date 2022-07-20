/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:05:49 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:50 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	border_void_check(t_vars *vars, int i, int j)
{
	if (vars->map[i + 1][j] == '0' || vars->map[i][j + 1] == '0'
		|| vars->map[i - 1][j] == '0' || vars->map[i][j - 1] == '0')
		ft_perror("Error: map without borders\n");
}

void	check_east_border(t_vars *vars, int *flag)
{
	int	len;
	int	i;
	int	j;

	i = 1;
	while (vars->map[i + 1])
	{
		j = 1;
		len = ft_strlen(vars->map[i]) - 1;
		while (j < len)
		{
			if (vars->map[i][j] == '0' &&
				(vars->map[i - 1][j] == ' ' || vars->map[i + 1][j] == ' ' ||
				vars->map[i][j - 1] == ' ' || vars->map[i][j + 1] == ' ' ||
				vars->map[i - 1][j] == '\0' || vars->map[i + 1][j] == '\0' ||
				vars->map[i][j - 1] == '\0' || vars->map[i][j + 1] == '\0'))
				*flag = 1;
			j++;
		}
		i++;
	}
}

void	check_we_ea_so_border(t_vars *vars, int *flag)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map[i])
	{
		j = ft_strlen(vars->map[i]) - 1;
		if (vars->map[i][0] == '0' || vars->map[i][j] == '0' ||
			(vars->map[i][0] == ' ' && vars->map[i][1] == '0') ||
			(vars->map[i][j] == ' ' && vars->map[i][j - 1] == '0'))
			*flag = 1;
		i++;
	}
	j = 0;
	while (vars->map[i - 1][j])
	{
		if (vars->map[i - 1][j] == '0' ||
			(vars->map[i - 1][j] == ' ' && vars->map[i - 2][j] == '0'))
			*flag = 1;
		j++;
	}
}

void	border_zero_check(t_vars *vars)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	j = 0;
	flag = 0;
	while (vars->map[0][j])
	{
		if (vars->map[0][j] == '0' ||
			(vars->map[0][j] == ' ' && vars->map[1][j] == '0'))
			flag = 1;
		j++;
	}
	check_we_ea_so_border(vars, &flag);
	check_east_border(vars, &flag);
	if (flag == 1)
		ft_perror("Error: map without borders\n");
}

void	map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 1;
	small_map_check(vars);
	border_zero_check(vars);
	while (vars->map[i + 1])
	{
		j = 1;
		while (vars->map[i][j + 1])
		{
			if (vars->map[i][j] == ' ')
				border_void_check(vars, i, j);
			j++;
		}
		i++;
	}
}

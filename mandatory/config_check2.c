/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:07:47 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:48 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	smol_map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (!vars->map)
		ft_perror("Error: no map\n");
	while (vars->map[i])
	{
		j = ft_strlen(vars->map[i]);
		if (j < 3)
			ft_perror("Error: map is too small\n");
		i++;
	}
	if (i < 3)
		ft_perror("Error: map is too small\n");
}

void	read_check(int check, char *buf)
{
	if (check < 0)
	{
		free (buf);
		ft_perror("Error: can't read map\n");
	}
}

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (2);
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != ' '
			&& str[i] != 'W' && str[i] != 'E' && str[i] != 'N'
			&& str[i] != 'S')
			return (1);
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

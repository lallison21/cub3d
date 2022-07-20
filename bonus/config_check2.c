/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_check2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:05:00 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:01 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	small_map_check(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!vars->map)
		ft_perror("Error: no map\n");
	while (vars->map[i])
	{
		j = ft_strlen(vars->map[i]);
		if (j < 3)
			ft_perror("Error: map is too small2\n");
		i++;
	}
	if (i < 3)
		ft_perror("Error: map is too small\n");
}

int	read_check(int check, char *buf)
{
	if (check < 0)
	{
		free (buf);
		ft_perror("Error: can't read map\n");
	}
	if (buf[0] == '\0')
	{
		free(buf);
		return (1);
	}
	return (0);
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
			&& str[i] != 'S' && str[i] != 'D')
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
		if (!check_door(vars, str))
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

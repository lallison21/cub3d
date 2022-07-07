/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:55:08 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 19:55:10 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*check_doubly_arguments(t_node *node, char *text, int flag)
{
	if (flag == 0 && !node->north_texture)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else if (flag == 1 && !node->south_texture)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else if (flag == 2 && !node->west_texture)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else if (flag == 3 && !node->east_texture)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else if (flag == 4 && !node->floor)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else if (flag == 5 && !node->ceiling)
		return (ft_substr(text, 0, ft_strlen(text) - 1));
	else
		error_msg(4);
	return (NULL);
}

void	check_file_format(char *str, int fd, char *format)
{
	int		i;
	int		j;

	i = -1;
	j = 4;
	while (str[++i])
		;
	while (j >= 0 && str[i--] == format[j--])
		;
	if (j == -1)
		return ;
	close(fd);
	error_msg(2);
}

void	check_text(char *text)
{
	int	i;

	i = -1;
	if (!ft_strcmp(text, "\n"))
		return ;
	while (text[++i])
	{
		if (text[i] != '0' && text[i] != '1' && text[i] != 'N'
			&& text[i] != 'S' && text[i] != 'W' && text[i] != 'E'
			&& text[i] != ' ' && text[i] != '\n')
			return ;
	}
	error_msg(3);
}

void	check_border(t_node *node, int i, int j)
{
	if (i == 0 || i == node->map_hight - 1)
	{
		if (j == 0 || j == node->map_width - 1)
		{
			if (node->map[i][j] != '1' && node->map[i][j] != ' ')
				error_msg(5);
		}
		else
			if (node->map[i][j] != '1' && node->map[i][j] != ' ')
				error_msg(5);
	}
	else if (j == 0 || j == node->map_width - 1)
		if (node->map[i][j] != '1' && node->map[i][j] != ' ')
			error_msg(5);
}

void	check_inside(t_node *node, int i, int j)
{
}

void	map_checker(t_node *node)
{
	int	i;
	int	j;

	i = -1;
	while (node->map[++i])
	{
		j = -1;
		while (node->map[i][++j])
		{
			if (node->map[i][j] != '0' && node->map[i][j] != '1'
				&& node->map[i][j] != ' ' && node->map[i][j] != 'N'
				&& node->map[i][j] != 'S' && node->map[i][j] != 'E'
				&& node->map[i][j] != 'W')
				error_msg(5);
			check_border(node, i, j);
			check_inside(node, i, j);
		}
	}
}

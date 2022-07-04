/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:31:14 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 16:31:16 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_next_line(int fd)
{
	char	*res;
	char	*buf;

	res = NULL;
	buf = malloc(2);
	while (read(fd, buf, 1) == 1 && buf[0] != '\0')
	{
		buf[1] = '\0';
		res = ft_strjoin(res, buf);
		if (buf[0] == '\n')
			break ;
	}
	free(buf);
	return (res);
}

int	create_trgb(int t, int r, int g, int b)
{
	while (r > 255 && g > 255 && b > 255)
	{
		if (r > 255)
			r = r - 255;
		else if (g > 255)
			g = g - 255;
		else if (b > 255)
			b = b - 255;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

void	init_node(t_node *node)
{
	node->north_texture = NULL;
	node->south_texture = NULL;
	node->west_texture = NULL;
	node->east_texture = NULL;
	node->floor = NULL;
	node->ceiling = NULL;
	node->map = NULL;
}

int	main(int ac, char **av)
{
	int		fd;
	t_node	node;

	if (ac != 2)
		error_msg(0);
	init_node(&node);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_msg(1);
	check_file_format(av[1], fd, ".cub");
	fill_node(fd, &node);
	close(fd);
	free_node(&node);
}

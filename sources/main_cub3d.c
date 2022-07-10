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

void	init_node(t_node *node)
{
	node->north_texture = NULL;
	node->south_texture = NULL;
	node->west_texture = NULL;
	node->east_texture = NULL;
	node->floor = -1;
	node->ceiling = -1;
	node->width = 1920;
	node->hight = 1080;
	node->map = NULL;
	node->map_hight = 0;
	node->map_width = 0;
}

int	create_colot(t_node *node, char **texts, int flag)
{
	int		i;
	int		*arr;
	char	*text;
	char	**color;

	text = check_doubly_arguments(node, texts[1], flag);
	arr = malloc(sizeof(int) * 3);
	color = ft_split(text, ',');
	i = -1;
	while (++i < 3)
		arr[i] = ft_atoi(color[i]);
	free(text);
	free_doubly_char(color);
	i = create_trgb(0, arr[0], arr[1], arr[2]);
	free(arr);
	return (i);
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
	map_checker(&node);
	raycasting(&node);
	free_node(&node);
}

//for (int i = 0; node.map[i] != NULL; i++)
//printf("%s\n", node.map[i]);

//for (int i = 0; map[i] != NULL; i++)
//printf("%s\n", map[i]);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:45:40 by lallison          #+#    #+#             */
/*   Updated: 2022/07/01 13:45:41 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	fill_textures_path(char *text, t_node *node)
{
	char	**texts;

	texts = ft_split(text, ' ');
	if (texts[2])
		error_msg(3);
	if (!ft_strcmp(texts[0], "NO"))
		node->north_texture = check_doubly_arguments(node, texts[1], 0);
	else if (!ft_strcmp(texts[0], "SO"))
		node->south_texture = check_doubly_arguments(node, texts[1], 1);
	else if (!ft_strcmp(texts[0], "WE"))
		node->west_texture = check_doubly_arguments(node, texts[1], 2);
	else if (!ft_strcmp(texts[0], "EA"))
		node->east_texture = check_doubly_arguments(node, texts[1], 3);
	else
		error_msg(3);
	free_doubly_char(texts);
}

void	fill_color(char *text, t_node *node)
{
	char	**texts;

	texts = ft_split(text, ' ');
	if (texts[2])
		error_msg(3);
	if (!ft_strcmp(texts[0], "F"))
		node->floor = create_colot(node, texts, 4);
	else if (!ft_strcmp(texts[0], "C"))
		node->ceiling = create_colot(node, texts, 5);
	else
		error_msg(3);
	free_doubly_char(texts);
}

void	fill_map(t_node *node, char *text, int fd)
{
	char	*map;

	while (!ft_strcmp(text, "\n"))
	{
		free(text);
		text = get_next_line(fd);
	}
	if (!text)
		error_msg(5);
	map = NULL;
	while (text)
	{
		map = ft_strjoin(map, text);
		free(text);
		text = get_next_line(fd);
	}
	node->map = ft_split(map, '\n');
	free(map);
}

void	make_right_square_map(t_node *node, int hight)
{
	int		i;
	int		width;
	char	*spcs;

	while (node->map[++hight])
	{
		width = ft_strlen(node->map[hight]);
		if (width > node->map_width)
			node->map_width = width;
	}
	node->map_hight = hight;
	hight = -1;
	while (node->map[++hight])
	{
		width = ft_strlen(node->map[hight]);
		i = -1;
		spcs = malloc(sizeof(char) * node->map_width - width + 1);
		while (++i < node->map_width - width)
			spcs[i] = ' ';
		spcs[i] = '\0';
		if (width < node->map_width)
			node->map[hight] = ft_strjoin(node->map[hight], spcs);
		free(spcs);
	}
}

void	fill_node(int fd, t_node *node)
{
	char	*text;

	text = get_next_line(fd);
	while (text)
	{
		if (ft_strnstr(text, "NO", ft_strlen(text))
			|| ft_strnstr(text, "SO", ft_strlen(text))
			|| ft_strnstr(text, "WE", ft_strlen(text))
			|| ft_strnstr(text, "EA", ft_strlen(text)))
			fill_textures_path(text, node);
		else if (ft_strnstr(text, "F", ft_strlen(text))
			|| ft_strnstr(text, "C", ft_strlen(text)))
			fill_color(text, node);
		check_text(text);
		free(text);
		text = get_next_line(fd);
		if (node->north_texture && node->south_texture && node->west_texture
			&&node->east_texture && node->floor != -1 && node->ceiling != -1)
			break ;
	}
	if (!node->south_texture || !node->north_texture || !node->west_texture
		|| !node->east_texture || node->floor == -1 || node->ceiling == -1)
		error_msg(3);
	fill_map(node, text, fd);
	make_right_square_map(node, -1);
}

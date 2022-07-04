/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 13:41:29 by lallison          #+#    #+#             */
/*   Updated: 2022/07/01 13:41:30 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_doubly_char(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}

void	free_node(t_node *node)
{
	free(node->north_texture);
	free(node->south_texture);
	free(node->east_texture);
	free(node->west_texture);
	free(node->floor);
	free(node->ceiling);
	free_doubly_char(node->map);
}

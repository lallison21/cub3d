/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 14:10:36 by lallison          #+#    #+#             */
/*   Updated: 2022/07/10 14:10:37 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	draw_minimap_element(t_data img, int i, int j, int flag)
{
	int	x;
	int	y;

	y = i * 10;
	while (y++ < i * 10 + 10)
	{
		x = j * 10;
		while (x++ < j * 10 + 10)
		{
			if (flag == 0)
				my_mlx_pixel_put(&img, x, y, 0x00000000);
			else if (flag == 1)
				my_mlx_pixel_put(&img, x, y, 0x0000FF00);
			else if (flag == 2)
				my_mlx_pixel_put(&img, x, y, 0x000000FF);
			else if (flag == 3)
				my_mlx_pixel_put(&img, x, y, 0x00FF0000);
		}
	}
}

void	draw_minimap(t_node *node, t_data img)
{
	int	i;
	int	j;

	i = -1;
	while (node->map[++i])
	{
		j = -1;
		while (node->map[i][++j])
		{
			if (node->map[i][j] == ' ')
				draw_minimap_element(img, i, j, 0);
			else if (node->map[i][j] == '1')
				draw_minimap_element(img, i, j, 1);
			else if (node->map[i][j] == '0')
				draw_minimap_element(img, i, j, 2);
			else if (node->map[i][j] == 'N' || node->map[i][j] == 'S'
				|| node->map[i][j] == 'W' || node->map[i][j] == 'E')
				draw_minimap_element(img, i, j, 3);
		}
	}
}

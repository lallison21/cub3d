/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 17:47:08 by lallison          #+#    #+#             */
/*   Updated: 2022/07/09 17:47:10 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenth + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_floor_and_ceiling(t_node *node, t_data img)
{
	int	x;
	int	y;

	y = -1;
	while (++y < node->hight)
	{
		x = -1;
		while (++x < node->width)
		{
			if (y < node->hight / 2)
				my_mlx_pixel_put(&img, x, y, node->ceiling);
			else
				my_mlx_pixel_put(&img, x, y, node->floor);
		}
	}
}

int	close_window(t_data *img)
{
	mlx_destroy_image(img->mlx, img->img);
	mlx_destroy_window(img->mlx, img->win);
	exit (0);
}

int	key_hook(int keycode, t_data *img)
{
	if (keycode == 53)
		close_window(img);
	return (0);
}

void	raycasting(t_node *node)
{
	t_data	img;

	img.mlx = mlx_init();
	img.win = mlx_new_window(img.mlx, node->width, node->hight, "CUB_3D");
	img.img = mlx_new_image(img.mlx, node->width, node->hight);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenth,
			&img.endian);
	mlx_key_hook(img.win, key_hook, &img);
	mlx_hook(img.win, 17, 1L << 0, close_window, &img);
	draw_floor_and_ceiling(node, img);
	mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
	mlx_loop(img.mlx);
}

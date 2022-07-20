/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding_assets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:05:26 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:05:27 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*find_asset(char *str)
{
	char	**buf;

	buf = ft_split(str, ' ');
	if (!buf[1])
		ft_perror("Error: no asset\n");
	free(str);
	free(buf[0]);
	free(buf);
	return (buf[1]);
}

void	check_rgb_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ',' && !ft_isdigit(str[i]))
			ft_perror("Error: no rgb values\n");
		i++;
	}
}

int	find_color_pt2(char **tmp)
{
	int		r;
	int		g;
	int		b;

	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255)
		ft_perror("Error: color component out of range\n");
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp);
	return (256 * 256 * r + 256 * g + b);
}

int	find_color(char *str)
{
	char	**buf;
	char	**tmp;

	buf = ft_split(str, ' ');
	if (!buf[1])
		ft_perror("Error: no color\n");
	free(str);
	check_rgb_numbers(buf[1]);
	tmp = ft_split(buf[1], ',');
	if (!tmp[0] || !tmp[1] || !tmp[2] || tmp[3])
		ft_perror("Error: no color\n");
	free(buf[1]);
	free(buf[0]);
	free(buf);
	return (find_color_pt2(tmp));
}

void	get_img_data(t_data *img, t_assets *assets)
{
	img->north_data = (int *)mlx_get_data_addr(img->north_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->south_data = (int *)mlx_get_data_addr(img->south_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->east_data = (int *)mlx_get_data_addr(img->east_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->west_data = (int *)mlx_get_data_addr(img->west_wall,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->door_data = (int *)mlx_get_data_addr(img->door,
			&img->bits_per_pixel, &img->line_length, &img->endian);
	img->floor_data = find_color(assets->floor);
	img->ceiling_data = find_color(assets->ceiling);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:33:37 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 16:33:39 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "../libft/libft.h"
# include "../minilibx/mlx.h"

typedef struct s_node
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	int		floor;
	int		ceiling;
	int		hight;
	int		width;
	char	**map;
	int		map_hight;
	int		map_width;
}	t_node;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenth;
	int		endian;
}	t_data;

/*		./sources/fill_node.c			*/
void	fill_node(int fd, t_node *node);

/*		./sources/main_cub3d.c			*/
char	*get_next_line(int fd);
int		create_colot(t_node *node, char **texts, int flag);

/*		./sources/raycasting.c			*/
void	raycasting(t_node *node);
int		create_trgb(int t, int r, int g, int b);

/*		./utils/check_utils.c			*/
void	check_text(char *text);
void	map_checker(t_node *node);
void	check_file_format(char *str, int fd, char *format);
char	*check_doubly_arguments(t_node *node, char *text, int flag);

/*		./utils/error_msg.c				*/
void	error_msg(int flag);

/*		./utils/free_memory_utils.c		*/
void	free_node(t_node *node);
void	free_doubly_char(char **str);

#endif

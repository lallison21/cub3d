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

typedef struct s_node
{
	char	*north_texture;
	char	*south_texture;
	char	*west_texture;
	char	*east_texture;
	char	*floor;
	char	*ceiling;
	char	**map;
}	t_node;

/*		./sources/fill_node.c			*/
void	fill_node(int fd, t_node *node);

/*		./sources/main_cub3d.c			*/
char	*get_next_line(int fd);

/*		./utils/check_utils.c			*/
void	check_text(char *text);
void	check_file_format(char *str, int fd, char *format);
char	*check_doubly_arguments(t_node *node, char *text, int flag);

/*		./utils/error_msg.c				*/
void	error_msg(int flag);

/*		./utils/free_memory_utils.c		*/
void	free_node(t_node *node);
void	free_doubly_char(char **str);

#endif

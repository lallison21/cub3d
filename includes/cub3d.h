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

#include <math.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/*		./utils/error_msg.c			*/
void	error_arg(void);
void	error_file(int flag);

/*		./utils/check_utils.c		*/
void	check_file_format(char *str, int fd);

#endif

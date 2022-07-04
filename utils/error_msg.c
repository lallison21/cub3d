/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 18:45:08 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 18:45:09 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_msg(int flag)
{
	if (flag == 0)
		write(2, "\033[0;31mError: wrong number of argument\n\033[0m", 39);
	else if (flag == 1)
		write(2, "\033[0;31mError: no such file or directory\n\033[0m", 40);
	else if (flag == 2)
		write(2, "\033[0;31mError: wrong file format\n\033[0m", 32);
	else if (flag == 3)
		write(2, "\033[0;31mError: wrong arguments\n\033[0m", 30);
	else if (flag == 4)
		write(2, "\033[0;31mError: there are repeated arguments\n\033[0m", 43);
	else if (flag == 5)
		write(2, "\033[0;31mError: error with map\n\033[0m", 29);
	exit(1);
}

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

void	error_arg(void)
{
	write(2, "\033[0;31mError: wrong number of argument\n\033[0m", 39);
	exit(1);
}

void	error_file(int flag)
{
	if (flag == 0)
		write(2, "\033[0;31mError: no such file or directory\n\033[0m", 40);
	else if (flag == 1)
		write(2, "\033[0;31mError: wrong file format\n\033[0m", 32);
	exit(2);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 19:55:08 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 19:55:10 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	check_file_format(char *str, int fd)
{
	int		i;
	int		j;
	char	*format;

	format = ".cub";
	i = -1;
	j = 4;
	while (str[++i])
		;
	while (j >= 0 && str[i--] == format[j--])
		;
	if (j == -1)
		return ;
	close(fd);
	error_file(1);
}

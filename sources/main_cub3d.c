/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_cub3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 16:31:14 by lallison          #+#    #+#             */
/*   Updated: 2022/06/27 16:31:16 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int fd;

	if (ac != 2)
		error_arg();
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_file(0);
	check_file_format(av[1], fd);
	write(1, "GOOD!!!\n", 8);
	close(fd);
}

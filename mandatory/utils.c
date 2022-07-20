/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:09:09 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:09:10 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	void			*ptr;
	unsigned char	*temp;
	size_t			i;

	if (count == 0 || size == 0)
		return (malloc(0));
	ptr = malloc(size * count);
	if (ptr == 0)
		return (NULL);
	i = size * count;
	temp = (unsigned char *)ptr;
	while (i > 0)
	{
		*temp++ = 0;
		i--;
	}
	return (ptr);
}

int	get_next_line(int fd, char **str)
{
	char	*buf;
	int		i;
	int		check;

	i = 0;
	check = 1;
	buf = ft_calloc(101, 1);
	if (!buf)
		exit (1);
	while (check > 0)
	{
		check = read(fd, &buf[i], 1);
		if (buf[i] == '\n')
			break ;
		i++;
	}
	read_check(check, buf);
	if (buf[0] == '\0')
	{
		free(buf);
		return (0);
	}
	buf[i] = '\0';
	*str = buf;
	return (1);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while ((s1[i] || s2[i]) && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	while (src[i])
		i++;
	if (dstsize == 0)
		return (i);
	i = 0;
	while (src[i] && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	i = 0;
	while (src[i])
		i++;
	return (i);
}

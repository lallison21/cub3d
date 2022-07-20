/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lallison <lallison@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 17:07:15 by lallison          #+#    #+#             */
/*   Updated: 2022/07/13 17:07:16 by lallison         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isdigit(int c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

static int	count(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f')
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = count(str);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			sign = sign * (-1);
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((((res * 10) + (str[i] - '0')) < res) && (sign == 1))
			return (-1);
		else if ((((res * 10) + (str[i] - '0')) < res) && (sign == -1))
			return (0);
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_perror(char *err)
{
	write(2, err, ft_strlen(err));
	exit(EXIT_FAILURE);
}

char	*ft_strdup(const char *s)
{
	char	*p;
	size_t	i;

	i = ft_strlen(s);
	p = NULL;
	p = (char *)malloc((i + 1) * sizeof(char));
	if (p != NULL)
	{
		i = 0;
		while (s[i])
		{
			p[i] = s[i];
			++i;
		}
		p[i] = '\0';
	}
	return (p);
}

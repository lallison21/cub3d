/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 10:42:22 by                   #+#    #+#             */
/*   Updated: 2021/10/09 12:26:40 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*k;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	k = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!k)
		return (NULL);
	while (s1[i])
	{
		k[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		k[i] = s2[j];
		j++;
		i++;
	}
	k[i] = '\0';
	return (k);
}

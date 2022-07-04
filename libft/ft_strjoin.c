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

	if (!s1)
		return (ft_strdup((char *)s2));
	if (!s2)
		return (NULL);
	k = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!k)
		return (NULL);
	i = -1;
	while (s1[++i])
		k[i] = s1[i];
	j = 0;
	while (s2[j])
		k[i++] = s2[j++];
	k[i] = '\0';
	free((char *)s1);
	return (k);
}

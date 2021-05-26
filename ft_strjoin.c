/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 17:21:32 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 14:40:36 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	start;
	size_t	total_len;
	char	*dest;

	if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	total_len = ft_strlen(s1) + ft_strlen(s2);
	if (!(dest = malloc(sizeof(char) * (total_len + 1))))
		return (NULL);
	i = 0;
	start = 0;
	while (s1[i])
	{
		dest[i] = (char)s1[i];
		i++;
	}
	while (s2[start])
		dest[i++] = (char)s2[start++];
	dest[i] = '\0';
	return (dest);
}

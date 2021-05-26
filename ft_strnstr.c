/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 10:18:26 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/10 20:32:03 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (*needle == '\0')
		return ((char *)haystack);
	else
	{
		i = 0;
		while (haystack[i] && i < len)
		{
			j = 0;
			while ((haystack[i + j] == needle[j]) && (i + j) < len)
			{
				j++;
				if (needle[j] == '\0')
					return ((char *)(haystack + i));
			}
			i++;
		}
	}
	return (0);
}

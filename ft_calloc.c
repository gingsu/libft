/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 15:56:15 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/21 14:40:46 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*dest;
	size_t	i;

	if (!(dest = malloc(sizeof(char) * (count * size))))
		return (NULL);
	i = 0;
	while (i < count * size)
		dest[i++] = 0;
	return ((void *)dest);
}

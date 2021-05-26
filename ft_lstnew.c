/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 14:23:11 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/12 14:25:56 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *dest;

	if (!(dest = malloc(sizeof(t_list))))
		return (NULL);
	dest->content = content;
	dest->next = NULL;
	return (dest);
}

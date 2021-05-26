/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyunlee <kyunlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 11:25:58 by kyunlee           #+#    #+#             */
/*   Updated: 2021/05/15 11:49:03 by kyunlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*dest;
	t_list	*temp;

	if (!lst || !(dest = ft_lstnew(f(lst->content))))
		return (NULL);
	temp = dest;
	lst = lst->next;
	while (lst != NULL)
	{
		if (!(temp->next = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&dest, del);
			return (NULL);
		}
		lst = lst->next;
		temp = temp->next;
	}
	return (dest);
}

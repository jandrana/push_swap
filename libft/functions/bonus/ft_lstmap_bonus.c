/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:58:27 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/13 18:24:31 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*start;
	t_list	*node;

	start = NULL;
	while (lst)
	{
		node = ft_lstnew(0);
		if (!node)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		node->content = f(lst->content);
		ft_lstadd_back(&start, node);
		lst = lst->next;
	}
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_init_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:34:15 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 12:37:02 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	stack_add(t_stack **a, int n)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	new_node->content = n;
	new_node->next = NULL;
	if (!(*a))
	{
		new_node->prev = NULL;
		*a = new_node;
	}
	else
	{
		stack_last_node(*a)->next = new_node;
		new_node->prev = stack_last_node(*a);
	}
}

void	stack_init(t_stack **a, char **nbrs)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (nbrs[i] != NULL)
	{
		n = ft_atol(nbrs[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			stack_free(a);
			print_error();
		}
		stack_add(a, (int)n);
		i++;
	}
}

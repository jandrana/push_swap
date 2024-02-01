/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 14:37:51 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 14:14:35 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_len(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (0);
	while (stack->next)
	{
		stack = stack->next;
		i++;
	}
	i++;
	return (i);
}

t_stack	*stack_last_node(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

t_stack	*max_stack(t_stack *stack)
{
	t_stack	*max_node;
	int		max_value;
	int		i;

	i = 1;
	max_value = stack->content;
	max_node = stack;
	while (++i <= stack_len(stack) + 1)
	{
		stack = stack->next;
		if (max_value < stack->content)
		{
			max_value = stack->content;
			max_node = stack;
		}
	}
	return (max_node);
}

t_stack	*min_stack(t_stack *stack)
{
	t_stack	*min_node;
	int		min_value;

	min_value = stack->content;
	min_node = stack;
	while (stack->next)
	{
		stack = stack->next;
		if (min_value > stack->content)
		{
			min_value = stack->content;
			min_node = stack;
		}
	}
	return (min_node);
}

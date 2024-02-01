/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 17:23:06 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 14:14:47 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	stack_is_sorted(t_stack	*stack)
{
	if (stack_len(stack) < 2)
		return (1);
	while (stack->next)
	{
		if (stack->content > stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	node_to_top_a(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper_side)
			ra(stack);
		else
			rra(stack);
		stack_index_side(*stack);
	}
}

void	node_to_top_b(t_stack *node, t_stack **stack)
{
	while (*stack != node)
	{
		if (node->is_upper_side)
			rb(stack);
		else
			rrb(stack);
		stack_index_side(*stack);
	}
}

void	stack_index_side(t_stack *stack)
{
	int	i;
	int	half;

	i = 0;
	half = (stack_len(stack) + 1) / 2;
	while (stack)
	{
		stack->index = ++i;
		stack->mid = half;
		if (i <= half)
		{
			stack->is_upper_side = 1;
			stack->dist_to_mid = half - i;
		}
		else
		{
			stack->is_upper_side = 0;
			stack->dist_to_mid = i - half;
		}
		stack = stack->next;
	}
}

t_stack	*stack_set_structure(t_stack *a, t_stack *b)
{
	stack_index_side(a);
	stack_index_side(b);
	stack_a_targets(a, b);
	return (stack_costs(a, b));
}

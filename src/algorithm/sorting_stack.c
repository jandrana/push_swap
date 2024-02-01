/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:28:40 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 14:20:12 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	limits_stack(int *min, int *max, t_stack *stack)
{
	int	i;
	int	min_value;
	int	max_value;

	i = 1;
	*min = 1;
	*max = 1;
	min_value = stack->content;
	max_value = stack->content;
	while (++i <= stack_len(stack) + 1)
	{
		stack = stack->next;
		if (min_value > stack->content)
		{
			min_value = stack->content;
			*min = i;
		}
		if (max_value < stack->content)
		{
			max_value = stack->content;
			*max = i;
		}
	}
	return (*min);
}

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		min;
	int		max;
	int		i;

	i = 0;
	tmp = (*stack);
	limits_stack(&min, &max, *stack);
	if (max == 1)
		ra(stack);
	else if ((min == 1) || (max == 3))
		sa(stack);
	else if (min == 3)
		rra(stack);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (stack_is_sorted(*a) && !b)
		return ;
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
	{
		while (!(stack_is_sorted(*a)))
			sort_three(a);
	}
	else if (!stack_is_sorted(*a))
		sort_big(a, b);
}

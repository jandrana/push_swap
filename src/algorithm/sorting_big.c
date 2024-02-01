/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:13:27 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 14:18:36 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	check_position(t_stack **a, t_stack *move)
{
	t_stack	*target;

	target = move->target;
	if (move->is_upper_side && !(target->is_upper_side))
	{
		if (target->index - move->index < target->mid)
			target->is_upper_side = 1;
	}
	else if (!(move->is_upper_side) && target->is_upper_side)
	{
		if ((target->index + stack_len(*a) - move->index) > target->mid)
			target->is_upper_side = 0;
	}
}

void	fill_b_stack(t_stack **a, t_stack **b, t_stack *move)
{
	check_position(a, move);
	if (move->is_upper_side && move->target->is_upper_side)
	{
		while (*a != move && *b != move->target)
			rr(a, b);
	}
	else if (!(move->is_upper_side) && !(move->target->is_upper_side))
	{
		while (*a != move && *b != move->target)
			rrr(a, b);
	}
	node_to_top_a(move, a);
	node_to_top_b(move->target, b);
	pb(a, b);
}

void	sorting_b(t_stack **a, t_stack **b)
{
	pb(a, b);
	if (stack_len(*a) > 3 && !stack_is_sorted(*a))
		pb(a, b);
	while (stack_len(*a) > 3 && !stack_is_sorted(*a))
	{
		stack_a_targets(*a, *b);
		fill_b_stack(a, b, stack_set_structure(*a, *b));
	}
}

void	sort_big(t_stack **a, t_stack **b)
{
	sorting_b(a, b);
	if (!stack_is_sorted(*a))
		sort_stack(a, b);
	while (*b)
	{
		stack_index_side(*a);
		stack_index_side(*b);
		stack_b_targets(*a, *b);
		node_to_top_a((*b)->target, a);
		pa(a, b);
	}
	node_to_top_a(min_stack(*a), a);
}

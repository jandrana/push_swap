/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_calculations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 11:38:18 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 12:43:56 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	stack_a_targets(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	closest;

	while (a)
	{
		closest = LONG_MIN;
		tmp = b;
		while (tmp)
		{
			if (a->content > tmp->content && tmp->content > closest)
			{
				closest = tmp->content;
				a->target = tmp;
			}
			tmp = tmp->next;
		}
		if (closest == LONG_MIN)
			a->target = min_stack(b);
		a = a->next;
	}
}

void	stack_b_targets(t_stack *a, t_stack *b)
{
	t_stack	*tmp;
	long	closest;

	while (b)
	{
		closest = LONG_MAX;
		tmp = a;
		while (tmp)
		{
			if (b->content < tmp->content && tmp->content < closest)
			{
				closest = tmp->content;
				b->target = tmp;
			}
			tmp = tmp->next;
		}
		if (closest == LONG_MAX)
			b->target = min_stack(a);
		b = b->next;
	}
}

void	calculate_costs(t_stack *a, t_stack *target, int s_len, int t_len)
{
	int	nba;
	int	nbt;

	nba = a->index;
	nbt = target->index;
	if (a->is_upper_side && (target->is_upper_side
			|| (nbt - nba < target->mid)))
		a->cost = mx(a->index, target->index);
	else if (!a->is_upper_side && (!target->is_upper_side
			|| (nbt + s_len - a->index) > target->mid))
		a->cost = mx(s_len - a->index + 1, t_len - target->index + 1);
	else if (a->is_upper_side)
		a->cost = a->index + (t_len - target->index + 1);
	else
		a->cost = (s_len - a->index + 1) + target->index;
}

t_stack	*stack_costs(t_stack *a, t_stack *b)
{
	t_stack	*cheapest;
	t_stack	*target;
	int		low_cost;
	int		a_len;
	int		b_len;

	low_cost = INT_MAX;
	a_len = stack_len(a);
	b_len = stack_len(b);
	while (a)
	{
		target = a->target;
		calculate_costs(a, target, a_len, b_len);
		if (a->cost < low_cost)
		{
			low_cost = a->cost;
			cheapest = a;
		}
		a = a->next;
	}
	return (cheapest);
}

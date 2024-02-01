/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 17:12:57 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/26 12:22:53 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*first;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = (*stack);
	first->prev = stack_last_node(*stack);
	stack_last_node(*stack)->next = first;
	*stack = (*stack)->next;
	first->next = NULL;
	(*stack)->prev = NULL;
}

void	ra(t_stack **a)
{
	ft_printf("ra\n");
	rotate(a);
}

void	rb(t_stack **b)
{
	ft_printf("rb\n");
	rotate(b);
}

void	rr(t_stack **a, t_stack **b)
{
	ft_printf("rr\n");
	rotate(a);
	rotate(b);
}

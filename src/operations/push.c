/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 13:49:50 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/25 17:03:55 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	push(t_stack **origin, t_stack **target)
{
	t_stack	*send;
	t_stack	*second_or;

	if (!(*origin))
		return ;
	send = (*origin);
	second_or = (*origin)->next;
	if (second_or)
		second_or->prev = NULL;
	if (!(*target))
		send->next = NULL;
	else
	{
		send->next = (*target);
		send->next->prev = send;
	}
	*origin = second_or;
	*target = send;
}

/*REVIEW PUSH FUNCTION*/

void	pa(t_stack **a, t_stack **b)
{
	ft_printf("pa\n");
	push(b, a);
}

void	pb(t_stack **a, t_stack **b)
{
	ft_printf("pb\n");
	push(a, b);
}

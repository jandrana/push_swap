/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:05:05 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/31 18:59:18 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

void	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

int	mx(int x, int y)
{
	if (x >= y)
		return (x);
	return (y);
}

void	stack_free(t_stack **stack)
{
	t_stack	*node;
	t_stack	*swp;

	if (!(stack))
		return ;
	node = *stack;
	while (node)
	{
		swp = node->next;
		node->content = 0;
		node->index = 0;
		node->cost = 0;
		node->is_upper_side = 0;
		if (node->target)
			node->target = NULL;
		free(node);
		node = swp;
	}
	*stack = NULL;
}

void	array_free(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

long	ft_atol_ps(char *str)
{
	long	i;
	long	negative;
	long	result;

	i = 0;
	negative = 0;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negative++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i])
		print_error();
	if (negative)
		result = -result;
	return (result);
}

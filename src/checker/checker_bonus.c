/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 13:57:14 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/12 13:45:02 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../libft/libft.h"

static void	rot(t_stack **a, t_stack **b, char *gnl)
{
	if (!ft_strncmp(gnl, "ra\n", 3))
		rotate(a);
	else if (!ft_strncmp(gnl, "rb\n", 3))
		rotate(b);
	else if (!ft_strncmp(gnl, "rr\n", 3))
	{
		rotate(a);
		rotate(b);
	}
	else if (!ft_strncmp(gnl, "rra\n", 4))
		rrotate(a);
	else if (!ft_strncmp(gnl, "rrb\n", 4))
		rrotate(b);
	else if (!ft_strncmp(gnl, "rrr\n", 4))
	{
		rrotate(a);
		rrotate(b);
	}
	else
		print_error();
}

static char	*movements(t_stack **a, t_stack **b, char *gnl)
{
	if (!ft_strncmp(gnl, "pa\n", 3))
		push(b, a);
	else if (!ft_strncmp(gnl, "pb\n", 3))
		push(a, b);
	else if (!ft_strncmp(gnl, "r", 1))
		rot(a, b, gnl);
	else if (!ft_strncmp(gnl, "sa\n", 3))
		swap(a);
	else if (!ft_strncmp(gnl, "sb\n", 3))
		swap(b);
	else if (!ft_strncmp(gnl, "ss\n", 3))
	{
		swap(a);
		swap(b);
	}
	else
		print_error();
	return (get_next_line(0));
}

static void	checker(t_stack **a, t_stack **b, char *gnl)
{
	char	*tmp;

	while (gnl)
	{
		tmp = gnl;
		gnl = movements(a, b, gnl);
		free(tmp);
	}
	if (*b || !stack_is_sorted(*a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(gnl);
}

int	main(int argc, char **argv)
{
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;
	char	*gnl;

	a = NULL;
	b = NULL;
	nbrs = 0;
	if (argc > 1)
	{
		process_input(argc, argv, nbrs, &a);
		gnl = get_next_line(0);
		if (!gnl && stack_is_sorted(a))
			write(1, "OK\n", 3);
		else if (!gnl && !stack_is_sorted(a))
			write(1, "KO\n", 3);
		else
			checker(&a, &b, gnl);
		stack_free(&a);
	}
	return (0);
}

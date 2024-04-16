/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:34 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/07 18:37:01 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/push_swap.h"

/* void	ft_leaks(void)
{
	system("leaks -q push_swap");
}
atexit(ft_leaks);
*/

int	main(int argc, char **argv)
{
	char	**nbrs;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	nbrs = 0;
	if (argc > 1)
		process_input(argc, argv, nbrs, &a);
	if (!stack_is_sorted(a))
		sort_stack(&a, &b);
	stack_free(&a);
	return (0);
}

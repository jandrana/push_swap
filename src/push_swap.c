/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 16:26:34 by ana-cast          #+#    #+#             */
/*   Updated: 2024/01/29 18:49:30 by ana-cast         ###   ########.fr       */
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

void	check_input(char **nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		ft_atol_ps(nbrs[i]);
		while (nbrs[j])
		{
			if (ft_atol(nbrs[i]) == ft_atol(nbrs[j]))
				print_error();
			j++;
		}
		i++;
	}
}

void	process_input(int argc, char **argv, char **nbrs, t_stack **a)
{
	if (argc == 2)
	{
		if (!argv[1][0] || ((argv[1][0] == '+'
			|| argv[1][0] == '-') && !argv[1][1]))
			print_error();
		nbrs = ft_split(argv[1], ' ');
	}
	else
		nbrs = (argv + 1);
	check_input(nbrs);
	stack_init(a, nbrs);
	if (argc == 2)
		array_free(nbrs);
}

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

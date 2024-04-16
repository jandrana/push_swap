/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_process_input.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 16:55:36 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/07 18:40:18 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft/libft.h"
#include "../../includes/push_swap.h"

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

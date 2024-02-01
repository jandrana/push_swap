/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 18:28:59 by ana-cast          #+#    #+#             */
/*   Updated: 2024/02/01 15:52:49 by ana-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file push_swap.h
 * @brief Function prototypes for the push_swap project
 *
 * This contains the prototypes fot the push_swap project
 * and the structure used by the stacks (double linked list)
 *
 * @author Ana Alejandra Castillejo Muñoz (github: jandrana)
 */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				index;
	int				cost;
	int				is_upper_side;
	int				dist_to_mid;
	int				mid;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

/**
 * @brief Depending on the initial number of arguments received by the main,
 * it processes the argv array into the nbrs array. After checking if the 
 * input is valid (check_input()), it initializes the stack a (stack_init())
 * @param argc int (nº of main arguments)
 * @param argv char ** (input received by main)
 * @param nbrs char ** (processed input)
 * @param a t_stack **
 * @return None
 */
void	process_input(int argc, char **argv, char **nbrs, t_stack **a);

/**
 * @brief Checks if the input passed when running the program is valid or not.
 * We consider the input of the program valid if: It only contains
 * numbers (integers) and there are no duplicates.
 * If the input is invalid the program exits after printing an Error message
 * through the standard error file (fd: 2).
 * @param nbrs array
 * @return None
 */
void	check_input(char **nbrs);

/**
 * @brief It checks that the stack contains at least two nodes and exchanges
 * the position of the first two elements of the stack passed as argument.
 * @param stack t_stack **
 * @return None
 */
void	swap(t_stack **stack);

/**
 * @brief It prints the move to be made ("sa") and calls swap() with stack
 * a as argument in order to exchange the first two elements of a.
 * @param a t_stack **
 * @return None
 */
void	sa(t_stack **a);

/**
 * @brief It prints the move to be made ("sb") and calls swap() with stack
 * b as argument in order to exchange the first to elements of b.
 * @param a t_stack **
 * @return None
 */
void	sb(t_stack **b);

/**
 * @brief It prints the move to be made ("ss") and calls swap() with stack a, 
 * and again with stack b. Making the swap move with both stacks.
 * @param a t_stack **
 * @return None
 */
void	ss(t_stack **a, t_stack **b);

/**
 * @brief It checks that the origin contains at least one element and moves it
 * to the first node of the target stack. Making the second node of origin become
 * the first one and the first node of target the second one (after the move). 
 * @param origin t_stack **
 * @param target t_stack **
 * @return None
 */
void	push(t_stack **origin, t_stack **target);

/**
 * @brief It prints the move to be made ("pa") and calls the push() function
 * with stack a as the target and stack b as the origin. Pushing the first node 
 * of stack b into stack a. Making the pushed node the new first node of stack a.
 * @param a t_stack **
 * @param b t_stack **
 * @return None
 */
void	pa(t_stack **a, t_stack **b);

/**
 * @brief It prints the move to be made ("pb") and calls the push() function
 * with stack b as the target and stack a as the origin. Pushing the first node 
 * of stack a into stack b. Making the pushed node the new first node of stack b.
 * @param a t_stack **
 * @param b t_stack **
 * @return None
 */
void	pb(t_stack **a, t_stack **b);

/**
 * @brief It rotates all the elements of the stack one position upwards. 
 * Making the first element become the last one and the second element become
 * the first one.
 * @param stack t_stack **
 * @return None
 */
void	rotate(t_stack **stack);

/**
 * @brief It prints the move to be made ("ra") and calls the rotate() function
 * with stack a as argument.
 * @param a t_stack **
 * @return None
 */
void	ra(t_stack **a);

/**
 * @brief It prints the move to be made ("rb") and calls the rotate() function
 * with stack b as argument.
 * @param b t_stack **
 * @return None
 */
void	rb(t_stack **b);

/**
 * @brief It prints the move to be made ("rr") and calls the rotate() function
 * with stack a as argument and again calls rotate() with stack b.
 * @param a t_stack **
 * @param b t_stack **
 * @return None
 */
void	rr(t_stack **a, t_stack **b);

/**
 * @brief It rotates all the elements of the stack one position downwards. 
 * Making the last element become the first one and the first element become
 * the second one.
 * @param stack t_stack **
 * @return None
 */
void	rrotate(t_stack **stack);

/**
 * @brief It prints the move to be made ("rra") and calls the rrotate() function
 * with stack a as argument.
 * @param a t_stack **
 * @return None
 */
void	rra(t_stack **a);

/**
 * @brief It prints the move to be made ("rrb") and calls the rrotate() function
 * with stack b as argument.
 * @param b t_stack **
 * @return None
 */
void	rrb(t_stack **b);

/**
 * @brief It prints the move to be made ("rrr") and calls the rrotate() function
 * with stack a as argument and again calls rrotate() with stack b.
 * @param a t_stack **
 * @param b t_stack **
 * @return None
 */
void	rrr(t_stack **a, t_stack **b);

/**
 * @brief This function is the one that decides which algorithm should be used
 * depending on the number of elements that stack a has. It also decides if it
 * should keep using an algorithm or not since it checks if the stack a is
 * already sorted or not.
 * @param a t_stack **
 * @param b t_stack **
 * @return None
 */
void	sort_stack(t_stack **a, t_stack **b);
void	sort_three(t_stack **a);

void	sort_big(t_stack **a, t_stack **b);
void	sorting_b(t_stack **a, t_stack **b);
void	fill_b_stack(t_stack **a, t_stack **b, t_stack *move);

void	stack_a_targets(t_stack *a, t_stack *b);
void	stack_b_targets(t_stack *a, t_stack *b);
void	calculate_costs(t_stack *a, t_stack *target, int a_len, int b_len);
t_stack	*stack_costs(t_stack *a, t_stack *b);

int		stack_is_sorted(t_stack	*stack);
void	node_to_top_b(t_stack *node, t_stack **stack);
void	node_to_top_a(t_stack *node, t_stack **stack);
void	stack_index_side(t_stack *stack);
t_stack	*stack_set_structure(t_stack *a, t_stack *b);

void	stack_init(t_stack **a, char	**nbrs);
void	stack_add(t_stack **a, int n);

int		stack_len(t_stack *stack);
t_stack	*stack_last_node(t_stack *stack);
t_stack	*max_stack(t_stack *stack);
t_stack	*min_stack(t_stack *stack);

void	print_error(void);
int		mx(int x, int y);
void	stack_free(t_stack **stack);
void	array_free(char **arr);
long	ft_atol_ps(char *str);

#endif /* PUSH_SWAP_H */

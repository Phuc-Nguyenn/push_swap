/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phunguye <phunguye@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 14:11:15 by phunguye          #+#    #+#             */
/*   Updated: 2022/12/06 16:04:50 by phunguye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/* is_sorted:
*	Checks if a stack is sorted.
*	Returns 0 if the stack is not sorted, 1 if it is sorted.
*/
int	is_sorted(t_stack *stack)
{
	while (stack->next != NULL)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

/* push_swap:
*	Chooses a sorting method depending on the number
*	of values to be sorted.
*/
void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size)
{
	if (stack_size == 2 && !is_sorted(*stack_a))
		do_sa(stack_a);
	else if (stack_size == 3)
		tiny_sort(stack_a);
	else if (stack_size > 3 && !is_sorted(*stack_a))
		sort(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	*tmp;

	if (ac < 2)
		return (0);
	if (ac == 2)
	{
		tmp = ft_strdup(av[1]);
		av = malloc((ft_wordcount(tmp, ' ') + 2) * sizeof(char *));
		av = ft_split(tmp, ' ');
		ac = ft_wordcount(tmp, ' ') + 1;
	}
	if (!input_correct_check(av))
		exit_error(NULL, NULL);
	stack_b = NULL;
	stack_a = stack_fill(ac, av);
	stack_size = get_stack_size(stack_a);
	assign_index(stack_a, stack_size + 1);
	push_swap(&stack_a, &stack_b, stack_size);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

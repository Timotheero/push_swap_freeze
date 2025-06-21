/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:09:17 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/21 00:20:10 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	free_exit(t_stack *stack)
{
	if (stack->stack_a)
		free(stack->stack_a);
	if (stack->stack_b)
		free(stack->stack_b);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*int_array;
	int		i;

	if (argc < 2)
		return (1);
	stack.len_a = argc - 1;
	stack.len_b = 0;
	stack.stack_a = malloc(stack.len_a * sizeof(int));
	stack.stack_b = calloc(stack.len_a, sizeof(int));
	if (!stack.stack_a || !stack.stack_b)
		return (free_exit(&stack));
	int_array = general_check_input(argc, argv);
	if (!int_array)
		return (free_exit(&stack));
	i = 0;
	while (i < stack.len_a)
	{
		stack.stack_a[i] = int_array[i];
		i++;
	}
	free(int_array);
	sort_stack(&stack);
	free(stack.stack_a);
	free(stack.stack_b);
	return (0);
}

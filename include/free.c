/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 23:45:56 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/07/01 15:15:26 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all_resources(t_stack *stack, int *int_array, char **split_array)
{
	free_stack(stack);
	if (int_array)
		free(int_array);
	if (split_array)
		ft_free_split(split_array);
}

void	free_stack(t_stack *stack)
{
	if (stack)
	{
		if (stack->stack_a)
			free(stack->stack_a);
		if (stack->stack_b)
			free(stack->stack_b);
	}
}

void	print_error_and_exit(t_stack *stack, int *int_array, char **split_array)
{
	free_all_resources(stack, int_array, split_array);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

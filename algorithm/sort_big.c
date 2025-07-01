/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:25:24 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/30 23:48:50 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	bubble_sort_array(int *array, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static void	replace_values_with_indices(t_stack *stack, int *sorted_copy)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->len_a)
	{
		j = 0;
		while (j < stack->len_a)
		{
			if (stack->stack_a[i] == sorted_copy[j])
			{
				stack->stack_a[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

static void	normalize_to_index(t_stack *stack)
{
	int	*sorted_copy;

	sorted_copy = malloc(stack->len_a * sizeof(int));
	if (!sorted_copy)
		print_error_and_exit(stack, NULL, NULL);
	copy_stack_to_array(stack, sorted_copy);
	bubble_sort_array(sorted_copy, stack->len_a);
	replace_values_with_indices(stack, sorted_copy);
	free(sorted_copy);
}

int	max_bits(t_stack *stack)
{
	int	max;
	int	bits;
	int	i;

	max = stack->stack_a[0];
	bits = 0;
	i = 1;
	while (i < stack->len_a)
	{
		if (stack->stack_a[i] > max)
			max = stack->stack_a[i];
		i++;
	}
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	k_sort(t_stack *stack)
{
	int	bits;
	int	size;
	int	i;
	int	j;

	normalize_to_index(stack);
	bits = max_bits(stack);
	size = stack->len_a;
	i = 0;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stack->stack_a[0] >> i) & 1) == 0)
				pb_push(stack);
			else
				ra_rotate(stack);
			j++;
		}
		while (stack->len_b > 0)
			pa_push(stack);
		i++;
	}
}

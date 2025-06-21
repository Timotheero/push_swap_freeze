/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:12:55 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/20 23:15:45 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->len_a != 3)
		return ;
	a = stack->stack_a[0];
	b = stack->stack_a[1];
	c = stack->stack_a[2];
	if (a > b && b < c && a < c)
		sa_swap(stack);
	else if (a > b && b > c && a > c)
	{
		sa_swap(stack);
		rra_rrotate(stack);
	}
	else if (a > b && b < c && a > c)
		ra_rotate(stack);
	else if (a < b && b > c && a < c)
	{
		sa_swap(stack);
		ra_rotate(stack);
	}
	else if (a < b && b > c && a > c)
		rra_rrotate(stack);
}

int	find_min_index(t_stack *stack)
{
	int	i;
	int	min_idx;
	int	min_val;

	if (!stack || stack->len_a == 0)
		return (-1);
	i = 0;
	min_idx = 0;
	min_val = stack->stack_a[0];
	while (i < stack->len_a)
	{
		if (stack->stack_a[i] < min_val)
		{
			min_val = stack->stack_a[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}

void	sort_small(t_stack *stack)
{
	int	min_pos;
	int	moves;

	while (stack->len_a > 3)
	{
		min_pos = find_min_index(stack);
		moves = 0;
		if (min_pos <= stack->len_a / 2)
		{
			while (moves++ < min_pos)
				ra_rotate(stack);
		}
		else
		{
			while (moves++ < (stack->len_a - min_pos))
				rra_rrotate(stack);
		}
		pb_push(stack);
	}
	sort_three(stack);
	while (stack->len_b > 0)
		pa_push(stack);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	if (!stack || stack->len_a <= 1)
		return (1);
	i = 0;
	while (i < stack->len_a - 1)
	{
		if (stack->stack_a[i] > stack->stack_a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sort_stack(t_stack *stack)
{
	if (!stack || stack->len_a <= 1)
		return ;
	if (is_sorted(stack))
		return ;
	if (stack->len_a == 2)
	{
		if (stack->stack_a[0] > stack->stack_a[1])
			sa_swap(stack);
	}
	else if (stack->len_a == 3)
		sort_three(stack);
	else if (stack->len_a <= 5)
		sort_small(stack);
	else
		k_sort(stack);
}

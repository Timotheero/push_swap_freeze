/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:12:55 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/12 18:12:55 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack *stack)
{
	int	a, b, c;
	
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

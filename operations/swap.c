/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:22:04 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/05 17:22:04 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap"


//sa	swap a	swaps the 2 top elements of stack a
int sa_swap(t_stack *stack)
{
	int temp;

	temp  = stack -> stack_a[0];
	stack -> stack_a[0] = stack->stack_a [1];
	stack ->stack_a[1] = temp;
	ft_printf("sa\n");
	return(0);
}

//sb	swap b	swaps the 2 top elements of stack b
int sb_swap(t_stack *stack)
{
	int temp;

	temp  = stack -> stack_b[0];
	stack -> stack_b[0] = stack->stack_b [1];
	stack ->stack_b[1] = temp;
	ft_printf("sb\n");
	return(0);
}

//ss	swap a + swap b	both sa and sb
int ss_swap(t_stack *stack)
{
	sa_swap( stack);
	sb_swap( stack);
	ft_printf("ss\n");
	return(0);
}
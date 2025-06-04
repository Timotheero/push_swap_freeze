/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:02 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/04 16:14:02 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//sa	swap a	swaps the 2 top elements of stack a
int ft_sa_swap(t_stack *stack)
{
	int temp;

	temp  = stack -> stack_a[0];
	stack -> stack_a[0] = stack->stack_a [1];
	stack ->stack_a[1] = temp;
	ft_printf("sa\n");
	return(0);
}

//sb	swap b	swaps the 2 top elements of stack b
int ft_sb_swap(t_stack *stack)
{
	int temp;

	temp  = stack -> stack_b[0];
	stack -> stack_b[0] = stack->stack_b [1];
	stack ->stack_b[1] = temp;
	ft_printf("sb\n");
	return(0);
}

//ss	swap a + swap b	both sa and sb
int ft_ss_swap(t_stack *stack)
{
	ft_sa_swap( stack);
	ft_sb_swap( stack);
	ft_printf("ss\n");
	return(0);
}

//pa	push a	moves the top element of stack b at the top of stack a
int ft_pa_push(t_stack *stack)
{
	if (stack->len_b == 0)
		return (0);
	memmove(&stack->stack_a[1], &stack->stack_a[0], stack->len_a * sizeof(int));
	stack->stack_a[0] = stack->stack_b[0];
	memmove(&stack->stack_b[0], &stack->stack_b[1], (stack->len_b - 1) * sizeof(int));
	stack->len_a++;
	stack->len_b--;
	ft_printf("pa\n");
	return (0);
}

//pb	push b	moves the top element of stack a at the top of stack b
int ft_pb_push(t_stack *stack)
{
	if (stack->len_a == 0)
		return (0);
	memmove(&stack->stack_b[1], &stack->stack_b[0], stack->len_b * sizeof(int));
	stack->stack_a[0] = stack->stack_b[0];
	memmove(&stack->stack_a[0], &stack->stack_a[1], (stack->len_a - 1) * sizeof(int));
	stack->len_a--;
	stack->len_b++;
	ft_printf("pb\n");
	return (0);
}

//ra	rotate a	shifts all elements of stack a from bottom to top
int ft_pb_push(t_stack *stack)
{
	int temp;

	if (stack -> len_a <= 1)
		return(0);
	temp = stack -> stack_a[0]

	memmove(&stack -> stack_a[0], &stack -> stack_a[1], (stack -> -1) * sizeof(int));
	stack -> stack_a[stack -> len_a -1] = temp;
	ft_printf("ra\n");
	return(0);
}


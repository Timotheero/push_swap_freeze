/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:28:04 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/05 17:28:04 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


//pa	push a	moves the top element of stack b at the top of stack a
int pa_push(t_stack *stack)
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
int pb_push(t_stack *stack)
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
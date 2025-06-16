/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 16:14:02 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/16 15:37:02 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// ra	rotate a	shifts all elements of stack a from bottom to top
int	ra_rotate(t_stack *stack)
{
	int	temp;

	if (stack->len_a <= 1)
		return (0);
	temp = stack->stack_a[0];
	memmove(&stack->stack_a[0], &stack->stack_a[1], (stack->len_a - 1)
		* sizeof(int));
	stack->stack_a[stack->len_a - 1] = temp;
	ft_printf("ra\n");
	return (0);
}

// rb	rotate b	shifts all elements of stack b from bottom to top
int	rb_rotate(t_stack *stack)
{
	int	temp;

	if (stack->len_a <= 1)
		return (0);
}

// rr	rotate a + rotate b	both ra and rb
int	rr_rotate(t_stack *stack)
{
	ra_rotate(stack);
	rb_rotate(stack);
	return (0);
}

// rra	reverse rotate a	shifts all elements of stack a from top to bottom
int	rra_rrotate(t_stack *stack)
{
	int	temp;

	if (stack->len_a <= 1)
		return (0);
	temp = stack->stack_a[stack->len_a - 1];
	memmove(&stack->stack_a[1], &stack->stack_a[0], (stack->len_a - 1)
		* sizeof(int));
	stack->stack_a[0] = temp;
	ft_printf("rra\n");
	return (0);
}

// rrb	reverse rotate b	shifts all elements of stack b from top to bottom
int	rrb_rotate(t_stack *stack)
{
	int	temp;

	if (stack->len_b <= 1)
		return (0);
	temp = stack->stack_b[stack->len_b - 1];
	memmove(&stack->stack_b[1], &stack->stack_b[0], (stack->len_b - 1)
		* sizeof(int));
	stack->stack_b[0] = temp;
	ft_printf("rrb\n");
	return (0);
}

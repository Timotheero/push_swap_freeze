/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrr_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:14:56 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/16 15:15:50 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// rrr	reverse rotate a + reverse rotate b	both rra and rrb
int	rrr_rotate(t_stack *stack)
{
	rra_rotate(stack);
	rrb_rotate(stack);
	return (0);
}

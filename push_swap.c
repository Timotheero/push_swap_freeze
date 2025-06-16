/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:09:17 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/04 15:09:17 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	free_exit(t_stack *stack)
{
	free(stack ->stack_a);
	free(stack ->stack_b);
	return(0);
}

int main(int argc, char **argv)
{
    t_stack stack;
	int i;

	i = 0;
    stack.len_a = argc - 1;
    stack.len_b = 0;
    stack.stack_a = malloc(stack.len_a * sizeof(int));
	stack.stack_b = calloc(stack.len_a, sizeof(int));
    if (!stack.stack_a || !stack.stack_b)
        return (free_exit(&stack)  1);
	stack.stack_a = general_check_input(int argc, char **argv);
	printf("[");
	while(argc >= 1)
    {
        printf("%d", array[i]);
        if (i < size - 1)
            printf(", ");
        i++;
    }
    printf("]\n");
    return (free_exit(t_stack));
}


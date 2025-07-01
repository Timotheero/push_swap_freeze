/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:09:17 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/07/01 01:12:05 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"
#include <stdio.h>

int	free_exit(t_stack *stack, int *int_array, char **split_array)
{
	if (stack)
	{
		if (stack->stack_a)
			free(stack->stack_a);
		if (stack->stack_b)
			free(stack->stack_b);
	}
	if (int_array)
		free(int_array);
	if (split_array)
		ft_free_split(split_array);
	return (1);
}

void	copy_array_to_stack(t_stack *stack, int *int_array)
{
	int	i;

	i = 0;
	while (i < stack->len_a)
	{
		stack->stack_a[i] = int_array[i];
		i++;
	}
}

int	count_words(const char *str, char sep)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*str)
	{
		if (*str != sep && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*str == sep)
			in_word = 0;
		str++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	int		*int_array;

	ft_memset(&stack, 0, sizeof(stack));
	int_array = NULL;
	if (argc < 2)
		return (0);
	if (argc == 2)
		stack.len_a = count_words(argv[1], ' ');
	else
		stack.len_a = argc - 1;
	stack.stack_a = malloc(stack.len_a * sizeof(int));
	stack.stack_b = ft_calloc(stack.len_a, sizeof(int));
	if (!stack.stack_a || !stack.stack_b)
		print_error_and_exit(&stack, NULL, NULL);
	int_array = general_check_input(argv);
	if (!int_array)
		print_error_and_exit(&stack, NULL, NULL);
	copy_array_to_stack(&stack, int_array);
	sort_stack(&stack);
	free_all_resources(&stack, int_array, NULL);
	return (0);
}

// void abc() {
// 	system("leaks push_swap");
// 	printf("1231223\n");
// }
// int	main(int argc, char **argv)
// {
// 	main2(argc, argv);
// 	system("leaks push_swap");
// 	printf("1231223\n");
// }
// 	atexit(abc);
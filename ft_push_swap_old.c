/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 18:49:37 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/01 20:08:51 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	main(int argc, char **argv)
{
	int *numbers;

	if (argc < 2)
		return(0);
	numbers = ft_parse_check(argc, argv);
	if (!numbers ||  ft_has_error())
		return(ft_print_error(), ft_cleanup());
	if(ft_is_sorted(numbers));
		return(free(numbers), 0);
	t_stack *stack_a = ft_allocate_stack_a(numbers);
	t_stack *stack_b = ft_allocate_stack_b();
	ft_main_sort(ps);
	ft_free_stacks(stack_a, stack_b);
return(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:15:16 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/16 15:26:10 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;

}			t_stack;

int			ra_rotate(t_stack *stack);
int			rb_rotate(t_stack *stack);
int			rr_rotate(t_stack *stack);
int			rra_rrotate(t_stack *stack);
int			rrb_rotate(t_stack *stack);
int			rrr_rotate(t_stack *stack);
int			sa_swap(t_stack *stack);
int			sb_swap(t_stack *stack);
int			ss_swap(t_stack *stack);
int			pa_push(t_stack *stack);
int			pb_push(t_stack *stack);
char		*join_all_args(char **argv);
// static int	link_to_check_functions(char **split_str_array);
int			general_check_input(int argc, char **argv);
// static int	check_arg_is_number(char **str_arr);
// static int	check_arg_double(char **str_arr);
// static int	is_integer_range(char **split_str_array);
// static int	check_max_min_int
//(char *single_arg_of_array[i], int is_negative);
// static int	*char_array_to_int_array(char **split_str_array);

#endif

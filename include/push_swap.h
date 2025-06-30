/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:15:16 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/30 01:16:45 by tdietz-r         ###   ########.fr       */
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
	int	*stack_a;
	int	*stack_b;
	int	len_a;
	int	len_b;

}		t_stack;

int		ra_rotate(t_stack *stack);
int		rb_rotate(t_stack *stack);
int		rr_rotate(t_stack *stack);
int		rra_rrotate(t_stack *stack);
int		rrb_rotate(t_stack *stack);
int		rrr_rotate(t_stack *stack);
int		sa_swap(t_stack *stack);
int		sb_swap(t_stack *stack);
int		ss_swap(t_stack *stack);
int		pa_push(t_stack *stack);
int		pb_push(t_stack *stack);
char	*join_all_args(char **argv);
void	k_sort(t_stack *stack);
int		*general_check_input(char **argv);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
void	*ft_memmove(void *dst, const void *src, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		check_arg_is_number(char **str_arr);
int		check_arg_double(char **str_arr);
int		is_integer_range(char **split_str_array);
int		check_max_min_int(char *single_arg_of_array, int is_negative);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_free_split(char **split);
int		*char_array_to_int_array(char **split_str_array);
void	sort_stack(t_stack *stack);
void	copy_stack_to_array(t_stack *stack, int *sorted_copy);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		count_words(const char *str, char sep);
void	*ft_calloc(size_t count, size_t size);
void	print_error_and_exit(void);

#endif

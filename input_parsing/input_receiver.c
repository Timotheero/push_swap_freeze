/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_receiver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:38:59 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/30 03:14:24 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*join_all_args(char **argv)
{
	char	*combined_str_of_args;
	char	*temp;
	int		i;

	if (!argv || !argv[1])
		print_error_and_exit();
	combined_str_of_args = ft_strdup(argv[1]);
	if (!combined_str_of_args)
		print_error_and_exit();
	i = 1;
	while (argv[++i])
	{
		temp = ft_strjoin(combined_str_of_args, " ");
		free(combined_str_of_args);
		combined_str_of_args = temp;
		if (!combined_str_of_args)
			print_error_and_exit();
		temp = ft_strjoin(combined_str_of_args, argv[i]);
		free(combined_str_of_args);
		combined_str_of_args = temp;
		if (!combined_str_of_args)
			print_error_and_exit();
	}
	return (combined_str_of_args);
}

void	ft_free_split(char **split)
{
	int	i;

	if (!split)
		return ;
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	link_to_check_functions(char **split_str_array)
{
	if (check_arg_is_number(split_str_array))
		return (1);
	if (is_integer_range(split_str_array))
		return (1);
	if (check_arg_double(split_str_array))
		return (1);
	return (0);
}

static int	*process_and_validate(char **split_array)
{
	int	*final_int_array;

	if (!split_array || link_to_check_functions(split_array))
	{
		ft_free_split(split_array);
		return (NULL);
	}
	final_int_array = char_array_to_int_array(split_array);
	ft_free_split(split_array);
	if (!final_int_array)
		return (NULL);
	return (final_int_array);
}

int	*general_check_input(char **argv)
{
	char	*input_str;
	char	**split_str_array;
	int		*result;

	input_str = NULL;
	split_str_array = NULL;
	result = NULL;
	if (!argv[1])
		print_error_and_exit();
	input_str = (!argv[2]) ? ft_strdup(argv[1]) : join_all_args(argv);
	if (!input_str)
		print_error_and_exit();
	split_str_array = ft_split(input_str, ' ');
	if (!split_str_array)
	{
		free(input_str);
		print_error_and_exit();
	}
	result = process_and_validate(split_str_array);
	free(input_str);
	if (!result)
		print_error_and_exit();
	return (result);
}

// int	*general_check_input(char **argv)
// {
// 	char	*combined_str_of_args;
// 	char	**split_str_array;
// 	int		*final_int_array;

// 	if (!argv[1])
// 		return (NULL);
// 	combined_str_of_args = join_all_args(argv);
// 	if (!combined_str_of_args)
// 		return (NULL);
// 	split_str_array = ft_split(combined_str_of_args, ' ');
// 	if (!split_str_array)
// 	{
// 		free(combined_str_of_args);
// 		return (NULL);
// 	}
// 	if (link_to_check_functions(split_str_array))
// 	{
// 		free(combined_str_of_args);
// 		ft_free_split(split_str_array);
// 		return (NULL);
// 	}
// 	final_int_array = char_array_to_int_array(split_str_array);
// 	if (!final_int_array)
// 	{
// 		free(combined_str_of_args);
// 		ft_free_split(split_str_array);
// 		return (NULL);
// 	}
// 	free(combined_str_of_args);
// 	ft_free_split(split_str_array);
// 	return (final_int_array);
// }
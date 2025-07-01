/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_receiver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:38:59 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/07/01 14:58:40 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char	*join_all_args(char **argv)
{
	char	*combined_str;
	char	*temp;
	int		i;

	if (!argv || !argv[1])
		print_error_and_exit(NULL, NULL, NULL);
	combined_str = ft_strdup(argv[1]);
	if (!combined_str)
		print_error_and_exit(NULL, NULL, NULL);
	i = 1;
	while (argv[++i])
	{
		temp = ft_strjoin(combined_str, " ");
		free(combined_str);
		if (!temp)
			print_error_and_exit(NULL, NULL, NULL);
		combined_str = temp;
		temp = ft_strjoin(combined_str, argv[i]);
		free(combined_str);
		if (!temp)
			print_error_and_exit(NULL, NULL, NULL);
		combined_str = temp;
	}
	return (combined_str);
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

	split_str_array = NULL;
	result = NULL;
	input_str = NULL;
	if (!argv[1])
		print_error_and_exit(NULL, NULL, NULL);
	if (argv[2])
		input_str = join_all_args(argv);
	else
		input_str = ft_strdup(argv[1]);
	if (!input_str)
		print_error_and_exit(NULL, NULL, NULL);
	split_str_array = ft_split(input_str, ' ');
	if (!split_str_array)
	{
		free(input_str);
		print_error_and_exit(NULL, NULL, NULL);
	}
	result = process_and_validate(split_str_array);
	free(input_str);
	return (result);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_receiver.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 16:38:59 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/08 16:38:59 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


char	*join_all_args(char **argv)
{
	char	*combined_str_of_args;
	char	*temp;
	int		i;

	if (!argv || !argv[1])
		return (NULL);
	combined_str_of_args = ft_strdup(argv[1]);
	if (!combined_str_of_args)
		return (NULL);
	i = 1;
	while (argv[++i])
	{
		temp = ft_strjoin(combined_str_of_args, " ");
		free(combined_str_of_args);
		combined_str_of_args = temp;
		if (!combined_str_of_args)
			return (NULL);
		temp = ft_strjoin(combined_str_of_args, argv[i]);
		free(combined_str_of_args);
		combined_str_of_args = temp;
		if (!combined_str_of_args)
			return (NULL);
	}
	return (combined_str_of_args);
}

//not checked general_check_input
static int link_to_check_functions(char** split_str_array)
{
	if (check_arg_is_number( split_str_array))
		return(1);
	if (is_integer_range( split_str_array))
		return(1);
	if (check_arg_double(split_str_array))
		return(1);
	if (char_array_to_int_array(split_str_array))
		return(1);
	return(0);
}

int	general_check_input(int argc, char **argv)
{
	char *combined_str_of_args;
	char **split_str_array;
	int *final_int_array;
	if (!argv[1])
        return (1);
	if (argc >= 2)
	{
		combined_str_of_args = join_all_args(*argv);
		if (!combined_str_of_args)
			return(1);
	}
	else 
		combined_str_of_args = argv[1];
	split_str_array = ft_split(combined_str_of_args);
	if (!split_str_array)
		return(1);
	if (link_to_check_functions(split_str_array))
		return(1);
	final_int_array = char_array_to_int_array( split_str_array);
	if (!final_int_array)
		return(1);
	free(combined_str_of_args);
	ft_free_split(split_str_array);
	return (final_int_array);
}

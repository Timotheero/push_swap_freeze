/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:30:07 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/05 17:30:07 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"


static int	check_arg_is_number(char **str_arr)
{
	int	i;
	int	j;

	if (!str_arr)
		return (1);
	i = -1;
	while (str_arr[++i])
	{
		j = 0;
		if (!str_arr[i][j])
			return (1);
		if ((str_arr[i][j] == '+' || str_arr[i][j] == '-') && !str_arr[i][++j])
			return (1);
		while (str_arr[i][j])
		{
			if (!ft_isdigit(str_arr[i][j]) || j++ > 10)
				return (1);
		}
	}
	return (0);
}

static int check_arg_double(char **split_str_array)
{
    int i;
    int j;

    i = 0;
    while (split_str_array[i])
    {
        j = i + 1;
        while (split_str_array[j])
        {
            if (ft_atoi(split_str_array[i]) == ft_atoi(split_str_array[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}


char *join_all_args(char *argv)
{
	char *combined_str_of_args;
	char *temp;
	int i;
	
	combined_str_of_args = ft_strdup(argv[1]);
	i = 2;
	
	while (argv[i])
	{
		temp = ft_strjoin(combined_str_of_args, " ");
		free(combined_str_of_args);
		combined_str_of_args = temp;
		
		temp = ft_strjoin(combined_str_of_args, argv[i]);
		free(combined_str_of_args);
		combined_str_of_args = temp;
		
		i++;
	}
	return (combined_str_of_args);
}

static int is_integer_range(char **split_str_array)
{
    int i;
    int j;
    int len;
    int is_negative;
    
    i = 0;
    while (split_str_array[i])
    {
        j = 0;
        is_negative = (split_str_array[i][0] == '-');
        if (split_str_array[i][j] == '-' || split_str_array[i][j] == '+')
            j++;
        while (split_str_array[i][j] == '0')
            j++;
        len = 0;
        while (split_str_array[i][j + len])
            len++;
        if (len > 10)
            return (1);
        if (len == 10)
			if (check_max_min_int(&split_str_array[i], is_negative ))
				return(1);
        i++;
    }
    return (0);  
}

static int check_max_min_int(char *single_arg_of_array[i], int is_negative )
{
	if (is_negative && ft_strcmp(&single_arg_of_array[i][1], "2147483648") > 0)
		return (1); 
	if (!is_negative && ft_strcmp(&single_arg_of_array[i][0], "2147483647") > 0)
		return (1);
	return(0);
}




static int  *char_array_to_int_array(char **split_str_array)
{
	int *int_array;
    int i;
    int size;

    size = 0;
    while (str_array[size])
        size++;
    int_array = (int *)malloc(sizeof(int) * size);
    if (!int_array)
        return (NULL);
    i = 0;
    while (i < size)
    {
        int_array[i] = ft_atoi(str_array[i]);
        i++;
    }

    return (int_array);
}


static int link_to_check_functions(char** split_str_array)
{
	if (check_arg_is_number( split_str_array))
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

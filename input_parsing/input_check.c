/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdietz-r <tdietz-r@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 13:16:40 by tdietz-r          #+#    #+#             */
/*   Updated: 2025/06/20 23:38:38 by tdietz-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	check_arg_is_number(char **str_arr)
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

int	check_arg_double(char **str_arr)
{
	int	i;
	int	j;

	if (!str_arr)
		return (1);
	i = -1;
	while (str_arr[++i])
	{
		j = i;
		while (str_arr[++j])
		{
			if (ft_atoi(str_arr[i]) == ft_atoi(str_arr[j]))
				return (1);
		}
	}
	return (0);
}

int	check_max_min_int(char *single_arg_of_array, int is_negative)
{
	if (is_negative && ft_strcmp(single_arg_of_array + 1, "2147483648") > 0)
		return (1);
	if (!is_negative && ft_strcmp(single_arg_of_array, "2147483647") > 0)
		return (1);
	return (0);
}

int	is_integer_range(char **split_str_array)
{
	int	i;
	int	j;
	int	len;
	int	is_negative;

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
			if (check_max_min_int(split_str_array[i], is_negative))
				return (1);
		i++;
	}
	return (0);
}

int	*char_array_to_int_array(char **split_str_array)
{
	int	*int_array;
	int	i;
	int	size;

	size = 0;
	while (split_str_array[size])
		size++;
	int_array = (int *)malloc(sizeof(int) * size);
	if (!int_array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		int_array[i] = ft_atoi(split_str_array[i]);
		i++;
	}
	return (int_array);
}

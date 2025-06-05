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



/* arg_is_number:
*   Checks if the argument is a number. +1 1 and -1 are all valid numbers.
*   Return: 1 if the argument is a number, 0 if not.
*/
//check if argument is a valid number

static int	check_arg_is_number(char *argv)
{
    int i;

    i = 0;
    if (argv[i] == '+' || argv[i] == '-')
        i++;
    if (argv[i] == '\0')
        return(1);
        
    while(argv[i])
    {
        if (!ft_isdigit(argv[i]))
            return(1);
        i++;
    }
    return(0);
}

static int	check_arg_double(char **argv)
{
	int i;
    int j;

    i = 1; 
    while (argv[i])
    {
        j = i + 1;
        while (argv[j])
        {
            if (ft_atoi(argv[i]) == ft_atoi(argv[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int	check_arg_is_zero(char *argv)
{
    if (ft_atoi(argv) == 0)
        return (1);
    return (0);
}

char *join_all_args(char **argv)
{
	char *result;
	char *temp;
	int i;

	if (!argv[1])
		return (NULL);
	
	result = ft_strdup(argv[1]);
	i = 2;
	
	while (argv[i])
	{
		temp = ft_strjoin(result, " ");
		free(result);
		result = temp;
		
		temp = ft_strjoin(result, argv[i]);
		free(result);
		result = temp;
		
		i++;
	}
	return (result);
}

static int is_integer_range()
{

	return(0);
}

static int link_to_check_functions()
{
	if (check_arg_is_number( argv))
		return(1);
	if (check_arg_is_zero(argv))
		return(1);
	if (check_arg_double( *argv))
		return(1);
	return(0);
}

int	general_check_input(int argc, char **argv)
{
	char *combined_str_of_args;
	int arg_is_combined;

	arg_is_combined = 0;

	 if (!argv[1])
        return (1)
	if (argc >= 2)
	{
		combined_str_of_args = join_all_args(*argv);
		if (!combined_args)
			return(1);
		arg_is_combined = 1;
		if (!ft_isdigit(combined_str_of_args))
			return(1);
	}
	else 
	{
		if (!ft_isdigit(argv[i]));
			return(1);
	}
	if (link_to_check_functions(combined_str_of_args))
		return(1);
	if (arg_is_combined == 1 && )
	return (0);
}


char **ft_split(char const *s, char c);
ft_strchr

argc = 0 -> error (main funktion check)
argc = 1 -> pass to check
argc >= 2 -> pass to split

string 


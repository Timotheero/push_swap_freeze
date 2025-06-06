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

static int	check_arg_is_number(char *combined_str_of_args)
{
    int i;

    i = 0;
    if (combined_str_of_args[i] == '+' || combined_str_of_args[i] == '-')
        i++;
    if (combined_str_of_args[i] == '\0')
        return(1);
        
    while(combined_str_of_args[i])
    {
        if (!ft_isdigit(combined_str_of_args[i]))
            return(1);
        i++;
    }
    return(0);
}

static int	check_arg_double(char **combined_str_of_args)
{
	int i;
    int j;

    i = 1; 
    while (combined_str_of_args[i])
    {
        j = i + 1;
        while (combined_str_of_args[j])
        {
            if (ft_atoi(combined_str_of_args[i]) == ft_atoi(combined_str_of_args[j]))
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

static int	check_arg_is_zero(char *combined_str_of_args)
{
    if (ft_atoi(combined_str_of_args) == 0)
        return (1);
    return (0);
}

char *join_all_args(char *argv)
{
	char *combined_str_of_args;
	char *temp;
	int i;

	if (!argv[1])
		return (NULL);
	
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

static int is_integer_range()
{

	return(0);
}

static int link_to_check_functions(char* combined_str_of_args)
{
	if (check_arg_is_number( combined_str_of_args))
		return(1);
	if (check_arg_is_zero(combined_str_of_args))
		return(1);
	if (check_arg_double(combined_str_of_args))
		return(1);
	return(0);
}

int	general_check_input(int argc, char **argv)
{
	char *combined_str_of_args;

	if (!argv[1])
        return (1)
	if (argc >= 2)
	{
		combined_str_of_args = join_all_args(*argv);
		if (!combined_str_of_args)
			return(1);
	}
	else 
		combined_str_of_args = argv[1];
	if (link_to_check_functions(combined_str_of_args))
		return(1);				
	return (0);
}
		

		if (!ft_isdigit(argv[i]));
		return(1);
		if (!ft_isdigit(combined_str_of_args))
	return(1);

char **ft_split(char const *s, char c);
ft_strchr

argc = 0 -> error (main funktion check)
argc = 1 -> pass to check
argc >= 2 -> pass to split

string 


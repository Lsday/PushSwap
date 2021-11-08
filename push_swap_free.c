/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:58:45 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:04:50 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks, char **splited_args)
{
	free(stacks->stack_a.elems);
	free(stacks->stack_b.elems);
	if (splited_args)
		free_split(splited_args);
}

void	free_split(char **splited_args)
{
	int	i;

	i = 0;
	while (splited_args[i])
	{
		free(splited_args[i++]);
	}
}

int	check_args(int argc, char ***splited_args, char **args)
{
	if (argc < 2)
		return (0);
	else if (argc == 2)
	{
		*splited_args = ft_split(args[1], ' ');
		return (1);
	}
	else if (argc >= 3)
		return (1);
	return (0);
}	

int	check_if_valid(char **arrays, int *count)
{
	int	i;

	i = 0;
	while (arrays[i])
	{
		if (!is_input_valid(arrays[i++]))
			return (0);
	}	
	*count = i;
	return (1);
}

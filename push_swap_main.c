/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:16:15 by oronda            #+#    #+#             */
/*   Updated: 2021/11/15 18:05:28 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_chunks(t_chunks *chunks, t_stacks *stacks)
{
	t_median	t_median;
	int			temp_chunk_count;

	if (stacks->stack_a.capacity >= 10 && stacks->stack_a.capacity < 100)
		temp_chunk_count = 3;
	else if (stacks->stack_a.capacity >= 99 && stacks->stack_a.capacity < 400)
		temp_chunk_count = 5;
	else if (stacks->stack_a.capacity >= 400)
		temp_chunk_count = 11;
	else
		temp_chunk_count = 1;
	chunks = create_chunks(chunks, temp_chunk_count);
	if (!chunks)
		return (0);
	find_median(stacks->stack_a.elems, stacks->stack_a.capacity, &t_median);
	fill_chunks(chunks, stacks, &t_median);
	return (1);
}

void	fill_chunks(t_chunks *chunks, t_stacks *stacks, t_median *t_median)
{
	int	i;
	int	slice;

	slice = stacks->stack_a.capacity / chunks->chunks_count;
	i = 0;
	while (i < chunks->chunks_count)
	{
		chunks->chunks[i].range_min = t_median->sorted_tab[slice * i];
		chunks->chunks[i].range_max = t_median->sorted_tab[slice * i + slice];
		i++;
	}
	chunks->chunks[0].range_min = get_min_nb(&stacks->stack_a);
	chunks->chunks[i - 1].range_max = get_max_nb(&stacks->stack_a);
}

t_chunks	*create_chunks(t_chunks *chunks, int number)
{
	chunks->chunks = malloc(sizeof(t_chunk) * number);
	chunks->chunks_count = number;
	return (chunks);
}

void	solve(t_stacks *stacks, int count)
{	
	if (count == 2)
	{
		if (stacks->stack_a.elems[0] > stacks->stack_a.elems[1])
		{
			sa(stacks);
			return ;
		}
	}
	else if (count == 3)
		solve3_a(stacks);
	else if (count > 3 && count <= 5)
		solve_5(stacks);
	else if (count > 5 && count < 100)
		solve_5_500(stacks);
	else if (count >= 100)
		solve_5_500(stacks);
}

int	main(int argc, char *argv[])
{
	int			count;
	t_stacks	stacks;
	char		**splited_args;

	splited_args = NULL;
	if (!check_args(argc, &splited_args, argv))
		return (0);
	if (splited_args)
		argv = splited_args;
	else
		argv++;
	if (!check_if_valid(argv, &count))
		return (print_error());
	if (!init_stack(&stacks, count))
		return (0);
	fill_stack(argv, &stacks.stack_a);
	if (have_duplicate(&stacks.stack_a))
		return (print_error());
	if (is_sorted(&stacks.stack_a))
		return (0);
	solve(&stacks, count);
	free_all(&stacks, splited_args);
	return (0);
}

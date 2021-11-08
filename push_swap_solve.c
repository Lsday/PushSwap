/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solve.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:07:32 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:05:21 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	solve_5_500(t_stacks *stacks)
{
	t_chunks	t_chunks;
	int			index_temp;
	int			chunck_index;

	if (!init_chunks(&t_chunks, stacks))
		return ;
	chunck_index = t_chunks.chunks_count;
	while (chunck_index)
	{
		chunck_index--;
		while (1)
		{
			if (!smart_rotate(stacks, &t_chunks, chunck_index))
				break ;
			pb(stacks);
		}
		while (stacks->stack_b.count != 0)
		{
			index_temp = get_index(&stacks->stack_b,
					get_max_nb(&stacks->stack_b));
			mv_nb_top_b(stacks, index_temp);
			pa(stacks);
		}
	}
	free(t_chunks.chunks);
}

void	solve_5(t_stacks *stacks)
{
	int		index_temp;

	if (is_sorted(&stacks->stack_a))
		return ;
	while (stacks->stack_a.count != 3)
	{
		index_temp = get_index(&stacks->stack_a, get_min_nb(&stacks->stack_a));
		mv_nb_top_a(stacks, index_temp);
		pb(stacks);
	}
	if (!is_sorted(&stacks->stack_a))
		solve3_a(stacks);
	while (stacks->stack_b.count != 0)
	{
		index_temp = get_index(&stacks->stack_b, get_max_nb(&stacks->stack_b));
		mv_nb_top_b(stacks, index_temp);
		pa(stacks);
	}
}

void	solve3_a(t_stacks *stacks)
{
	t_stack	*stack;

	if (is_sorted(&stacks->stack_a))
		return ;
	stack = &stacks->stack_a;
	if (stack->elems[0] > stack->elems[1] && stack->elems[0] < stack->elems[2])
		sa(stacks);
	else if (stack->elems[0] > stack->elems[1] && stack->elems[0]
		> stack->elems[2] && stack->elems[1] > stack->elems[2])
	{
		sa(stacks);
		rra(stacks);
	}
	else if (stack->elems[0] > stack->elems[1] && stack->elems[0]
		> stack->elems[2] && stack->elems[1] < stack->elems[2])
		ra(stacks);
	else if (stack->elems[0] < stack->elems[1]
		&& stack->elems[0] < stack->elems[2])
	{
		sa(stacks);
		ra(stacks);
	}
	else if (stack->elems[0] < stack->elems[1]
		&& stack->elems[0] > stack->elems[2])
		rra(stacks);
}

void	solve3_b(t_stacks *stacks)
{
	t_stack	*stack;

	stack = &stacks->stack_b;
	if (stack->elems[0] > stack->elems[1] && stack->elems[0] < stack->elems[2])
		sb(stacks);
	else if (stack->elems[0] > stack->elems[1] && stack->elems[0]
		> stack->elems[2] && stack->elems[1] > stack->elems[2])
	{
		sb(stacks);
		rrb(stacks);
	}
	else if (stack->elems[0] > stack->elems[1] && stack->elems[0]
		> stack->elems[2] && stack->elems[1] < stack->elems[2])
		rb(stacks);
	else if (stack->elems[0] < stack->elems[1]
		&& stack->elems[0] < stack->elems[2])
	{
		sb(stacks);
		rb(stacks);
	}
	else if (stack->elems[0] < stack->elems[1]
		&& stack->elems[0] > stack->elems[2])
		rrb(stacks);
}

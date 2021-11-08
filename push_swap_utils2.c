/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:01:16 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:03:06 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

void	mv_nb_top(t_stacks *stacks, int index, t_stack_type type)
{
	int		mid;
	int		nb;
	t_stack	stack;

	if (type == STACK_A)
		stack = stacks->stack_a;
	else
		stack = stacks->stack_b;
	nb = stack.elems[index];
	mid = stack.count / 2;
	if (index >= mid)
	{
		reverse_rot(stacks, type, nb);
	}
	else if (index <= mid)
	{
		while (stack.elems[0] != nb)
		{
			if (stack.type == STACK_A)
				ra(stacks);
			if (stack.type == STACK_B)
				rb(stacks);
		}
	}
}

void	reverse_rot(t_stacks *stacks, t_stack_type type, int nb)
{
	t_stack	stack;

	if (type == STACK_A)
		stack = stacks->stack_a;
	else
		stack = stacks->stack_b;
	while (stack.elems[0] != nb)
	{
		if (stack.type == STACK_A)
			rra(stacks);
		if (stack.type == STACK_B)
			rrb(stacks);
	}
}

void	rot(t_stacks *stacks, t_stack_type type, int nb)
{
	t_stack	stack;

	if (type == STACK_A)
		stack = stacks->stack_a;
	else
		stack = stacks->stack_b;
	while (stack.elems[0] != nb)
	{
		if (stack.type == STACK_A)
			ra(stacks);
		if (stack.type == STACK_B)
			rb(stacks);
	}
}

void	mv_nb_top_a(t_stacks *stacks, int index)
{
	mv_nb_top(stacks, index, STACK_A);
}

void	mv_nb_top_b(t_stacks *stacks, int index)
{
	mv_nb_top(stacks, index, STACK_B);
}

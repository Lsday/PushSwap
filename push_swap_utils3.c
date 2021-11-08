/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:04:53 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:04:52 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	get_min_nb(t_stack *stack)
{
	int	i;
	int	min;

	i = 1;
	min = stack->elems[0];
	while (i < stack->count)
	{
		if (stack->elems[i] < min)
			min = stack->elems[i];
		i++;
	}
	return (min);
}

int	get_max_nb(t_stack *stack)
{
	int	i;
	int	max;

	i = 1;
	max = stack->elems[0];
	while (i < stack->count)
	{
		if (stack->elems[i] > max)
			max = stack->elems[i];
		i++;
	}
	return (max);
}

void	find_median(int *tab, int size, t_median *t_median)
{
	int	i;

	i = 0;
	while (i <= size - 1)
	{
		t_median->sorted_tab[i] = tab[i];
		i++;
	}
	i = 1;
	while (i <= size - 1)
	{
		if (t_median->sorted_tab[i - 1] > t_median->sorted_tab[i])
		{
			ft_swap(&t_median->sorted_tab[i], &t_median->sorted_tab[i - 1]);
			i = 0;
		}
		i++;
	}
	t_median->median = t_median->sorted_tab[size / 2];
}

int	smart_rotate(t_stacks *stacks, t_chunks *t_chunks, int chunck_index)
{
	int	index_first;
	int	index_second;

	index_first = scan_from_top(&stacks->stack_a,
			t_chunks->chunks[chunck_index]);
	index_second = scan_from_bot(&stacks->stack_a,
			t_chunks->chunks[chunck_index]);
	if (index_first < 0 && index_second < 0)
		return (0);
	if (index_first < index_second - stacks->stack_a.count - 1
		|| index_second == -1)
		mv_nb_top_a(stacks, index_first);
	else
		mv_nb_top_a(stacks, index_second);
	if (stacks->stack_b.count >= 2)
		mv_nb_top_b(stacks, get_index(&stacks->stack_b,
				get_min_nb(&stacks->stack_b)));
	return (1);
}

int	get_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (i < stack->count)
	{
		if (stack->elems[i] == nb)
			return (i);
		i++;
	}
	return (0);
}

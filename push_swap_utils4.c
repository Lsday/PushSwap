/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:05:06 by oronda            #+#    #+#             */
/*   Updated: 2021/11/06 10:11:35 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	scan_from_top(t_stack *stack, t_chunk chunk)
{
	int	i;

	i = 0;
	while (i < (stack->count / 2) + 1)
	{
		if (stack->elems[i] >= chunk.range_min
			&& stack->elems[i] <= chunk.range_max)
			return (i);
		i++;
	}
	return (-1);
}

//return the index of the scanned number in range, not the nb itself
int	scan_from_bot(t_stack *stack, t_chunk chunk)
{
	int	i;

	i = stack->count - 1;
	while (i > (stack->count / 2))
	{
		if (stack->elems[i] >= chunk.range_min
			&& stack->elems[i] <= chunk.range_max)
			return (i);
		i--;
	}
	return (-1);
}

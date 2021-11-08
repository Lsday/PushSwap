/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 11:45:36 by oronda            #+#    #+#             */
/*   Updated: 2021/11/06 10:06:26 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	is_stack_full(t_stack *stack)
{
	return (stack->capacity == stack->count);
}

int	is_stack_empty(t_stack *stack)
{
	return (stack->count == 0);
}

void	shrink_up(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count)
	{
		stack->elems[i] = stack->elems[i + 1];
		i++;
	}
	stack->count--;
}

void	grow_down(t_stack *stack)
{	
	int	i;

	if (stack->count >= stack->capacity)
		return ;
	stack->count++;
	i = 0;
	while (i < stack->count)
	{
		stack->elems[stack->count - 1 - i] = stack->elems[stack->count - i - 2];
		i++;
	}
}

int	find_smallest_position(t_stack *stack)
{
	int	i;
	int	min_index;
	int	min;

	i = 1;
	min = stack->elems[0];
	while (i < stack->count)
	{
		if (stack->elems[i] < min)
		{
			min = stack->elems[i];
			min_index = i;
		}
	}
	return (min_index);
}

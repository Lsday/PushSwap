/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rrotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:24:50 by oronda            #+#    #+#             */
/*   Updated: 2021/11/02 15:30:25 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static void	r_rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->elems[stack->count - 1];
	while (i < stack->count - 1)
	{
		stack->elems[stack->count - 1 - i] = stack->elems[stack->count - i - 2];
		i++;
	}
	stack->elems[0] = temp;
}

void	rra(t_stacks *stacks)
{
	r_rotate(&stacks->stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stacks *stacks)
{
	r_rotate(&stacks->stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stacks *stacks)
{
	r_rotate(&stacks->stack_a);
	r_rotate(&stacks->stack_b);
	ft_putstr_fd("rrr\n", 1);
}

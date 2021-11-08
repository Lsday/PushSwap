/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:28:30 by oronda            #+#    #+#             */
/*   Updated: 2021/11/05 10:43:52 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_stack *stack);

void	ra(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stacks *stacks)
{
	rotate(&stacks->stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stacks *stacks)
{
	rotate(&stacks->stack_a);
	rotate(&stacks->stack_b);
	ft_putstr_fd("rr\n", 1);
}

static void	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	i = 0;
	temp = stack->elems[0];
	while (i < stack->count - 1)
	{
		stack->elems[i] = stack->elems[i + 1];
		i++;
	}
	stack->elems[stack->count - 1] = temp;
}

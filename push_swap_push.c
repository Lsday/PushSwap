/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:16:55 by oronda            #+#    #+#             */
/*   Updated: 2021/11/02 15:33:08 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack *src, t_stack *dest)
{
	int	temp;

	if (is_stack_empty(src))
		return ;
	temp = src->elems[0];
	shrink_up(src);
	grow_down(dest);
	dest->elems[0] = temp;
}

void	pa(t_stacks *stacks)
{
	push(&stacks->stack_b, &stacks->stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stacks *stacks)
{
	push(&stacks->stack_a, &stacks->stack_b);
	ft_putstr_fd("pb\n", 1);
}

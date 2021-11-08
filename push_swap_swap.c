/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 15:27:01 by oronda            #+#    #+#             */
/*   Updated: 2021/11/04 11:27:36 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static	void	swap(t_stack *stack);

void	sa(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stacks *stacks)
{
	swap(&stacks->stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stacks *stacks)
{
	swap(&stacks->stack_a);
	swap(&stacks->stack_b);
	ft_putstr_fd("ss\n", 1);
}

static	void	swap(t_stack *stack)
{
	if (stack->count < 2)
		return ;
	ft_swap(&(stack->elems[0]), &(stack->elems[1]));
}

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

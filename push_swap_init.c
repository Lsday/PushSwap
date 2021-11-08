/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 13:53:33 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 14:46:56 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_stack(t_stacks *stacks, int capacity)
{
	stacks->stack_a.elems = (int *)malloc(sizeof(int *) * capacity);
	stacks->stack_b.elems = (int *)malloc(sizeof(int *) * capacity);
	if (!stacks->stack_b.elems)
		return (0);
	stacks->stack_a.capacity = capacity;
	stacks->stack_b.capacity = capacity;
	stacks->stack_a.count = 0;
	stacks->stack_b.count = 0;
	stacks->stack_a.type = STACK_A;
	stacks->stack_b.type = STACK_B;
	return (1);
}

void	fill_stack(char **argv, t_stack *stack)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		stack->elems[i] = ft_atoi(argv[i]);
		stack->count += 1;
		i++;
	}
}

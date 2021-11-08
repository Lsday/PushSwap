/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:16:39 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:41:21 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

int	print_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

int	is_input_valid(char *str)
{
	long	nb;

	nb = ft_atol(str);
	while (*str)
	{
		if (!ft_isdigit(*str))
			if (*str != '-')
				return (0);
		str++;
	}
	if (nb > INT_MAX || nb < INT_MIN)
		return (0);
	return (1);
}

int	have_duplicate(t_stack *stack)
{
	int	i;
	int	y;

	i = 0;
	while (i < stack->capacity)
	{
		y = i + 1;
		while (y < stack->capacity)
		{
			if (stack->elems[i] == stack->elems[y])
			{
				return (1);
			}
			y++;
		}
		i++;
	}
	return (0);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->count - 1)
	{
		if (stack->elems[i + 1] < stack->elems[i])
		{
			return (0);
		}
		i++;
	}
	return (1);
}

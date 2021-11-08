/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oronda <oronda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 09:16:42 by oronda            #+#    #+#             */
/*   Updated: 2021/11/08 16:03:49 by oronda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef enum e_stack_type
{
	STACK_A,
	STACK_B
}	t_stack_type;

typedef struct s_stack
{
	int				*elems;
	int				count;
	int				capacity;
	t_stack_type	type;

}			t_stack;

typedef struct s_stacks
{
	t_stack	stack_a;
	t_stack	stack_b;

}			t_stacks;

typedef struct s_chunk
{
	int	range_min;
	int	range_max;
}	t_chunk;

typedef struct s_chunks
{
	t_chunk	*chunks;
	int		chunks_count;
}	t_chunks;

typedef struct s_median
{
	int		sorted_tab[1000];
	int		median;
}	t_median;

//INIT
int			init_stack(t_stacks *staks, int capacity);
void		fill_stack(char **argv, t_stack *stack);

//OPERAT	IONS
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);

void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);
void		rr(t_stacks *stacks);

void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rrr(t_stacks *stacks);

void		grow_down(t_stack *stack);
void		shrink_up(t_stack *stack);

void		solve3(t_stacks *stacks);

//ERRORS	
int			print_error(void);
int			is_input_valid(char *str);
int			have_duplicate(t_stack *stack);
int			is_sorted(t_stack *stack);

//Utils	
int			is_stack_full(t_stack *stack);
int			is_stack_empty(t_stack *stack);
int			find_smallest(t_stack *stack);
void		mv_nb_top(t_stacks *stacks, int index, t_stack_type type);
int			get_min_nb(t_stack *stack);
int			get_max_nb(t_stack *stack);
void		ft_swap(int *a, int *b);
void		find_median(int *tab, int size, t_median *t_median);
int			scan_from_top(t_stack *stack, t_chunk chunk);
int			scan_from_bot(t_stack *stack, t_chunk chunk);
void		solve3_a(t_stacks *stacks);
void		mv_nb_top_a(t_stacks *stacks, int index);
void		mv_nb_top_b(t_stacks *stacks, int index);
int			get_index(t_stack *stack, int nb);
t_chunks	*create_chunks(t_chunks *chunks, int number);
int			init_chunks(t_chunks *chunks, t_stacks *stacks);
void		fill_chunks(t_chunks *chunks, t_stacks *stacks, t_median *t_median);
int			smart_rotate(t_stacks *stacks, t_chunks *t_chunks,
				int chunck_index);
void		rot(t_stacks *stacks, t_stack_type type, int nb);
void		reverse_rot(t_stacks *stacks, t_stack_type type, int nb);
void		solve3_b(t_stacks *stacks);
void		solve3_a(t_stacks *stacks);
void		solve_5(t_stacks *stacks);
void		solve_5_500(t_stacks *stacks);
void		solve(t_stacks *stacks, int count);
void		free_all(t_stacks *stacks, char **splited_args);
void		free_split(char **splited_args);
int			check_args(int argc, char ***splited_args, char **args);
int			check_if_valid(char **arrays, int *count);

#endif
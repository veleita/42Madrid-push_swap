/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:09:16 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 17:51:15 by elopez-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <checker.h>
#include <instructions.h>

static bool	found(long *ordered_stack, int bottom_index, int top_index, int num)
{
	while (bottom_index < top_index)
	{
		if (num == ordered_stack[bottom_index])
			return (true);
		bottom_index++;
	}
	return (false);
}

static void	rotate_to_win(int distance, char *instruction, void (rotate)(long*),
		long *stack)
{
	while (--distance >= 0)
	{
		rotate(stack);
		ft_putstr(instruction);
	}
}

static void	find_in_chunk(long *ordered_stack, int bottom_index, int top_index,
		long *stack)
{
	int	dist_from_head;
	int	dist_from_tail;
	int	last;

	dist_from_head = 0;
	dist_from_tail = 1;
	last = get_last(stack);
	while (found(ordered_stack, bottom_index, top_index,
			stack[dist_from_head]) == false)
		dist_from_head++;
	while (found(ordered_stack, bottom_index, top_index,
			stack[last - dist_from_tail + 1]) == false)
		dist_from_tail++;
	if (dist_from_head < dist_from_tail - 1)
		rotate_to_win(dist_from_head, "ra\n", do_the_rot, stack);
	else
		rotate_to_win(dist_from_tail, "rra\n", do_the_revrot, stack);
}

static void	search_and_push(int chunk_size, int stack_size, t_stacks *stacks,
								long *ordered_stack)
{
	int		top_index;
	int		bottom_index;
	int		push;

	bottom_index = 0;
	top_index = chunk_size;
	while (top_index <= stack_size)
	{
		push = 0;
		while (push < chunk_size)
		{
			find_in_chunk(ordered_stack, bottom_index, top_index, stacks->a);
			do_the_push(stacks->a, stacks->b, stacks->size);
			ft_putstr("pb\n");
			push++;
		}
		top_index += chunk_size;
		bottom_index += chunk_size;
	}
}

void	divide_chunks(t_stacks *stacks)
{
	int		stack_size;
	int		chunk_size;
	int		n_chunks;
	long	*ordered_stack;

	stack_size = get_stack_size(stacks->a);
	n_chunks = 1;
	chunk_size = stack_size / n_chunks;
	while (chunk_size > (n_chunks * 3))
	{
		n_chunks++;
		chunk_size = stack_size / n_chunks;
	}
	ordered_stack = order_stack(stacks->a, stack_size);
	search_and_push(chunk_size, stack_size, stacks, ordered_stack);
	while (is_empty(stacks->a, stacks->size) == false)
	{
		do_the_push(stacks->a, stacks->b, stacks->size);
		ft_putstr("pb\n");
	}
	free(ordered_stack);
	return ;
}

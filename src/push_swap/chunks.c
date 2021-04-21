/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:09:16 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/21 20:43:18 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

int		get_chunk_size(long *stack, int stack_size)
{
	int chunk_size;
	int n_chunks;

	n_chunks = 1;
	chunk_size = stack_size / n_chunks;
	while (chunk_size > (n_chunks * 10))
	{
		n_chunks++;
		chunk_size = stack_size / n_chunks;
	}
	return (chunk_size);
}

static bool push_to_b(t_stacks *stacks, long num, int *pushes)
{
	if (stacks->a[0] == num)
	{
		do_the_push(stacks->a, stacks->b);
		*pushes++;
		ft_putstr("pb\n");
		return (true);
	}
	else
		return (false);
}

static void	search_and_push(int chunk_size, int stack_size, t_stacks *stacks)
{
	int		top_index;
	int		bottom_index;
	int		stack_index;
	int		pushes;
	bool	pushed;
	
	bottom_index = 0;
	top_index = chunk_size;
	while (top_index < stack_size)
	{
		pushed = false;
		bottom_index = top_index - chunk_size;
		index = bottom_index;
		while (index < top_index && pushed == false)
		{
			pushed = push_to_b(stacks, ordered_stack[index], &pushes);
			index++;
		}
		if (pushed == false)
			do_the_rot(stacks->a);
		if (pushes == stack_size)
		{
			top_index += chunk_size;
			pushes = 0;
		}
	}
}

void	divide_chunks(t_stacks *stacks)
{
	int		stack_size;
	int		chunk_size;
	long	*ordered_stack;

	stack_size = get_stack_size(stacks->a);
	chunk_size = get_chunk_size(stacks->a, stack_size);
	ordered_stack = order_stack(stacks->a);
	search_and_push(chunk_size, stack_size, stacks)
}

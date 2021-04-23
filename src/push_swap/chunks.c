/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 21:09:16 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 14:06:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <chunks.h>
#include <checker.h>
#include <instructions.h>

static int	get_chunk_size(int stack_size)
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

static bool push_to_b(t_stacks *stacks, long num)
{
	if (stacks->a[0] == num)
	{
		do_the_push(stacks->a, stacks->b, stacks->size);
		ft_putstr("pb\n");
		ft_putstr(ft_itoa(num));
		ft_putchar('\n');
		return (true);
	}
	else
		return (false);
}

static void	search_and_push(int chunk_size, int stack_size, t_stacks *stacks,
								long *ordered_stack)
{
	int		top_index;
	int		bottom_index;
	int		index;
	int		push;
	
	bottom_index = 0;
	top_index = chunk_size;
	push = 0;
	ft_putstr("Bottom: ");
	ft_putstr(ft_itoa(bottom_index));
	ft_putchar('\n');
	ft_putstr("Top: ");
	ft_putstr(ft_itoa(top_index));
	ft_putchar('\n');
	ft_putstr("-------------------\n");
	while (top_index < stack_size)
	{
		index = bottom_index;
		while (index < top_index &&
				push_to_b(stacks, ordered_stack[index]) == false)
			index++;
		if (index == top_index)
		{
			do_the_rot(stacks->a);
			ft_putstr("ra\n");
		}
		else if (++push == chunk_size)
		{
			top_index += chunk_size;
			bottom_index += chunk_size;
			push = 0;
			ft_putstr("Bottom: ");
			ft_putstr(ft_itoa(bottom_index));
			ft_putchar('\n');
			ft_putstr("Top: ");
			ft_putstr(ft_itoa(top_index));
			ft_putchar('\n');
			ft_putstr("-------------------\n");
		}
	}
}

void	divide_chunks(t_stacks *stacks)
{
	int		stack_size;
	int		chunk_size;
	long	*ordered_stack;

	stack_size = get_stack_size(stacks->a);
	chunk_size = get_chunk_size(stack_size);
	ordered_stack = order_stack(stacks->a, stack_size);
	search_and_push(chunk_size, stack_size, stacks, ordered_stack);
}

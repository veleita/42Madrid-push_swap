/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:04:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/09 17:31:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>

static void	insert_in_a(t_stacks *stacks, int stack_size, int next)
{
	long	*ordered_stack;
	int		dist_from_head;
	int		dist_from_tail;

	next = ordered_stack[stack_size - 1];
	dist_from_head = get_dist_from_head(stacks->b, next);
	dist_from_tail = get_dist_from_tail(stacks->b, next);
	if (dist_from_head < dist_from_tail)
	{
		while (stacks->b[0] != next)
		{
			do_the_rot(stacks->b);
			ft_putstr("rb\n");
		}
	}
	else
	{
		while (stacks->b[0] != next)
		{
			do_the_revrot(stacks->b);
			ft_putstr("rrb\n");
		}
	}
	do_the_push(stacks->b, stacks->a, stacks->size);
	ft_putstr("pa\n");
}

void		normal_insertion(t_stacks *stacks, int stack_size)
{
	int 	next;

	divide_chunks(stacks);
	ordered_stack = order_stack(stacks->b, stack_size);
	while (is_empty(stacks->b, stacks->size) == false)
		insert_in_a(stacks, get_stack_size(stacks->b), next);
}

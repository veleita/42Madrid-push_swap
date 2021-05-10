/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_algorithm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 14:04:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/10 17:45:18 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>

static void	insert_in_a(t_stacks *stacks, int next)
{
	int		dist_from_head;
	int		dist_from_tail;

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
	long	*ordered_stack;
	int 	next;
//	int		it = 4;

	divide_chunks(stacks);
	while (is_empty(stacks->b, stacks->size) == false)
//	while (it--)
	{
		stack_size = get_stack_size(stacks->b);
		ordered_stack = order_stack(stacks->b, stack_size);
		next = ordered_stack[stack_size - 1];
		insert_in_a(stacks, next);
	}
}

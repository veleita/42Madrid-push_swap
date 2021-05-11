/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 16:04:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 18:20:55 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>

static void	last_element(t_stacks *stacks)
{
	do_the_push(stacks->b, stacks->a, stacks->size);
	ft_putstr("pb\n");
	do_the_revrot(stacks->a);
	ft_putstr("rra\n");
}

static void	put_in_its_place(t_stacks *stacks, long *ordered_stack, int	it)
{
	int		dist_from_head;
	int		dist_from_tail;

	if (it == stacks->size - 1)
		last_element(stacks);
	else
	{
		dist_from_head = get_dist_from_head(stacks->a, ordered_stack[it + 1]);
		dist_from_tail = get_dist_from_tail(stacks->a, ordered_stack[it + 1]);
		while (stacks->a[0] != ordered_stack[it + 1])
		{
			if (dist_from_head < dist_from_tail)
			{
				do_the_rot(stacks->a);
				ft_putstr("ra\n");
			}
			else
			{
				do_the_revrot(stacks->a);
				ft_putstr("rra\n");
			}
		}
		do_the_push(stacks->b, stacks->a, stacks->size);
		ft_putstr("pa\n");
	}
}

static void	final_rotate(long *stack, long *ordered_stack)
{
	int		dist_from_head;
	int		dist_from_tail;

	dist_from_head = get_dist_from_head(stack, ordered_stack[0]);
	dist_from_tail = get_dist_from_tail(stack, ordered_stack[0]);
	while (stack[0] != ordered_stack[0])
	{
		if (dist_from_head < dist_from_tail)
		{
			do_the_rot(stack);
			ft_putstr("ra\n");
		}
		else
		{
			do_the_revrot(stack);
			ft_putstr("rra\n");
		}
	}
}

void	order_five(t_stacks *stacks)
{
	long	*ordered_stack;
	int		it;
	int		repeat;

	repeat = 2;
	ordered_stack = order_stack(stacks->a, stacks->size);
	do_the_push(stacks->a, stacks->b, stacks->size);
	ft_putstr("pb\n");
	do_the_push(stacks->a, stacks->b, stacks->size);
	ft_putstr("pb\n");
	order_three(stacks->a);
	while (repeat-- > 0)
	{
		if (stacks->b[0] < stacks->b[1])
		{
			do_the_swap(stacks->b);
			ft_putstr("sb\n");
		}
		it = 0;
		while (stacks->b[0] != ordered_stack[it])
			it++;
		put_in_its_place(stacks, ordered_stack, it);
	}
	final_rotate(stacks->a, ordered_stack);
	free(ordered_stack);
}

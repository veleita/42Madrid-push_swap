/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 18:23:24 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/25 13:44:15 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static bool	does_a_actually_need(long *stack, int size)
{
	int		n;

	n = 0;
	while (n++ < size - 2)
	{
		if (stack[n + 1] > stack[n + 2])
			return (true);
	}
	return (false);
}

void	ask_rotate(t_stacks *stacks, char priority)
{
	bool a_needs;
	bool b_needs;

	a_needs = does_a_actually_need(stacks->a, stacks->size);
	b_needs = ((stacks->b[0] < stacks->b[1]) && (stacks->b[0] < stacks->b[2]));
	if (priority == 'a' && a_needs == true)
	{
		do_the_rot(stacks->a);
		if (b_needs == true)
		{
			do_the_rot(stacks->b);
			ft_putstr("rr\n");
		}
		else
			ft_putstr("ra\n");
	}
	else if (priority == 'b' && b_needs == true)
	{
		do_the_rot(stacks->b);
		if (a_needs == true)
		{
			do_the_rot(stacks->a);
			ft_putstr("rr\n");
		}
		else
			ft_putstr("rb\n");
	}
}

void	ask_rev_rotate(t_stacks *stacks, char priority, int chunk_size)
{
	bool a_needs;
	bool b_needs;
	int  last;
	(void)chunk_size;

	last = get_last(stacks->a); 
	a_needs = ((stacks->a[last] < stacks->a[1]) && (stacks->a[last] > stacks->a[0]));
	last = get_last(stacks->b); 
	b_needs = (stacks->b[last] > stacks->b[0]);
	if (priority == 'a' && a_needs == true)
	{
		do_the_revrot(stacks->a);
		if (b_needs == true)
		{
			do_the_revrot(stacks->b);
			ft_putstr("rrr\n");
		}
		else
			ft_putstr("rra\n");
	}
	else if (priority == 'b' && b_needs == true)
	{
		do_the_revrot(stacks->b);
		if (a_needs == true)
		{
			do_the_revrot(stacks->a);
			ft_putstr("rrr\n");
		}
		else
			ft_putstr("rrb\n");
	}
}

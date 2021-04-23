/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/23 17:22:43 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>

static void	ask_push(t_stacks *stacks, char priority)
{
	if (stacks->a[0] > stacks->b[0])
	{
		if (priority == 'a' || stacks->a[0] < stacks->a[1])
		{
			do_the_push(stacks->b, stacks->a, stacks->size);
			ft_putstr("pa\n");
		}
	}
}

void		push_swap(t_stacks *stacks)
{
	char priority;
	int	 it = 10;

	divide_chunks(stacks);
	while (is_ordered(stacks->a, stacks->size) == false &&
			is_empty(stacks->b, stacks->size) == false && it > 0)
	{
		priority = set_priority(stacks);
		ask_push(stacks, priority);
		it--;
	}
//	ask_swap(stacks, priority);
//	ask_rotate(stacks, priority);
//	ask_rev_rotate(stacks, priority);
	ft_putstr("END\n");
	return ;
}

int		main(int argc, char **argv)
{
	t_stacks	*stacks;

	stacks = args_cooker(argc, 0, argv);
	if (!stacks)
		return (-1);
	push_swap(stacks);
	return (0);
}

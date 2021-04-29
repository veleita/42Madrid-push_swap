/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/29 17:23:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>

void		find_biggest_pair(long *stack)
{
	int bigger;
	int second;
	int it;

	bigger = INT_MIN;
	second = INT_MIN;
	it = 0;
	while (stack[it] != VOID)
	{
		if (stack[it] > bigger)
			bigger = stack[it];
		else if (stack[it] > second)
			second = stack[it];
		it++;
	}
}

void		push_swap(t_stacks *stacks)
{
	long	*main_stack;
	long	*secondary_stack;
	int		chunk_size;
//	int	 it = 2;

	chunk_size = divide_chunks(stacks);
	while ((is_ordered(stacks->a, stacks->size) == false ||
			is_empty(stacks->b, stacks->size) == false))
	{
		if (set_priority(stacks) == 'a')
		{
			main_stack = stacks->a;
			secondary_stack = stacks->b;
		}
		else
		{
			main_stack = stacks->b;
			secondary_stack = stacks->a;
		}
		find_biggest_pair(main_stack);
		/*
		ask_push(stacks, priority);
		ask_swap(stacks, priority);
		ask_rev_rotate(stacks, priority, chunk_size);
		ask_swap(stacks, priority);
		ask_rotate(stacks, priority);
		it--;*/
	}
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

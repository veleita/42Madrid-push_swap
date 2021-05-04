/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:29:47 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/04 19:09:26 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static bool	check_dups(long *ordered_stack, int aux_it, int num)
{
	bool 	dup;

	dup = false;
	while (aux_it >= 0)
	{
		if (ordered_stack[aux_it] == num)
		{
			dup = true;
			break ;
		}
		aux_it--;
	}
	return (dup);
}

long	*order_stack(long *stack, int stack_size)
{
	long	*ordered_stack;
	int		ordered_stack_it;
	int		stack_it;
	int		next;

	ordered_stack = (long*)malloc(sizeof(long) * stack_size);
	ordered_stack_it = -1;
	while (ordered_stack_it++ < stack_size)
		ordered_stack[ordered_stack_it] = VOID;
	ordered_stack_it = -1;
	while (++ordered_stack_it < stack_size)
	{
		stack_it = 0;
		next = stack[0];
		while (stack[++stack_it] != VOID)
		{
			if (stack[stack_it] < next &&
					check_dups(ordered_stack, ordered_stack_it, stack[stack_it]) == false)
					next = stack[stack_it];
		}
		ordered_stack[ordered_stack_it] = next;
	}
	return (ordered_stack);
}

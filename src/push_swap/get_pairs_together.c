/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:34:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/06 20:32:26 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	get_smaller_index(long *stack, long *ordered_stack, int excludes)
{
	int smaller_index;
	int it;

	smaller_index = 0;
	it = 0;
	while (stack[it] != VOID)
	{
		if (stack[it] == ordered_stack[excludes])
			smaller_index = it;
		it++;
	}
	return (smaller_index);
}

void	get_smallest_pair_together(long *stack, t_list **set_of_ins, t_nums *important_numbers)
{
	int smaller_index;
	int second_index;
	int excludes;
	long *ordered_stack;

	ordered_stack = order_stack(stack, get_stack_size(stack));
	excludes = 0;
	smaller_index = get_smaller_index(stack, ordered_stack, excludes);
	excludes++;
	second_index = get_smaller_index(stack, ordered_stack, excludes);
	while (smaller_index == (second_index + 1))
	{
		smaller_index = second_index;
		excludes++;
		second_index = get_smaller_index(stack, ordered_stack, excludes);
	}
	important_numbers->first = stack[smaller_index];
	important_numbers->second = stack[second_index];
	get_first_to_head(stack, important_numbers, 'b', set_of_ins);
	get_first_next_to_second(stack, 'b', important_numbers, set_of_ins);
}

static int	get_bigger_index(long *stack, long *ordered_stack, int last, int excludes)
{
	int bigger_index;
	int it;

	bigger_index = 0;
	it = 0;
	while (stack[it] != VOID)
	{
		if (stack[it] == ordered_stack[last - excludes])
			bigger_index = it;
		it++;
	}
	return (bigger_index);
}

void	get_biggest_pair_together(long *stack, t_list **set_of_ins, t_nums *important_numbers)
{
	int 	bigger_index;
	int 	second_index;
	int 	excludes;
	int		last;
	long 	*ordered_stack;

	ordered_stack = order_stack(stack, get_stack_size(stack));
	last = get_last(ordered_stack);
	excludes = 0;
	bigger_index = get_bigger_index(stack, ordered_stack, last, excludes);
	excludes++;
	second_index = get_bigger_index(stack, ordered_stack, last, excludes);
	while (bigger_index == (second_index + 1))
	{
		bigger_index = second_index;
		excludes++;
		second_index = get_bigger_index(stack, ordered_stack, last, excludes);
	}
	important_numbers->first = stack[bigger_index];
	important_numbers->second = stack[second_index];
	get_first_to_head(stack, important_numbers, 'a', set_of_ins);
	get_first_next_to_second(stack, 'a', important_numbers, set_of_ins);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:34:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/04 19:18:02 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	get_smaller_index(long *stack, long *ordered_stack, int last, int excludes)
{
	int smaller_index;
	int it;
	int save_excludes;

	smaller_index = 0;
	it = 0;
	last = get_last(ordered_stack);
	while (stack[++it] != VOID)
	{
		if (stack[it] < stack[smaller_index])
		{
			save_excludes = excludes;
			while (excludes > 0)
			{
				if (stack[it] != ordered_stack[excludes - 1])
					excludes--;
			}
			if (excludes == 0)
				smaller_index = it;
		}
	}
	return (smaller_index);
}

void	get_smallest_pair_together(long *stack, t_list *set_of_ins)
{
	int smaller_index;
	int second_index;
	int excludes;
	int last;
	long *ordered_stack;

	ordered_stack = order_stack(stack, get_stack_size(stack));
	last = get_last(ordered_stack);
	excludes = 0;
	smaller_index = get_smaller_index(stack, ordered_stack, last, excludes);
	excludes++;
	second_index = get_smaller_index(stack, ordered_stack, last, excludes);
	while (smaller_index == (second_index - 1))
	{
		smaller_index = second_index;
		excludes++;
		second_index = get_smaller_index(stack, ordered_stack, last, excludes);
	}
	smaller = stack[smaller_index];
	second = stack[second_index];
	get_second_to_head(stack, second, set_of_ins);
	get_first_next_to_second(stack, smaller);
}

int	get_bigger_index(long *stack, long *ordered_stack, int last, int excludes)
{
	int bigger_index;
	int it;
	int save_excludes;

	save_excludes = excludes;
	bigger_index = 0;
	it = 0;
	while (stack[++it] != VOID)
	{
		if (stack[it] > stack[bigger_index])
		{
			excludes = save_excludes;
			while (excludes > 0)
			{
				if (stack[it] == ordered_stack[last - excludes + 1])
					excludes--;
			}
			if (excludes == 0)
				bigger_index = it;
		}
	}
	return (bigger_index);
}

void	get_biggest_pair_together(long *stack, t_list *set_of_ins)
{
	int bigger_index;
	int second_index;
	int excludes;
	int last;
	long *ordered_stack;

	ordered_stack = order_stack(stack, get_stack_size(stack));
	last = get_last(ordered_stack);
	excludes = 0;
	smaller_index = get_bigger_index(stack, ordered_stack, last, excludes);
	excludes++;
	second_index = get_bigger_index(stack, ordered_stack, last, excludes);
	while (bigger_index == (second_index - 1))
	{
		bigger_index = second_index;
		excludes++;
		second_index = get_bigger_index(stack, ordered_stack, last, excludes);
	}
	bigger = stack[bigger_index];
	second = stack[second_index];
	get_second_to_head(stack, second, set_of_ins);
	get_first_next_to_second(stack, bigger);
}

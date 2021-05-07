/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_set_of_ins.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/02 16:32:39 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/07 16:51:14 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*get_set_of_instructions_a(long *stack)
{
	t_list	*set_of_ins;
	t_nums	*important_numbers;
	int		stack_size;
	long	*ordered_stack;

	set_of_ins = NULL;
	important_numbers = (t_nums*)malloc(sizeof(t_nums));
	stack_size = get_stack_size(stack);
	ordered_stack = order_stack(stack, stack_size);
	important_numbers->top = ordered_stack[stack_size - 1];
	while (is_ordered(stack) == false)
		get_biggest_pair_together(stack, &set_of_ins, important_numbers);
	return (set_of_ins);
}

t_list	*get_set_of_instructions_b(long *stack)
{
	t_list	*set_of_ins;
	t_nums	*important_numbers;
	int		stack_size;

	important_numbers = (t_nums*)malloc(sizeof(t_nums));
	stack_size = get_stack_size(stack);
	important_numbers->top = order_stack(stack, stack_size)[0];
	set_of_ins = NULL;
	while (is_rev_ordered(stack) == false)
		get_smallest_pair_together(stack, &set_of_ins, important_numbers);
	return (set_of_ins);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smaller_pair_together.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:34:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 21:33:19 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static void get_from_tail(long *stack, char stack_id, t_list **set_of_ins,
							int first)
{
	if (stack_id == 'a')
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("sa\n"));
		do_the_swap(stack);
		if (*(stack + 1) != first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rra\n"));
			do_the_revrot(stack);
		}
	}
	else
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
		do_the_swap(stack);
		if (*(stack + 1) != first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
			do_the_revrot(stack);
		}
	}
}

static void get_from_head(long *stack, char stack_id, t_list **set_of_ins,
							int first)
{
	if (stack_id == 'a')
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("rra\n"));
		do_the_revrot(stack);
		if (*(stack + 1) != first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("sa\n"));
			do_the_swap(stack);
		}
	}
	else
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
		do_the_revrot(stack);
		if (*(stack + 1) != first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
			do_the_swap(stack);
		}
	}
}

void	get_first_next_to_second(long *stack, char stack_id, int first,
									t_list **set_of_ins)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, first);
	dist_from_tail = get_dist_from_tail(stack, first);
	if (dist_from_head >= dist_from_tail)
	{
		while (*(stack + 1) != first)
			get_from_head(stack, stack_id, set_of_ins, first);
	}
	else 
	{
		while (*(stack + 1) != first)
			get_from_tail(stack, stack_id, set_of_ins, first);
	}
}

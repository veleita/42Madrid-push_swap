/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:25:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/06 13:42:42 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static void get_from_head(long *stack, char stack_id, t_list **set_of_ins)
{
	if (stack_id == 'a')
		ft_lstadd_back(set_of_ins, ft_lstnew("ra\n"));
	else
		ft_lstadd_back(set_of_ins, ft_lstnew("rb\n"));
	do_the_rot(stack);
}

static void get_from_tail(long *stack, char stack_id, t_list **set_of_ins)
{
	if (stack_id == 'a')
		ft_lstadd_back(set_of_ins, ft_lstnew("rra\n"));
	else
		ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
	do_the_revrot(stack);
}

void	get_first_to_head(long *stack, int first, char stack_id,
							t_list **set_of_ins)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, first);
	dist_from_tail = get_dist_from_tail(stack, first);
	if (dist_from_head <= dist_from_tail)
	{
		while (*stack != first)
			get_from_head(stack, stack_id, set_of_ins);
	}
	else
	{
		while (*stack != first)
			get_from_tail(stack, stack_id, set_of_ins);
	}
}

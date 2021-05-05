/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:25:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 19:42:38 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static void get_from_tail(long *stack, char stack_id, t_list **set_of_ins)
{
	if (stack_id == 'a')
		ft_lstadd_back(set_of_ins, ft_lstnew("ra\n"));
	else
		ft_lstadd_back(set_of_ins, ft_lstnew("rb\n"));
	do_the_rot(stack);
}

static void get_from_head(long *stack, char stack_id, t_list **set_of_ins)
{
	if (stack_id == 'a')
		ft_lstadd_back(set_of_ins, ft_lstnew("rra\n"));
	else
		ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
	do_the_revrot(stack);
}

void	get_second_to_head(long *stack, int second, char stack_id,
							t_list **set_of_ins)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, second);
	dist_from_tail = get_dist_from_tail(stack, second);
	if (dist_from_head >= dist_from_tail)
	{
		while (*stack != second)
			get_from_tail(stack, stack_id, set_of_ins);
	}
	else
	{
		while (*stack != second)
			get_from_head(stack, stack_id, set_of_ins);
	}
}

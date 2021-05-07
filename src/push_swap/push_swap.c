/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/07 16:56:49 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>
/*
static char	*safe_list_access(t_list *list)
{
	if (list)
		return (list->content);
	return (NULL);
}
*/
void		push_swap(t_stacks *stacks)
{
//	t_list	*set_of_ins_a;
//	t_list	*set_of_ins_b;
	int 	next;
	int		stack_size;
	long	*ordered_stack;
	int		dist_from_tail;
	int		dist_from_head;

	divide_chunks(stacks);
	while (is_empty(stacks->b, stacks->size) == false)
	{
		stack_size = get_stack_size(stacks->b);
		ordered_stack = order_stack(stacks->b, stack_size);
		next = ordered_stack[stack_size - 1];
		dist_from_head = get_dist_from_head(stacks->b, next);
		dist_from_tail = get_dist_from_tail(stacks->b, next);
		if (dist_from_head < dist_from_tail)
		{
			while (stacks->b[0] != next)
			{
				do_the_rot(stacks->b);
				ft_putstr("rb\n");
			}
		}
		else
		{
			while (stacks->b[0] != next)
			{
				do_the_revrot(stacks->b);
				ft_putstr("rrb\n");
			}
		}
		ft_putstr("pa\n");
		do_the_push(stacks->b, stacks->a, stacks->size);
	}
/*	set_of_ins_a = get_set_of_instructions_a(stacks->a);
	set_of_ins_b = get_set_of_instructions_b(stacks->b);
	while (set_of_ins_a || set_of_ins_b)
	{
		if (ft_lstsize(set_of_ins_a) > ft_lstsize(set_of_ins_b))
		{	
			if (print_instructions(set_of_ins_a->content,
						safe_list_access(set_of_ins_b)) == 2)
				set_of_ins_b = set_of_ins_b->next;
			set_of_ins_a = set_of_ins_a->next;
		}
		else
		{
			if (print_instructions(safe_list_access(set_of_ins_b),
						safe_list_access(set_of_ins_a)) == 2)
				set_of_ins_a = set_of_ins_a->next;
			set_of_ins_b = set_of_ins_b->next;
		}
	}
	push_to_a(stacks);*/
	return (ft_putstr("END\n"));
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_smaller_pair_together.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:34:21 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/06 19:58:39 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <instructions.h>

static void get_from_tail_a(long *stack, t_list **set_of_ins, t_nums *important_numbers)
{
	ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
	do_the_revrot(stack);
	if (*stack != important_numbers->second)
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
		do_the_swap(stack);
		while (*stack != important_numbers->biggest)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rb\n"));
			do_the_rot(stack);
			ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
			do_the_swap(stack);
		}
		while (*stack != important_numbers->first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
			do_the_revrot(stack);
		}
	}
}

static void get_from_tail_b(long *stack, t_list **set_of_ins, t_nums *important_numbers)
{
	ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
	do_the_revrot(stack);
	if (*stack != important_numbers->second)
	{
		ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
		do_the_swap(stack);
		while (*stack != important_numbers->biggest)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rb\n"));
			do_the_rot(stack);
			ft_lstadd_back(set_of_ins, ft_lstnew("sb\n"));
			do_the_swap(stack);
		}
		while (*stack != important_numbers->first)
		{
			ft_lstadd_back(set_of_ins, ft_lstnew("rrb\n"));
			do_the_revrot(stack);
		}
	}
}

static void get_from_tail(long *stack, char stack_id, t_list **set_of_ins,
							t_nums *important_numbers)
{
	if (stack_id == 'a')
		get_from_tail_a(stack, set_of_ins, important_numbers);
	else
		get_from_tail_b(stack, set_of_ins, important_numbers);
}

void	get_first_next_to_second(long *stack, char stack_id, t_nums *important_numbers,
									t_list **set_of_ins)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, important_numbers->second);
	dist_from_tail = get_dist_from_tail(stack, important_numbers->second);
	while (*stack != important_numbers->second)
		get_from_tail(stack, stack_id, set_of_ins, important_numbers->second);
}

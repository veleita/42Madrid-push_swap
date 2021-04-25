/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/25 13:44:42 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>

void		push_swap(t_stacks *stacks)
{
	char 	priority;
	int	chunk_size;
	int	 it = 2;

	chunk_size = divide_chunks(stacks);
	while ((is_ordered(stacks->a, stacks->size) == false ||
			is_empty(stacks->b, stacks->size) == false) && it > 0)
	{
		priority = set_priority(stacks);
		ask_push(stacks, priority);
		ask_swap(stacks, priority);
		ask_rev_rotate(stacks, priority, chunk_size);
		ask_swap(stacks, priority);
		ask_rotate(stacks, priority);
		it--;
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

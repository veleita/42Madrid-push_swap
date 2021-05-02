/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_in_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 16:39:45 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/02 16:20:35 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	perform_instruction(long *stack, void (do_the_ins)(long*),
									char *instruction)
{
	do_the_ins(stack);
	ft_putstr(instruction);
}

static void	swap_or_double_swap(t_stacks *stacks, char priority,
								void (main_ins)(long*),
								void (second_ins)(long*))
{
	if (priority == 'a')
	{
		main_ins(stacks->a);
		if (second_ins == main_ins)
			perform_instruction(second_ins, "ss\n");
	}
}

void		get_first_next_to_second(long *stacks, char priority,
									int first, t_list *instructions)
{
	int	dist_from_head;
	int	dist_from_tail;

	dist_from_head = get_dist_from_head(stack, first);
	dist_from_tail = get_dist_from_tail(stack, first);
	if (dist_from_head >= dist_from_tail)
	{
		while (*(stack + 1) != first)
		{
			ft_lstadd_back(&instructions, &do_the_swap());
			ft_lstadd_back(&instructions, &do_the_revrot());
		}
	}
	else if (*(stack + 1) != first)
		{
			do_the_revrot(stack);
			do_the_swap(stack);
		}
	}
}

int	get_dist_from_head(long *stack, int aim)
{
	int	dist;

	dist = 0;
	while (stack[dist] != aim)
		dist++;
	return (dist);
}

int	get_dist_from_tail(long *stack, int aim)
{
	int	dist;
	int	last;

	dist = 0;
	last = get_last(stack);
	while (stack[last - dist] != aim)
		dist++;
	return (dist);
}

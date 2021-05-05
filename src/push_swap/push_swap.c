/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/19 23:03:59 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/05 20:01:32 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>
#include <common.h>
#include <instructions.h>
#include <args_cooker.h>

void		push_swap(t_stacks *stacks)
{
	t_list	*set_of_ins_a;
	t_list	*set_of_ins_b;

	divide_chunks(stacks);
	set_of_ins_a = get_set_of_instructions_a(stacks->a);
	set_of_ins_b = get_set_of_instructions_b(stacks->b);
	while (set_of_ins_a || set_of_ins_b)
	{
		if (set_priority(stacks) == 'a')
		{
			
			if (print_instructions(set_of_ins_a->content,
						tern_hack_str((set_of_ins_b),
							set_of_ins_b->content, NULL)) == 2)
				set_of_ins_b = set_of_ins_b->next;
			set_of_ins_a = set_of_ins_a->next;
		}
		else
		{
			if (print_instructions(set_of_ins_b->content,
						tern_hack_str((set_of_ins_a),
							set_of_ins_a->content, NULL)) == 2)
				set_of_ins_a = set_of_ins_a->next;
			set_of_ins_b = set_of_ins_b->next;
		}
	}
	push_to_a(stacks);
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

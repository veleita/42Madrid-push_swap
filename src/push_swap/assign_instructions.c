/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 16:25:34 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/04 16:28:22 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_ins	*assign_rot_a()
{
	t_ins	*instruction;

	instruction = (t_ins*)malloc(sizeof(t_ins));
	instruction->instruction = &do_the_rot();
	instruction->simple_ins = "ra\n";
	instruction->double_ins = "rr\n";
	return (instruction);
}

t_ins	*assign_revrot_a()
{
	t_ins	*instruction;

	instruction = (t_ins*)malloc(sizeof(t_ins));
	instruction->instruction = &do_the_revrot();
	instruction->simple_ins = "rra\n";
	instruction->double_ins = "rrr\n";
	return (instruction);
}

t_ins	*assign_revrot_b()
{
	t_ins	*instruction;

	instruction = (t_ins*)malloc(sizeof(t_ins));
	instruction->instruction = &do_the_revrot();
	instruction->simple_ins = "rrb\n";
	instruction->double_ins = "rrr\n";
	return (instruction);
}

t_ins	*assign_revrot_b()
{
	t_ins	*instruction;

	instruction = (t_ins*)malloc(sizeof(t_ins));
	instruction->instruction = &do_the_revrot();
	instruction->simple_ins = "rrb\n";
	instruction->double_ins = "rrr\n";
	return (instruction);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:31:10 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 20:41:43 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <instructions.h>
#include <common.h>
#include <libft.h>

void	swap_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a')
		do_the_swap(stacks->a);
	else if (*(instruction + 1) == 'b')
		do_the_swap(stacks->b);
	else if (*(instruction + 1) == 's')
	{
		do_the_swap(stacks->a);
		do_the_swap(stacks->b);
	}
	else
		free_and_error(stacks);
}

void	push_ins(char *instruction, t_stacks *stacks, int size)
{
	if (*(instruction + 1) == 'a')
		do_the_push(stacks->b, stacks->a, size);
	else if (*(instruction + 1) == 'b')
		do_the_push(stacks->a, stacks->b, size);
	else
		free_and_error(stacks);
}

void	revrotate_ins(char *instruction, t_stacks *stacks, int size)
{
	if (*(instruction + 2) == '\0')
	{
		do_the_rot(stacks->a, size);
		do_the_rot(stacks->b, size);
	}
	else if (*(instruction + 2) == 'a')
		do_the_revrot(stacks->a, size);
	else if (*(instruction + 2) == 'b')
		do_the_revrot(stacks->b, size);
	else if (*(instruction + 2) == 'r')
	{
		do_the_revrot(stacks->a, size);
		do_the_revrot(stacks->b, size);
	}
		else
			free_and_error(stacks);
}

void	rotate_ins(char *instruction, t_stacks *stacks, int size)
{
	if (*(instruction + 1) == 'a')
		do_the_rot(stacks->a, size);
	else if (*(instruction + 1) == 'b')
		do_the_rot(stacks->b, size);
	else if (*(instruction + 1) == 'r')
		revrotate_ins(instruction, stacks, size);
	else
		free_and_error(stacks);
}

int	process_instruction(char *instruction, t_stacks *stacks, int args)
{
	char *trimmed_ins;

	trimmed_ins = trim_spaces(instruction);
	if (ft_strlen(trimmed_ins) > 2)
		free_and_error(stacks);
	if (*instruction == 's')
		swap_ins(trimmed_ins, stacks);
	if (*instruction == 'p')
		push_ins(trimmed_ins, stacks, args);
	if (*instruction == 'r')
		rotate_ins(trimmed_ins, stacks, args);
	else
		free_and_error(stacks);
	return (1);
}

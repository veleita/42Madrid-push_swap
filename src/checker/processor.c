/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:31:10 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 23:36:29 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <instructions.h>
#include <common.h>
#include <libft.h>

void	revrotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 2) == '\0')
	{
		do_the_rot(stacks->a);
		do_the_rot(stacks->b);
	}
	else if (*(instruction + 2) == 'a' && *(instruction + 3) == '\0')
		do_the_revrot(stacks->a);
	else if (*(instruction + 2) == 'b' && *(instruction + 3) == '\0')
		do_the_revrot(stacks->b);
	else if (*(instruction + 2) == 'r' && *(instruction + 3) == '\0')
	{
		do_the_revrot((long*)stacks->a);
		do_the_revrot(stacks->b);
	}
		else
			free_and_error(stacks);
}

void	rotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a' && *(instruction + 2) == '\0')
		do_the_rot(stacks->a);
	else if (*(instruction + 1) == 'b' && *(instruction + 2) == '\0')
		do_the_rot(stacks->b);
	else if (*(instruction + 1) == 'r')
		revrotate_ins(instruction, stacks);
	else
		free_and_error(stacks);
}

void	push_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a')
		do_the_push(stacks->b, (long*)stacks->a, stacks->size);
	else if (*(instruction + 1) == 'b')
		do_the_push((long*)stacks->a, stacks->b, stacks->size);
	else
		free_and_error(stacks);
}

void	swap_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a')
		do_the_swap((long*)stacks->a);
	else if (*(instruction + 1) == 'b')
		do_the_swap(stacks->b);
	else if (*(instruction + 1) == 's')
	{
		do_the_swap((long*)stacks->a);
		do_the_swap(stacks->b);
	}
	else
		free_and_error(stacks);
}

int	process_instruction(char *instruction, t_stacks *stacks)
{
	char *trimmed_ins;

	trimmed_ins = trim_spaces(instruction);
	if (ft_strlen(trimmed_ins) > 3)
		free_and_error(stacks);
	if (*instruction == 's')
		swap_ins(trimmed_ins, stacks);
	else if (*instruction == 'p')
		push_ins(trimmed_ins, stacks);
	else if (*instruction == 'r')
		rotate_ins(trimmed_ins, stacks);
	else
		free_and_error(stacks);
	return (1);
}

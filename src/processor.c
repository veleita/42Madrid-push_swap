/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:31:10 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/12 18:50:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_swap(int *stack)
{
	int save;

	save = stack[0];
	stack[0] = stack[1];
	stack[1] = save;
}

void	swap_ins(char *instruction, t_stacks *stacks)
{
	if (ft_strlen(instruction) > 2)
		free_and_error(stacks);
	if (*(instruction + 1) == 'a')
		do_the_swap(stacks->a);
	else if (*(instruction + 1) == 'b')
		do_the_swap(stacks->b);
	else
		free_and_error(stacks);
}

void	do_the_push(int *src, int *dst, int size)
{
	int save;
	int prev;
	int index;

	while (index < size)
	{
		if (index == 0)
		{
			prev = dst[0];
			dst[0] = src[0];
			src[0] = src[1];
		}
		else
		{
			save = dst[index];
			dst[index] = prev;
			prev = save;
			src[index] = src[index + 1];
		}
		index++;
	}
}

void	push_ins(char *instruction, t_stacks *stacks)
{
	if (ft_strlen(instruction) > 2)
		free_and_error(stacks);
	if (*(instruction + 1) == 'a')
		do_the_push(stacks->b, stacks->a);
	else if (*(instruction + 1) == 'b')
		do_the_swap(stacks->a, stacks->b);
	else
		free_and_error(stacks);
}

int	process_instruction(char *instruction, t_stacks *stacks)
{
	trim_spaces(instruction);
	if (*instruction == 's')
		swap_ins(instruction, stacks);
	if (*instruction == 'p')
		push_ins(instruction, stacks);
	if (*instruction == 'r')
		rotate_ins(instruction, stacks);
	else
		free_and_error(stacks);
	return (1);
}

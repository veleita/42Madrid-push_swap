/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:58:57 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 16:07:54 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_revrot(long *stack, int size)
{
	int index;
	long last;

	index = 0;
	while (stack[index] != VOID && index < size - 1)
		index++;
	if (index == 0)
		return ;
	last = stack[index];
	stack[0] = last;
	index = 0;
	while (stack[index++] != last)
		stack[index] = stack[index - 1];
}

void	revrotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 2) == '\0')
	{
		do_the_rot((long*)stacks->a, stacks->size);
		do_the_rot(stacks->b, stacks->size);
	}
	else if (*(instruction + 2) == 'a')
		do_the_revrot((long*)stacks->a, stacks->size);
	else if (*(instruction + 2) == 'b')
		do_the_revrot(stacks->b, stacks->size);
	else if (*(instruction + 2) == 'r')
	{
		do_the_revrot((long*)stacks->a, stacks->size);
		do_the_revrot(stacks->b, stacks->size);
	}
		else
			free_and_error(stacks);
}

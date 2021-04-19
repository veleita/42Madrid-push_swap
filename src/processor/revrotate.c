/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:58:57 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 13:15:27 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_revrot(long *stack)
{
	int index;
	long last;

	if (*stack == VOID)
		return ;
	last = get_last(stack);
	stack[0] = last;
	index = 0;
	while (stack[index++] != last)
		stack[index] = stack[index - 1];
}

void	revrotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 2) == '\0')
	{
		do_the_rot((long*)stacks->a);
		do_the_rot(stacks->b);
	}
	else if (*(instruction + 2) == 'a')
		do_the_revrot((long*)stacks->a);
	else if (*(instruction + 2) == 'b')
		do_the_revrot(stacks->b);
	else if (*(instruction + 2) == 'r')
	{
		do_the_revrot((long*)stacks->a);
		do_the_revrot(stacks->b);
	}
		else
			free_and_error(stacks);
}

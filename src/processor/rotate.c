/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:57:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 13:10:21 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_rot(long *stack)
{
	int 	save;
	int		index;
	int		last;

	if (*stack == VOID)
		return ;
	last = get_last(stack);
	save = stack[0];
	while (stack[index] != stack[last])
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[last] = save;
}

void	rotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a')
		do_the_rot(stacks->a);
	else if (*(instruction + 1) == 'b')
		do_the_rot(stacks->b);
	else if (*(instruction + 1) == 'r')
		revrotate_ins(instruction, stacks);
	else
		free_and_error(stacks);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:57:05 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 18:55:16 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_rot(long *stack, int size)
{
	int 	save;
	int		index;
	int		last;

	last = get_last(long *stack);
	save = stack[0];
	while (index < size - 1)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[size - 1] = save;
}

void	rotate_ins(char *instruction, t_stacks *stacks)
{
	if (*(instruction + 1) == 'a')
		do_the_rot(stacks->a, stacks->size);
	else if (*(instruction + 1) == 'b')
		do_the_rot(stacks->b, stacks->size);
	else if (*(instruction + 1) == 'r')
		revrotate_ins(instruction, stacks);
	else
		free_and_error(stacks);
}

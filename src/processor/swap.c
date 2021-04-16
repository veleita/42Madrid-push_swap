/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:40:45 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 16:09:09 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_swap(long *stack)
{
	int save;

	if (stack[1] == VOID)
		return ;
	save = stack[0];
	stack[0] = stack[1];
	stack[1] = save;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:52:56 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/16 16:23:43 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <processor.h>
#include <common.h>

void	do_the_push(long *src, long *dst, int size)
{
	long save;
	long prev;
	int index;

	if (src[0] == VOID)
		return ;
	else if (dst[0] == VOID)
		dst[0] = src[0];
	else
	{
		index = 0;
		while (index < size - 1)
		{
			if (index == 0)
			{
				prev = dst[0];
				dst[0] = src[0];
				src[0] = src[1];
			}
			else
			{
				if (prev != VOID)
				{
					save = dst[index];
					dst[index] = prev;
					prev = save;
				}
				if (src[index + 1] != VOID)
					src[index] = src[index + 1];
			}
			index++;
		}
	}
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

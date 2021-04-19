/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:52:56 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/19 23:20:47 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <common.h>

static void	push_to_void(long *src, long *dst, int size)
{
	int index;
	
	dst[0] = src[0];
	index = 0;
	while (index < size)
	{
		src[index] = src[index + 1];
		index++;
	}
}

static void	rotate_stack(long *prev, long *save, int index, long *dst, long*src)
{
	if (*prev != VOID)
	{
		*save = dst[index];
		dst[index] = *prev;
		*prev = *save;
	}
	src[index] = src[index + 1];
}

void		do_the_push(long *src, long *dst, int size)
{
	long save;
	long prev;
	int index;

	if (src[0] == VOID)
		return ;
	else if (dst[0] == VOID)
		push_to_void(src, dst, size);
	else
	{
		index = 0;
		while (index < size)
		{
			if (index == 0)
			{
				prev = dst[0];
				dst[0] = src[0];
				src[0] = src[1];
			}
			else
				rotate_stack(&prev, &save, index, src, dst);
			index++;
		}
	}
}

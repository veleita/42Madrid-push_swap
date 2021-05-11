/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 15:52:56 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/05/11 16:20:16 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <common.h>

static void	push_to_void(long *src, long *dst, int size)
{
	int	index;

	dst[0] = src[0];
	index = 0;
	while (index < size)
	{
		src[index] = src[index + 1];
		index++;
	}
}

static void	rotate_stack(long *prev, long *save, int index, long *dst)
{
	if (*prev != VOID)
	{
		*save = dst[index];
		dst[index] = *prev;
		*prev = *save;
	}
}

void	do_the_push(long *src, long *dst, int size)
{
	long	save;
	long	prev;
	int		index;

	if (src[0] != VOID && dst[0] == VOID)
		push_to_void(src, dst, size);
	else if (dst[0] != VOID)
	{
		index = -1;
		while (++index < size)
		{
			if (index == 0)
			{
				prev = dst[0];
				dst[0] = src[0];
				src[0] = src[1];
			}
			else
			{
				rotate_stack(&prev, &save, index, dst);
				src[index] = src[index + 1];
			}
		}
	}
	return ;
}

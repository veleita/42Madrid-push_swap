/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzomeno- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/15 20:19:13 by mzomeno-          #+#    #+#             */
/*   Updated: 2021/04/15 20:43:50 by mzomeno-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <instructions.h>
#include <common.h>

void	do_the_swap(int *stack)
{
	int save;

	save = stack[0];
	stack[0] = stack[1];
	stack[1] = save;
}

void	do_the_push(int *src, int *dst, int size)
{
	int save;
	int prev;
	int index;

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
		{
			save = dst[index];
			dst[index] = prev;
			prev = save;
			src[index] = src[index + 1];
		}
		index++;
	}
}

void	do_the_revrot(int *stack, int size)
{
	int index;

	stack[0] = stack[size - 1];
	index = 0;
	while (index++ < size)
		stack[index] = stack[index - 1];
}

void	do_the_rot(int *stack, int size)
{
	int save;
	int index;

	index = 0;
	save = stack[0];
	while (index < size - 1)
	{
		stack[index] = stack[index + 1];
		index++;
	}
	stack[size - 1] = save;
}
